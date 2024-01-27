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
#include "Kismet/KismetMathLibrary.h"
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

void AFYPPlayerController::FindPathPortals(ARecastNavMesh* Nav)
{
	UNavigationSystemV1* NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
	APawn* ControlledPawn = GetPawn();
	UNavigationPath* path = NavSys->FindPathToLocationSynchronously(this, ControlledPawn->GetActorLocation(), CachedDestination, ControlledPawn);

	TArray<FMyPolyEdge> Portals;

	if (path && path->IsValid())
	{
		TArray<FNavPathPoint> pathpoints = path->GetPath()->GetPathPoints();

		if (pathpoints.Num() <= 2)
		{
			return;
		}

		//DRAW FIRST POLYGON
		if (!PathfindingAuto)
		{
			NavNodeRef nodeRef = pathpoints[0].NodeRef;
			TArray<FVector> CurrentPolygonVertices;
			Nav->GetPolyVerts(nodeRef, CurrentPolygonVertices);
			for (int j = 1; j < CurrentPolygonVertices.Num(); j++)
			{
				DrawDebugLine(GetWorld(), CurrentPolygonVertices[j], CurrentPolygonVertices[j - 1], FColor(0, 255, 0), true, 0, 5.f);
			}
			DrawDebugLine(GetWorld(), CurrentPolygonVertices[0], CurrentPolygonVertices[CurrentPolygonVertices.Num() - 1], FColor(0, 255, 0), true, 0, 5.f);

			DrawDebugSphere(GetWorld(), pathpoints[0], 5.f, 5, FColor(255, 0, 255), true, 0, 5.f);
		}

		for (int i = 1; i < pathpoints.Num(); i++)
		{
			NavNodeRef nodeRef = pathpoints[i].NodeRef;
			TArray<FVector> CurrentPolygonVertices;
			Nav->GetPolyVerts(nodeRef, CurrentPolygonVertices);

			//if (!PathfindingAuto)
			//{
			//	for (int j = 1; j < CurrentPolygonVertices.Num(); j++)
			//	{
			//		DrawDebugLine(GetWorld(), CurrentPolygonVertices[j], CurrentPolygonVertices[j - 1], FColor(0, 255, 0), true, 0, 5.f);
			//	}
			//	DrawDebugLine(GetWorld(), CurrentPolygonVertices[0], CurrentPolygonVertices[CurrentPolygonVertices.Num() - 1], FColor(0, 255, 0), true, 0, 5.f);

			//	DrawDebugSphere(GetWorld(), pathpoints[i], 5.f, 5, FColor(255, 0, 255), true, 0, 5.f);
			//}

			//PREVIOUS POLYGON
			NavNodeRef prevNodeRef = pathpoints[i - 1].NodeRef;
			TArray<FVector> PrevPolygonVertices;
			Nav->GetPolyVerts(prevNodeRef, PrevPolygonVertices);

			if (PrevPolygonVertices.Num() == 2)
			{
				//IGNORE
			}
			else
			{
				if (CurrentPolygonVertices.Num() == 2)
				{
					//VERTEX 1 IS ALWAYS BOTTOM LINK, VERTEX 0 IS ALWAYS TOP LINK
					//DrawDebugSphere(GetWorld(), CurrentPolygonVertices[0], 5.f, 5, FColor(255, 255, 255), true, 0, 10.f);
					//DrawDebugSphere(GetWorld(), CurrentPolygonVertices[1], 5.f, 5, FColor(0, 0, 0), true, 0, 10.f);

					//NEXT POLYGON
					NavNodeRef nextNodeRef = pathpoints[i + 1].NodeRef;
					TArray<FVector> NextPolygonVertices;
					Nav->GetPolyVerts(nextNodeRef, NextPolygonVertices);

					FMyPolyEdge TopEdge;
					FMyPolyEdge BottomEdge;
					if (FVector::DistSquared(pathpoints[i], CurrentPolygonVertices[0]) < FVector::DistSquared(pathpoints[i], CurrentPolygonVertices[1]))
					{
						TopEdge = GetEdgeClosestToPointOnPolygon(pathpoints[i], PrevPolygonVertices);
						BottomEdge = GetEdgeClosestToAnotherEdgeOnPolygon(TopEdge, NextPolygonVertices);
						TopEdge.IsJumpEdge = false;
						BottomEdge.IsJumpEdge = true;
						Portals.Add(TopEdge);
						Portals.Add(BottomEdge);
					}
					else
					{
						TopEdge = GetEdgeClosestToPointOnPolygon(pathpoints[i + 1], NextPolygonVertices);
						BottomEdge = GetEdgeClosestToAnotherEdgeOnPolygon(TopEdge, PrevPolygonVertices);
						TopEdge.IsJumpEdge = true;
						BottomEdge.IsJumpEdge = false;
						Portals.Add(BottomEdge);
						Portals.Add(TopEdge);
					}

					if (!PathfindingAuto)
					{
						DrawDebugLine(GetWorld(), TopEdge.Left, TopEdge.Right, FColor(255, 255, 255), true, 0, 5.f);
						DrawDebugLine(GetWorld(), BottomEdge.Left, BottomEdge.Right, FColor(255, 0, 0), true, 0, 5.f);
					}
				}
				else
				{
					FMyPolyEdge EdgeToAdd;
					if (i == pathpoints.Num() - 1)
					{
						EdgeToAdd = GetEdgeClosestToAnotherEdgeOnPolygon(Portals[Portals.Num() - 1], PrevPolygonVertices);
					}
					else
					{
						EdgeToAdd = GetEdgeClosestToPointOnPolygon(pathpoints[i], PrevPolygonVertices);
					}

					EdgeToAdd.IsJumpEdge = false;
					Portals.Add(EdgeToAdd);

					if (!PathfindingAuto)
					{
						//DrawDebugLine(GetWorld(), EdgeToAdd.Left, EdgeToAdd.Right, FColor(255, 255, 255), true, 0, 5.f);
					}
				}
			}
		}
	}

	CreateCustomPath(Portals, ControlledPawn->GetActorLocation(), CachedDestination);

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
		EnhancedInputComponent->BindAction(NextPortalAction, ETriggerEvent::Completed, this, &AFYPPlayerController::ComputeNextPathStep);
		EnhancedInputComponent->BindAction(SwitchPathfindModeAction, ETriggerEvent::Completed, this, &AFYPPlayerController::SwitchPathfindMode);

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

void AFYPPlayerController::CreateCustomPath(const TArray<FMyPolyEdge>& Portals, FVector Start, FVector Destination)
{
	//Clear old path
	AgentPathPoints.Empty();

	if (Portals.Num() < 1)
	{
		return;
	}
	TArray<FMyPolyEdge> PortalsButNoHeight;

	//MAKE EVERYTHING 2D
	Start.Z = 0;
	Destination.Z = 0;

	for (int i = 0; i < Portals.Num(); i++)
	{
		PortalsButNoHeight.Add(Portals[i]);
		PortalsButNoHeight[i].Left.Z = 0;
		PortalsButNoHeight[i].Right.Z = 0;
	}

	MyPortals = PortalsButNoHeight;

	MyPathPoints.Empty();
	MyPathPoints.Add(Start);

	//FMyPolyEdge Barrier1;
	Barrier1.Left = Start;
	Barrier1.Right = PortalsButNoHeight[0].Left;

	//FMyPolyEdge Barrier2;
	Barrier2.Left = Start;
	Barrier2.Right = PortalsButNoHeight[0].Right;

	float DotProduct = FVector::DotProduct(Barrier1.GetVectorTo(), Barrier2.GetVectorTo());
	Angle = DotProduct;

	CurrentPathIndex = 0;
	DidStep2 = true;

	MyPortals3D.Empty();
	MyPortals3D = Portals;

	if (PathfindingAuto)
	{
		CurrentPathIndex = 0;
		PathComplete = false;
		while (!PathComplete)
		{
			ComputeNextPathStep();
		}
		PathComplete = false;
		CurrentPathIndex = 0;
		LineIndex = 0;
		while (!PathComplete)
		{
			CompleteFinalPath();
		}

		FPathPoint finalPathPoint;
		finalPathPoint.Location = CachedDestination;
		finalPathPoint.IsJump = false;
		AgentPathPoints.Add(finalPathPoint);
		DrawDebugSphere(GetWorld(), finalPathPoint.Location, 5.f, 5, FColor(255, 0, 255), true, 0, 5.f);

		//DRAW FINAL 3D PATH
		for (int fin = 1; fin < AgentPathPoints.Num(); fin++)
		{
			DrawDebugLine(GetWorld(), AgentPathPoints[fin].Location, AgentPathPoints[fin - 1].Location, FColor(255, 255, 0), true, 0, 10.f);
		}

		CurrentPathIndex = 0;
		GoToNextPointOnCustomPath();
	}
}

FMyPolyEdge AFYPPlayerController::GetEdgeClosestToPointOnPolygon(const FVector& Point, const TArray<FVector>& PolygonVerticies)
{
	//FIND EDGE CONNECTING TO PREV POLYGON
	float Closest = FMath::PointDistToSegment(Point, PolygonVerticies[0], PolygonVerticies[PolygonVerticies.Num() - 1]);
	
	int LeftVert = 0;
	int RightVert = PolygonVerticies.Num() - 1;
	for (int j = 1; j < PolygonVerticies.Num(); j++)
	{
		float Distance = FMath::PointDistToSegment(Point, PolygonVerticies[j], PolygonVerticies[j-1]);
		if (Distance < Closest)
		{
			Closest = Distance;

			LeftVert = j;
			RightVert = j - 1;
		}
	}

	FMyPolyEdge Edge;
	Edge.Left = PolygonVerticies[LeftVert];
	Edge.Right = PolygonVerticies[RightVert];

	//DrawDebugLine(GetWorld(), Edge.Left, Edge.Right, FColor(0, 0, 255), true, 0, 10.f);

	return Edge;
}

FMyPolyEdge AFYPPlayerController::GetEdgeClosestToAnotherEdgeOnPolygon(const FMyPolyEdge& Edge, const TArray<FVector>& PolygonVerticies)
{
	FVector EdgeDirection = Edge.Right - Edge.Left;
	int LeftVert = 0;
	int RightVert = PolygonVerticies.Num() - 1;
	float Best = fabs(FVector::DotProduct(EdgeDirection, (PolygonVerticies[LeftVert] - PolygonVerticies[RightVert])));
	
	FVector Closest1;
	FVector Closest2;
	FMath::SegmentDistToSegment(Edge.Left, Edge.Right, PolygonVerticies[LeftVert], PolygonVerticies[RightVert], Closest1, Closest2);
	float Closest = FVector::DistSquared(Closest1, Closest2);

	for (int i = 0; i < PolygonVerticies.Num() - 1; i++)
	{
		FMath::SegmentDistToSegment(Edge.Left, Edge.Right, PolygonVerticies[i], PolygonVerticies[i + 1], Closest1, Closest2);
		float Distance = FVector::DistSquared(Closest1, Closest2);

		if (Distance <= Closest)
		{
			FVector PolyVertDirection = PolygonVerticies[i] - PolygonVerticies[i + 1];
			float DotProduct = fabs(FVector::DotProduct(EdgeDirection, PolyVertDirection));
			if (DotProduct > Best)
			{
				Best = DotProduct;
				Closest = Distance;

				LeftVert = i;
				RightVert = i + 1;
			}
		}
	}

	FMyPolyEdge ClosestEdge;
	ClosestEdge.Left = PolygonVerticies[LeftVert];
	ClosestEdge.Right = PolygonVerticies[RightVert];

	//DrawDebugLine(GetWorld(), ClosestEdge.Left, ClosestEdge.Right, FColor(255, 0, 0), true, 0, 10.f);

	return ClosestEdge;
}

bool AFYPPlayerController::FindPointSegmentIntersection(const FVector Point, const FVector SegmentStart, const FVector SegmentEnd)
{
	const FVector Da = Point - SegmentStart;
	const FVector Db = SegmentEnd - SegmentStart;
	if (FVector::CrossProduct(Da, Db).IsNearlyZero())
	{
		const float Res = Da.SizeSquared() / Db.SizeSquared();
		const float DotProd = FVector::DotProduct(Da, Db);
		if (DotProd >= 0 && 0 <= Res && Res <= 1)
		{
			return true;
		}
	}
	return false;
}

void AFYPPlayerController::ComputeNextPathStep()
{
	FVector NewPathPoint;
	bool IsParallel = false;
	if (DidStep2)
	{
		CurrentPathIndex++;
		if (CurrentPathIndex >= MyPortals.Num())
		{
			FVector End = CachedDestination;
			End.Z = 0;
			MyPathPoints.Add(End);
			PathComplete = true;

			if (!PathfindingAuto)
			{
				DrawDebugSphere(GetWorld(), End, 5.f, 5, FColor(255, 0, 0), true, 0, 5.f);

				LineIndex = 0;
				CurrentPathIndex = 0;
				CompleteFinalPath();
			}
			return;
		}

		//CHECK IF BACK TRACKED
		float distToPrevPortal = FVector::DistSquared(Barrier1.Left, (MyPortals[CurrentPathIndex - 1].Left + MyPortals[CurrentPathIndex - 1].Right) / 2.f);
		float distToNextPortal = FVector::DistSquared(Barrier1.Left, (MyPortals[CurrentPathIndex].Left + MyPortals[CurrentPathIndex].Right) / 2.f);
		if (distToNextPortal <= distToPrevPortal)
		{
			float Barrier1Length = FVector::DistSquared(Barrier1.Left, Barrier1.Right);
			float Barrier2Length = FVector::DistSquared(Barrier2.Left, Barrier2.Right);

			NewPathPoint = FMath::ClosestPointOnSegment(MyPathPoints[MyPathPoints.Num() - 1], Barrier1.Right, Barrier2.Right);
			MyPathPoints.Add(NewPathPoint);
			Barrier1.Left = NewPathPoint;
			Barrier2.Left = NewPathPoint;

			for (int portalIndex = 0; portalIndex < MyPortals.Num() - 1; portalIndex++)
			{
				if (NewPathPoint == MyPortals[portalIndex].Left || NewPathPoint == MyPortals[portalIndex].Right)
				{
					CurrentPathIndex = portalIndex + 1;
				}
			}
			Barrier1.Right = MyPortals[CurrentPathIndex].Left;
			Barrier2.Right = MyPortals[CurrentPathIndex].Right;

			Angle = FVector::DotProduct(Barrier1.GetVectorTo(), Barrier2.GetVectorTo());

			if (!PathfindingAuto)
			{
				DrawDebugSphere(GetWorld(), NewPathPoint, 5.f, 5, FColor(255, 0, 0), true, 0, 5.f);
			}
			return;
		}

		DidStep2 = false;

		//Update Barrier 1
		if (UpdateBarrier(Barrier1, Barrier2, MyPortals[CurrentPathIndex], Angle, NewPathPoint, FColor(0, 0, 255), IsParallel))
		{
			MyPathPoints.Add(NewPathPoint);
			if (CurrentPathIndex != MyPortals.Num() - 1)
			{
				Barrier1.Left = NewPathPoint;
				Barrier2.Left = NewPathPoint;

				for (int portalIndex = 0; portalIndex < MyPortals.Num() - 1; portalIndex++)
				{
					if (NewPathPoint == MyPortals[portalIndex].Left || NewPathPoint == MyPortals[portalIndex].Right)
					{
						CurrentPathIndex = portalIndex + 1;
					}
				}
				Barrier1.Right = MyPortals[CurrentPathIndex].Left;
				Barrier2.Right = MyPortals[CurrentPathIndex].Right;

				Angle = FVector::DotProduct(Barrier1.GetVectorTo(), Barrier2.GetVectorTo());

				if (!PathfindingAuto)
				{
					DrawDebugSphere(GetWorld(), NewPathPoint, 5.f, 5, FColor(255, 0, 0), true, 0, 5.f);
					DrawDebugLine(GetWorld(), Barrier1.Left, Barrier1.Right, FColor(0, 0, 255), true, 0, 20.f);
					DrawDebugLine(GetWorld(), Barrier2.Left, Barrier2.Right, FColor(255, 125, 0), true, 0, 20.f);
				}
			}
			DidStep2 = true;
			return;
		}
	}
	else
	{
		DidStep2 = true;
		//Update Barrier 2
		if (UpdateBarrier(Barrier2, Barrier1, MyPortals[CurrentPathIndex], Angle, NewPathPoint, FColor(255, 125, 0), IsParallel))
		{
			MyPathPoints.Add(NewPathPoint);
			if (CurrentPathIndex != MyPortals.Num() - 1)
			{
				Barrier1.Left = NewPathPoint;
				Barrier2.Left = NewPathPoint;

				for (int portalIndex = 0; portalIndex < MyPortals.Num() - 1; portalIndex++)
				{
					if (NewPathPoint == MyPortals[portalIndex].Left || NewPathPoint == MyPortals[portalIndex].Right)
					{
						CurrentPathIndex = portalIndex + 1;
					}
				}

				Barrier1.Right = MyPortals[CurrentPathIndex].Left;
				Barrier2.Right = MyPortals[CurrentPathIndex].Right;

				Angle = FVector::DotProduct(Barrier1.GetVectorTo(), Barrier2.GetVectorTo());

				if (!PathfindingAuto)
				{
					DrawDebugSphere(GetWorld(), NewPathPoint, 5.f, 5, FColor(255, 0, 0), true, 0, 5.f);
					DrawDebugLine(GetWorld(), Barrier1.Left, Barrier1.Right, FColor(0, 0, 255), true, 0, 20.f);
					DrawDebugLine(GetWorld(), Barrier2.Left, Barrier2.Right, FColor(255, 125, 0), true, 0, 20.f);
				}
			}
			else
			{
				if (FVector::DistSquared(Barrier1.Left, Barrier1.Right) < FVector::DistSquared(Barrier2.Left, Barrier2.Right))
				{
					MyPathPoints.Add(Barrier1.Right);
				}
				else
				{
					MyPathPoints.Add(Barrier2.Right);
				}
			}
			return;
		}
	}
	
}

void AFYPPlayerController::SwitchPathfindMode()
{
	PathfindingAuto = !PathfindingAuto;
}

void AFYPPlayerController::CompleteFinalPath()
{
	for (int j = 1; j < MyPathPoints.Num(); j++)
	{
		DrawDebugLine(GetWorld(), MyPathPoints[j], MyPathPoints[j - 1], FColor(255, 0, 0), true, 0, 10.f);
	}

	if (CurrentPathIndex == 0)
	{
		FPathPoint firstPathPoint;
		firstPathPoint.IsJump = false;
		firstPathPoint.Location = GetPawn()->GetActorLocation();
		AgentPathPoints.Add(firstPathPoint);
		CurrentPathIndex++;
		DrawDebugSphere(GetWorld(), firstPathPoint.Location, 5.f, 5, FColor(255, 0, 255), true, 0, 20.f);
		return;
	}

	if (LineIndex <= MyPathPoints.Num() - 1)
	{
		DrawDebugLine(GetWorld(), MyPathPoints[LineIndex], MyPathPoints[LineIndex + 1], FColor(0, 0, 255), true, 0, 10.f);
	}
	else
	{
		PathComplete = true;
		return;
	}

	if (CurrentPathIndex - 1 <= MyPortals.Num() - 1)
	{
		DrawDebugLine(GetWorld(), MyPortals[CurrentPathIndex - 1].Left, MyPortals[CurrentPathIndex - 1].Right, FColor(0, 255, 255), true, 0, 10.f);
	}
	else
	{
		PathComplete = true;
		return;
	}

	FVector Intersection;
	if (FindSegmentSegmentIntersection(MyPortals[CurrentPathIndex - 1].Left, MyPortals[CurrentPathIndex - 1].Right, MyPathPoints[LineIndex], MyPathPoints[LineIndex + 1], Intersection))
	{
		if (AgentPathPoints.Num() > 0)
		{
			FVector PreviousLocation = AgentPathPoints[AgentPathPoints.Num() - 1].Location;
			PreviousLocation.Z = 0;
			if (Intersection == PreviousLocation)
			{
				CurrentPathIndex++;
				return;
			}
			FVector ClosestPoint = FMath::ClosestPointOnSegment(Intersection, MyPortals[CurrentPathIndex - 1].Left, MyPortals[CurrentPathIndex - 1].Right);
			if (FVector::DistSquared(ClosestPoint, Intersection) > 1.f)
			{
				CurrentPathIndex++;
				return;
			}
		}
		FPathPoint newPathPoint;
		newPathPoint.IsJump = false;
		newPathPoint.Location = Intersection;
		newPathPoint.Location.Z = MyPortals3D[CurrentPathIndex - 1].Left.Z;

		DrawDebugSphere(GetWorld(), newPathPoint.Location, 5.f, 5, FColor(255, 0, 255), true, 0, 50.f);
		if (MyPortals3D[CurrentPathIndex - 1].IsJumpEdge)
		{
			newPathPoint.IsJump = true;
		}

		if (!newPathPoint.IsJump)
		{
			if (AgentPathPoints.Num() >= 1 && !AgentPathPoints[AgentPathPoints.Num() - 1].IsJump)
			{
				//REPLACE LAST NODE WITH CLOSER ONE
				AgentPathPoints[AgentPathPoints.Num() - 1] = newPathPoint;
			}
			else
			{
				//ADD NORMAL NODE
				AgentPathPoints.Add(newPathPoint);
			}
		}
		else
		{
			//ADD JUMP TO NODE
			AgentPathPoints.Add(newPathPoint);
		}
		CurrentPathIndex++;
	}
	else
	{
		LineIndex++;
		if (LineIndex >= MyPathPoints.Num() - 1)
		{
			PathComplete = true;
			return;
		}
		CurrentPathIndex--;
	}
}

bool AFYPPlayerController::UpdateBarrier(FMyPolyEdge& BarrierToUpdate, FMyPolyEdge& OtherBarrier, const FMyPolyEdge& NextPortal, float& AngleBetweenBarriers, FVector& OutNewPathPoint, FColor ColourBarrier, bool& Parallel)
{
	FVector PreviousLocation = BarrierToUpdate.Right;
	//If intersect, went to wrong vertex. Swap.
	FVector Intersect;
	if (FindSegmentSegmentIntersection(BarrierToUpdate.Right, NextPortal.Left, OtherBarrier.Right, NextPortal.Right, Intersect))
	{
		BarrierToUpdate.Right = NextPortal.Right;
	}
	else
	{
		BarrierToUpdate.Right = NextPortal.Left;
	}

	//Calc new angle
	float newDotProduct = FVector::DotProduct(BarrierToUpdate.GetVectorTo(), OtherBarrier.GetVectorTo());

	FVector ExtendOtherBarrier = OtherBarrier.Left + (OtherBarrier.Right - OtherBarrier.Left) * 100.f;
	if (FindSegmentSegmentIntersection(PreviousLocation, BarrierToUpdate.Right, OtherBarrier.Left, ExtendOtherBarrier, Intersect))
	{
		OutNewPathPoint = OtherBarrier.Right;
		if (!PathfindingAuto)
		{
			DrawDebugLine(GetWorld(), OtherBarrier.Left, OtherBarrier.Right, FColor(0, 255, 255), true, 0, 10.f);
		}
		return true;
	}

	//Check new angle
	if (newDotProduct > AngleBetweenBarriers)
	{
		//Funnel got tighter
		AngleBetweenBarriers = newDotProduct;
	}
	else
	{
		//Funnel got wider
		BarrierToUpdate.Right = PreviousLocation;
	}

	if (!PathfindingAuto)
	{
		DrawDebugLine(GetWorld(), BarrierToUpdate.Left, BarrierToUpdate.Right, ColourBarrier, true, 0, 10.f);
	}
	return false;
}

bool AFYPPlayerController::FindSegmentSegmentIntersection(const FVector Segment1Start, const FVector Segment1End, const FVector Segment2Start, const FVector Segment2End, FVector& IntersectionPoint)
{
	// both points
	if (Segment1Start == Segment1End && Segment2Start == Segment2End)
	{
		if (Segment1Start == Segment2Start)
		{
			IntersectionPoint = Segment1Start;
			return true;
		}
		return false;
	}

	//segment 1 is point
	if (Segment1Start == Segment1End)
	{
		if (FindPointSegmentIntersection(Segment1Start, Segment2Start, Segment2End))
		{
			IntersectionPoint = Segment1Start;
			return true;
		}
		return false;
	}

	//segment 2 is point
	if (Segment2Start == Segment2End)
	{
		if (FindPointSegmentIntersection(Segment2Start, Segment1Start, Segment1End))
		{
			IntersectionPoint = Segment2Start;
			return true;
		}
		return false;
	}

	//both segments
	const FVector S1Delta = Segment1End - Segment1Start;
	const FVector S2Delta = Segment2End - Segment2Start;
	const FVector Delta = Segment2Start - Segment1Start;
	const FVector Cross = FVector::CrossProduct(S1Delta, S2Delta);

	if (Cross.IsNearlyZero())
	{
		if (!FVector::CrossProduct(Delta, S2Delta).IsNearlyZero())
		{
			//parallel
			return false;
		}
		//overlap
		const float T0 = FVector::DotProduct(Delta, S1Delta) / S1Delta.SizeSquared();
		const float T1 = T0 + FVector::DotProduct(S2Delta, S1Delta) / S1Delta.SizeSquared();
		if (T0 <= 0 && T0 <= 1)
		{
			IntersectionPoint = Segment1Start + (S1Delta * T0);
			return true;
		}
		if (T0 <= 0 && 0 <= T1)
		{
			IntersectionPoint = Segment1Start;
			return true;
		}
		if (0 <= T1 && T1 <= 1)
		{
			IntersectionPoint = Segment1Start + (S1Delta * T0);
			return true;
		}
		if (T0 <= 1 && 1 <= T1)
		{
			IntersectionPoint = Segment1Start;
			return true;
		}
		return false;
	}

	if (!FMath::IsNearlyZero(FVector::DotProduct(Delta, Cross)))
	{
		//skew
		return false;
	}

	FVector Cross1 = FVector::CrossProduct(Delta, S1Delta);
	const FVector Cross2 = FVector::CrossProduct(Delta, S2Delta);
	FVector Start = Segment2Start;
	FVector SDelta = S2Delta;
	if (Cross1.IsNearlyZero())
	{
		Cross1 = Cross2;
		Start = Segment1Start;
		SDelta = S1Delta;
	}

	const float Dot1 = FVector::DotProduct(Cross1, Cross);
	const float Dot2 = FVector::DotProduct(Cross2, Cross);
	const float Denom = Cross.SizeSquared();

	if (0 <= Dot1 && Dot1 <= Denom && 0 <= Dot2 && Dot2 <= Denom)
	{
		IntersectionPoint = Start + (SDelta * (Dot1 / Denom));
		return true;
	}
	return false;
}

void AFYPPlayerController::GoToNextPointOnCustomPath()
{
	if (AgentPathPoints.Num() == 0 || CurrentPathIndex >= AgentPathPoints.Num())
	{
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, CachedDestination);
		return;
	}

	bool IsAnyJumpPoints;
	for (int i = 0; i < AgentPathPoints.Num() - 1; i++)
	{
		if (AgentPathPoints[i].IsJump)
		{
			IsAnyJumpPoints = true;
		}
	}

	if (!IsAnyJumpPoints)
	{
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, CachedDestination);
		return;
	}

	if (AgentPathPoints[CurrentPathIndex].IsJump)
	{
		//Let BP make spline path
	}
	else
	{
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, AgentPathPoints[CurrentPathIndex].Location);
	}
	CustomGoingToNextPoint(AgentPathPoints[CurrentPathIndex]);
	CurrentPathIndex++;
}
