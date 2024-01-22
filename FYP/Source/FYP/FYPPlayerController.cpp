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

	if (path && path->IsValid())
	{
		TArray<FNavPathPoint> pathpoints = path->GetPath()->GetPathPoints();

		for (int i = 0; i < pathpoints.Num(); i++)
		{
			NavNodeRef nodeRef = pathpoints[i].NodeRef;
			TArray<FVector> CurrentPolygonVertices;
			Nav->GetPolyVerts(nodeRef, CurrentPolygonVertices);

			//DRAW POLYGONS 
			for (int j = 1; j < CurrentPolygonVertices.Num(); j++)
			{
				// POLYGON IS NAV LINK
				if (CurrentPolygonVertices.Num() == 2)
				{				
					if (i == 0)
					{
						//AGENT ALREADY ON POLYGON TO JUMP
					}
					else
					{
						
					}
				}
				else
				{
					DrawDebugLine(GetWorld(), CurrentPolygonVertices[j], CurrentPolygonVertices[j - 1], FColor(255, 0, 0), true, 0, 2.f);
				}
			}
			DrawDebugLine(GetWorld(), CurrentPolygonVertices[0], CurrentPolygonVertices[CurrentPolygonVertices.Num() - 1], FColor(255, 0, 0), true, 0, 2.f);

			if (CurrentPolygonVertices.Num() == 2)
			{
				//Draw green line for nav link
				DrawDebugLine(GetWorld(), CurrentPolygonVertices[0], CurrentPolygonVertices[1], FColor(0, 255, 0), true, 0, 5.f);
			}
		}
	}



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

int AFYPPlayerController::stringPull(const float* portals, int nportals, float* pts, const int maxPts)
{
	// Find straight path.
	int npts = 0;
	// Init scan state
	float portalApex[2], portalLeft[2], portalRight[2];
	int apexIndex = 0, leftIndex = 0, rightIndex = 0;
	vcpy(portalApex, &portals[0]);
	vcpy(portalLeft, &portals[0]);
	vcpy(portalRight, &portals[2]);

	// Add start point.
	vcpy(&pts[npts * 2], portalApex);
	npts++;

	for (int i = 1; i < nportals && npts < maxPts; ++i)
	{
		const float* left = &portals[i * 4 + 0];
		const float* right = &portals[i * 4 + 2];

		// Update right vertex.
		if (triarea2(portalApex, portalRight, right) <= 0.0f)
		{
			if (vequal(portalApex, portalRight) || triarea2(portalApex, portalLeft, right) > 0.0f)
			{
				// Tighten the funnel.
				vcpy(portalRight, right);
				rightIndex = i;
			}
			else
			{
				// Right over left, insert left to path and restart scan from portal left point.
				vcpy(&pts[npts * 2], portalLeft);
				npts++;
				// Make current left the new apex.
				vcpy(portalApex, portalLeft);
				apexIndex = leftIndex;
				// Reset portal
				vcpy(portalLeft, portalApex);
				vcpy(portalRight, portalApex);
				leftIndex = apexIndex;
				rightIndex = apexIndex;
				// Restart scan
				i = apexIndex;
				continue;
			}
		}

		// Update left vertex.
		if (triarea2(portalApex, portalLeft, left) >= 0.0f)
		{
			if (vequal(portalApex, portalLeft) || triarea2(portalApex, portalRight, left) < 0.0f)
			{
				// Tighten the funnel.
				vcpy(portalLeft, left);
				leftIndex = i;
			}
			else
			{
				// Left over right, insert right to path and restart scan from portal right point.
				vcpy(&pts[npts * 2], portalRight);
				npts++;
				// Make current right the new apex.
				vcpy(portalApex, portalRight);
				apexIndex = rightIndex;
				// Reset portal
				vcpy(portalLeft, portalApex);
				vcpy(portalRight, portalApex);
				leftIndex = apexIndex;
				rightIndex = apexIndex;
				// Restart scan
				i = apexIndex;
				continue;
			}
		}
	}
	// Append last point to path.
	if (npts < maxPts)
	{
		vcpy(&pts[npts * 2], &portals[(nportals - 1) * 4 + 0]);
		npts++;
	}

	return npts;
}
