// Copyright Epic Games, Inc. All Rights Reserved.

#include "FYPPlayerController.h"
#include "GameFramework/Pawn.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"
#include "FYPCharacter.h"
#include "Engine/World.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "NavigationPath.h"
#include "NavMesh/RecastNavMesh.h"
#include "Runtime/NavigationSystem/Public/NavigationSystem.h"

AFYPPlayerController::AFYPPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	CachedDestination = FVector::ZeroVector;
	FollowTime = 0.f;
}

void AFYPPlayerController::FindPath(ARecastNavMesh* Nav)
{
	UNavigationSystemV1* NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
	APawn* ControlledPawn = GetPawn();
	UNavigationPath* path = NavSys->FindPathToLocationSynchronously(this, ControlledPawn->GetActorLocation(), CachedDestination, ControlledPawn);

	TArray<FVector> MoveToLocations;

	if (path && path->IsValid())
	{
		TArray<FNavPathPoint> pathpoints = path->GetPath()->GetPathPoints();

		for (int i = 1; i < pathpoints.Num(); i++)
		{
			NavNodeRef nodeRef = pathpoints[i].NodeRef;
			TArray<FVector> CurrentPolygonVertices;
			Nav->GetPolyVerts(nodeRef, CurrentPolygonVertices);
			float ClosestDistance = BIG_NUMBER;
			int ClosestIndex = 0;
			for (int j = 1; j < CurrentPolygonVertices.Num(); j++)
			{
				float calcDistance = FVector::DistSquared(ControlledPawn->GetActorLocation(), CurrentPolygonVertices[j]);
				if (calcDistance < ClosestDistance)
				{
					ClosestIndex = j;
					ClosestDistance = calcDistance;
				}
			}

			//pathpoints[i].Location = CurrentPolygonVertices[ClosestIndex];
			MoveToLocations.Add(CurrentPolygonVertices[ClosestIndex]);
		}
	}

	FollowPath(MoveToLocations);

	DrawPath();

	UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, FXCursor, CachedDestination, FRotator::ZeroRotator, FVector(1.f, 1.f, 1.f), true, true, ENCPoolMethod::None, true);
}

void AFYPPlayerController::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}
}

void AFYPPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		// Setup mouse input events
		EnhancedInputComponent->BindAction(SetDestinationClickAction, ETriggerEvent::Started, this, &AFYPPlayerController::OnInputStarted);
		EnhancedInputComponent->BindAction(SetDestinationClickAction, ETriggerEvent::Triggered, this, &AFYPPlayerController::OnSetDestinationTriggered);
		EnhancedInputComponent->BindAction(SetDestinationClickAction, ETriggerEvent::Completed, this, &AFYPPlayerController::OnSetDestinationReleased);
		EnhancedInputComponent->BindAction(SetDestinationClickAction, ETriggerEvent::Canceled, this, &AFYPPlayerController::OnSetDestinationReleased);

		// Setup touch input events
		EnhancedInputComponent->BindAction(SetDestinationTouchAction, ETriggerEvent::Started, this, &AFYPPlayerController::OnInputStarted);
		EnhancedInputComponent->BindAction(SetDestinationTouchAction, ETriggerEvent::Triggered, this, &AFYPPlayerController::OnTouchTriggered);
		EnhancedInputComponent->BindAction(SetDestinationTouchAction, ETriggerEvent::Completed, this, &AFYPPlayerController::OnTouchReleased);
		EnhancedInputComponent->BindAction(SetDestinationTouchAction, ETriggerEvent::Canceled, this, &AFYPPlayerController::OnTouchReleased);
	}
}

void AFYPPlayerController::OnInputStarted()
{
	StopMovement();
}

// Triggered every frame when the input is held down
void AFYPPlayerController::OnSetDestinationTriggered()
{
	// We flag that the input is being pressed
	FollowTime += GetWorld()->GetDeltaSeconds();
	
	// We look for the location in the world where the player has pressed the input
	FHitResult Hit;
	bool bHitSuccessful = false;
	if (bIsTouch)
	{
		bHitSuccessful = GetHitResultUnderFinger(ETouchIndex::Touch1, ECollisionChannel::ECC_Visibility, true, Hit);
	}
	else
	{
		bHitSuccessful = GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, true, Hit);
	}

	// If we hit a surface, cache the location
	if (bHitSuccessful)
	{
		CachedDestination = Hit.Location;
	}
	
	// Move towards mouse pointer or touch
	APawn* ControlledPawn = GetPawn();
	if (ControlledPawn != nullptr)
	{
		FVector WorldDirection = (CachedDestination - ControlledPawn->GetActorLocation()).GetSafeNormal();
		ControlledPawn->AddMovementInput(WorldDirection, 1.0, false);
	}
}

void AFYPPlayerController::OnSetDestinationReleased()
{
	// If it was a short press
	if (FollowTime <= ShortPressThreshold)
	{
		// We move there and spawn some particles
		//UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, CachedDestination);

		FindNavData();
	}

	FollowTime = 0.f;
}

// Triggered every frame when the input is held down
void AFYPPlayerController::OnTouchTriggered()
{
	bIsTouch = true;
	OnSetDestinationTriggered();
}

void AFYPPlayerController::OnTouchReleased()
{
	bIsTouch = false;
	OnSetDestinationReleased();
}

FVector AFYPPlayerController::GetGoalDestination()
{
	return CachedDestination;
}
