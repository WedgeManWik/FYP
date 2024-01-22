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

	TArray<FCustomPathPoint> FinalPath;

	TArray<FJumpPoint> FinalJumppPointPath;

	if (path && path->IsValid())
	{
		TArray<FNavPathPoint> pathpoints = path->GetPath()->GetPathPoints();

		for (int i = 0; i < pathpoints.Num(); i++)
		{
			NavNodeRef nodeRef = pathpoints[i].NodeRef;
			TArray<FVector> CurrentPolygonVertices;
			Nav->GetPolyVerts(nodeRef, CurrentPolygonVertices);

			TArray<FNavigationPortalEdge> CurrentPolygonEdges;
			Nav->GetPolyEdges(nodeRef, CurrentPolygonEdges);

			bool IsJump = false;

			// POLYGON IS NAV LINK
			if (CurrentPolygonVertices.Num() == 2)
			{
				IsJump = true;
				//DRAW NAV LINK
				DrawDebugLine(GetWorld(), CurrentPolygonVertices[0], CurrentPolygonVertices[1], FColor(0, 255, 0), true, 0, 5.f);

				//PREVIOUS POLYGON
				NavNodeRef prevNodeRef = pathpoints[i - 1].NodeRef;
				TArray<FVector> PrevPolygonVertices;
				Nav->GetPolyVerts(prevNodeRef, PrevPolygonVertices);

				if (i == 1)
				{
					//AGENT ALREADY ON POLYGON

					FVector Point = ControlledPawn->GetActorLocation();
					if (pathpoints[i + 1].Location.Z <= pathpoints[i].Location.Z + 5.f)
					{
						//Dropping down so have to go to edge
						FVector Closest = FMath::ClosestPointOnSegment(pathpoints[i], PrevPolygonVertices[0], PrevPolygonVertices[PrevPolygonVertices.Num() - 1]);
						for (int j = 0; j < PrevPolygonVertices.Num() - 1; j++)
						{
							//DRAW PREVIOUS POLYGON
							DrawDebugLine(GetWorld(), PrevPolygonVertices[j], PrevPolygonVertices[j + 1], FColor(255, 0, 0), true, 0, 5.f);

							FVector ClosestPoint = FMath::ClosestPointOnSegment(pathpoints[i], PrevPolygonVertices[j], PrevPolygonVertices[j + 1]);
							DrawDebugSphere(GetWorld(), ClosestPoint, 5.f, 5, FColor(255, 0, 255), true, 0, 5.f);
							if (FVector::DistSquared(pathpoints[i], ClosestPoint) < FVector::DistSquared(pathpoints[i], Closest))
							{
								Closest = ClosestPoint;
							}
						}

						Point = Closest;
					}

					pathpoints[i].Location = Point;
					DrawDebugSphere(GetWorld(), pathpoints[i].Location, 5.f, 5, FColor(0, 0, 255), true, 0, 5.f);

					FJumpPoint newJumpPoint;
					newJumpPoint.Left = pathpoints[i].Location;
					newJumpPoint.Right = pathpoints[i + 1].Location;
					FinalJumppPointPath.Add(newJumpPoint);
				}
				else
				{
					//STRING PULL
					DrawDebugLine(GetWorld(), PrevPolygonVertices[0], PrevPolygonVertices[PrevPolygonVertices.Num() - 1], FColor(255, 0, 255), true, 0, 5.f);

					FVector Point = pathpoints[i + 1].Location.Z > pathpoints[i].Location.Z ? pathpoints[i - 1] : pathpoints[i];
					FVector Closest = FMath::ClosestPointOnSegment(Point, PrevPolygonVertices[0], PrevPolygonVertices[PrevPolygonVertices.Num() - 1]);
					for (int j = 0; j < PrevPolygonVertices.Num() - 1; j++)
					{
						//DRAW PREVIOUS POLYGON
						DrawDebugLine(GetWorld(), PrevPolygonVertices[j], PrevPolygonVertices[j + 1], FColor(255, 0, 0), true, 0, 5.f);

						FVector ClosestPoint = FMath::ClosestPointOnSegment(Point, PrevPolygonVertices[j], PrevPolygonVertices[j + 1]);
						DrawDebugSphere(GetWorld(), ClosestPoint, 5.f, 5, FColor(255, 0, 255), true, 0, 5.f);
						if (FVector::DistSquared(Point, ClosestPoint) < FVector::DistSquared(Point, Closest))
						{
							Closest = ClosestPoint;
						}
					}
					pathpoints[i].Location = Closest;

					DrawDebugSphere(GetWorld(), Closest, 5.f, 5, FColor(0, 0, 255), true, 0, 5.f);

					FJumpPoint newJumpPoint;
					newJumpPoint.Left = Closest;
					newJumpPoint.Right = pathpoints[i + 1].Location;
					FinalJumppPointPath.Add(newJumpPoint);
				}
			}
			else
			{
				//DRAW POLYGON
				for (int j = 0; j < CurrentPolygonEdges.Num(); j++)
				{
					DrawDebugLine(GetWorld(), CurrentPolygonEdges[j].Left, CurrentPolygonEdges[j].Right, FColor(255, 0, 0), true, 0, 5.f);
				}
				DrawDebugLine(GetWorld(), CurrentPolygonVertices[0], CurrentPolygonVertices[CurrentPolygonVertices.Num() - 1], FColor(255, 0, 0), true, 0, 5.f);
			}
			//FCustomPathPoint pathPointToAdd = FCustomPathPoint();
			//pathPointToAdd.Location = path->GetPath()->GetPathPointLocation(i).Position;
			//pathPointToAdd.IsJumpPoint = IsJump;
			//FinalPath.Add(pathPointToAdd);
		}
	}

	CustomPath = FinalPath;

	JumpPoints = FinalJumppPointPath;

	FollowCustomPath();

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

void AFYPPlayerController::FollowCustomPath()
{
	CurrentPathIndex = 0;
	GoToNextPointOnCustomPath();
}

void AFYPPlayerController::GoToNextPointOnCustomPath()
{
	if (JumpPoints.Num() == 0 || CurrentPathIndex >= JumpPoints.Num())
	{
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, CachedDestination);
		return;
	}

	UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, JumpPoints[CurrentPathIndex].Left);
	CustomGoingToNextPoint(JumpPoints[CurrentPathIndex]);
	CurrentPathIndex++;
	//if (CurrentPathIndex >= CustomPath.Num())
	//{
	//	return;
	//}

	//if (CustomPath[CurrentPathIndex].IsJumpPoint)
	//{
	//	FVector Upper = CustomPath[CurrentPathIndex].Location.Z > CustomPath[CurrentPathIndex + 1].Location.Z ? CustomPath[CurrentPathIndex].Location : CustomPath[CurrentPathIndex + 1].Location;
	//	FVector Lower = CustomPath[CurrentPathIndex].Location.Z < CustomPath[CurrentPathIndex + 1].Location.Z ? CustomPath[CurrentPathIndex].Location : CustomPath[CurrentPathIndex + 1].Location;
	//	CustomJump(Lower, Upper);
	//}
	//else
	//{
	//	UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, CustomPath[CurrentPathIndex].Location);
	//	CustomGoingToNextPoint(CustomPath[CurrentPathIndex].Location);
	//}

	//CurrentPathIndex++;
}

