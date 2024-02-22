// Fill out your copyright notice in the Description page of Project Settings.


#include "MyJumpNavigationComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "NavigationPath.h"
#include "NavMesh/RecastNavMesh.h"
#include "Runtime/NavigationSystem/Public/NavigationSystem.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UMyJumpNavigationComponent::UMyJumpNavigationComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	PathfindingAuto = true;
	DrawDebug = false;
}

void UMyJumpNavigationComponent::Initialise(AController* Controller, APawn* Pawn, float MaxJumpDist, float MinJumpDist)
{
	MyController = Controller;
	MyPawn = Pawn;
	AgentMaxJumpDistance = MaxJumpDist;
	AgentMinJumpDistance = MinJumpDist;
}

void UMyJumpNavigationComponent::BeginPlay()
{
	Nav = Cast<ARecastNavMesh>(UGameplayStatics::GetActorOfClass(GetWorld(), ARecastNavMesh::StaticClass()));
}

void UMyJumpNavigationComponent::CreateCustomJumpPath(const FVector& Start, const FVector& Destination, const bool& ShouldDrawDebug, const bool& IsAutoPathfinding)
{
	startSeconds = FPlatformTime::Seconds();

	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, FString::Printf(TEXT("Start: %f ms"), startSeconds));

	StartOfPath = Start;
	FinalDestination = Destination;
	DrawDebug = ShouldDrawDebug;
	PathfindingAuto = IsAutoPathfinding;

	FindPathPortals();
}

void UMyJumpNavigationComponent::FindPathPortals()
{
	UNavigationSystemV1* NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
	UNavigationPath* path = NavSys->FindPathToLocationSynchronously(this, StartOfPath, FinalDestination, MyPawn);

	TArray<FMyPolyEdge> Portals;

	if (path && path->IsValid())
	{
		TArray<FNavPathPoint> pathpoints = path->GetPath()->GetPathPoints();

		if (pathpoints.Num() <= 2)
		{
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(MyController, FinalDestination);
			return;
		}

		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, FString::Printf(TEXT("Amount of nodes in path: %d"), pathpoints.Num()));

		for (int i = 0; i < pathpoints.Num(); i++)
		{
			NavNodeRef nodeRef = pathpoints[i].NodeRef;
			TArray<FVector> CurrentPolygonVertices;
			Nav->GetPolyVerts(nodeRef, CurrentPolygonVertices);

			if (DrawDebug)
			{
				for (int j = 1; j < CurrentPolygonVertices.Num(); j++)
				{
					DrawDebugLine(GetWorld(), CurrentPolygonVertices[j], CurrentPolygonVertices[j - 1], FColor(0, 255, 0), true, 0, 5.f);
				}
				DrawDebugLine(GetWorld(), CurrentPolygonVertices[0], CurrentPolygonVertices[CurrentPolygonVertices.Num() - 1], FColor(0, 255, 0), true, 0, 5.f);

				DrawDebugSphere(GetWorld(), pathpoints[i], 5.f, 5, FColor(255, 0, 255), true, 0, 5.f);
			}

			if (CurrentPolygonVertices.Num() == 2)
			{
				//VERTEX 1 IS ALWAYS BOTTOM LINK, VERTEX 0 IS ALWAYS TOP LINK
				//NEIGHBOUR 1 IS ALWAYS TOP, NEIGHBOUR 0 IS ALWAYS BOTTOM
				//DrawDebugSphere(GetWorld(), CurrentPolygonVertices[0], 5.f, 5, FColor(255, 255, 255), true, 0, 10.f);
				//DrawDebugSphere(GetWorld(), CurrentPolygonVertices[1], 5.f, 5, FColor(0, 0, 0), true, 0, 10.f);

				TArray<NavNodeRef> Neighbours;
				Nav->GetPolyNeighbors(nodeRef, Neighbours);

				TArray<FVector> BottomPolygonVertices;
				Nav->GetPolyVerts(Neighbours[0], BottomPolygonVertices);
				TArray<FVector> TopPolygonVertices;
				Nav->GetPolyVerts(Neighbours[1], TopPolygonVertices);

				FMyPolyEdge TopEdge;
				FMyPolyEdge BottomEdge;
				if (FVector::DistSquared(pathpoints[i], CurrentPolygonVertices[0]) < FVector::DistSquared(pathpoints[i], CurrentPolygonVertices[1]))
				{
					//TOP LINK IS FIRST IN PATH
					TopEdge = GetEdgeClosestToPointOnPolygon(pathpoints[i], TopPolygonVertices);
					BottomEdge = GetEdgeClosestToAnotherEdgeOnPolygon(TopEdge, BottomPolygonVertices);
					TopEdge.IsJumpEdge = false;
					BottomEdge.IsJumpEdge = true;
					Portals.Add(TopEdge);
					Portals.Add(BottomEdge);
				}
				else
				{
					//BOTTOM LINK IS FIRST IN PATH
					TopEdge = GetEdgeClosestToPointOnPolygon(pathpoints[i + 1], TopPolygonVertices);
					BottomEdge = GetEdgeClosestToAnotherEdgeOnPolygon(TopEdge, BottomPolygonVertices);
					TopEdge.IsJumpEdge = true;
					BottomEdge.IsJumpEdge = false;
					Portals.Add(BottomEdge);
					Portals.Add(TopEdge);
				}
				continue;
			}
		}
	}

	if (Portals.Num() == 0)
	{
		return;
	}

	if (DrawDebug)
	{
		for (int i = 1; i < Portals.Num(); i++)
		{
			if (Portals[i].IsJumpEdge)
			{
				DrawDebugLine(GetWorld(), Portals[i].Left, Portals[i].Right, FColor(255, 255, 255), true, 0, 10.f);
				DrawDebugLine(GetWorld(), Portals[i - 1].Left, Portals[i - 1].Right, FColor(0, 0, 0), true, 0, 10.f);
			}
		}
	}
	CreateCustomPath(Portals, StartOfPath, FinalDestination);
}

bool UMyJumpNavigationComponent::DoNextPathFindingStep()
{
	if (!PathComplete)
	{
		CreatePathIn2D();
	}

	return PathComplete;
}

void UMyJumpNavigationComponent::GoToNextPointOnCustomPath()
{
	if (AgentPathPoints.Num() == 0 || CurrentPathIndex >= AgentPathPoints.Num())
	{
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(MyController, FinalDestination);
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
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(MyController, FinalDestination);
		return;
	}

	if (AgentPathPoints[CurrentPathIndex].IsJump)
	{
		//Let BP make spline path
	}
	else
	{
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(MyController, AgentPathPoints[CurrentPathIndex].Location);
	}
	CustomGoingToNextPoint(AgentPathPoints[CurrentPathIndex]);
	CurrentPathIndex++;
}

FMyPolyEdge UMyJumpNavigationComponent::GetEdgeClosestToPointOnPolygon(const FVector& Point, const TArray<FVector>& PolygonVerticies)
{
	//FIND EDGE CONNECTING TO PREV POLYGON
	float Closest = FMath::PointDistToSegment(Point, PolygonVerticies[0], PolygonVerticies[PolygonVerticies.Num() - 1]);

	int LeftVert = 0;
	int RightVert = PolygonVerticies.Num() - 1;

	for (int j = 1; j < PolygonVerticies.Num(); j++)
	{
		float Distance = FMath::PointDistToSegment(Point, PolygonVerticies[j], PolygonVerticies[j - 1]);
		if (Distance <= Closest)
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

FMyPolyEdge UMyJumpNavigationComponent::GetEdgeClosestToAnotherEdgeOnPolygon(const FMyPolyEdge& Edge, const TArray<FVector>& PolygonVerticies)
{
	FVector EdgeDirection = Edge.Right - Edge.Left;
	EdgeDirection.Z = 0;
	EdgeDirection.Normalize();
	int LeftVert = 0;
	int RightVert = PolygonVerticies.Num() - 1;
	FVector PolyEdgeDirection = (PolygonVerticies[LeftVert] - PolygonVerticies[RightVert]);
	PolyEdgeDirection.Z = 0;
	PolyEdgeDirection.Normalize();
	float Best = fabs(FVector::DotProduct(EdgeDirection, PolyEdgeDirection));

	FVector Closest1;
	FVector Closest2;
	FMath::SegmentDistToSegment(Edge.Left, Edge.Right, PolygonVerticies[LeftVert], PolygonVerticies[RightVert], Closest1, Closest2);
	float Closest = FVector::DistSquared(Closest1, Closest2);

	for (int i = 1; i < PolygonVerticies.Num(); i++)
	{
		FMath::SegmentDistToSegment(Edge.Left, Edge.Right, PolygonVerticies[i], PolygonVerticies[i - 1], Closest1, Closest2);
		float Distance = FVector::DistSquared(Closest1, Closest2);

		if (Distance <= Closest)
		{
			PolyEdgeDirection = PolygonVerticies[i] - PolygonVerticies[i - 1];
			PolyEdgeDirection.Z = 0;
			PolyEdgeDirection.Normalize();
			float DotProduct = fabs(FVector::DotProduct(EdgeDirection, PolyEdgeDirection));
			if (DotProduct > Best)
			{
				Best = DotProduct;
				Closest = Distance;

				LeftVert = i;
				RightVert = i - 1;
			}
		}
	}

	FMyPolyEdge ClosestEdge;
	ClosestEdge.Left = PolygonVerticies[LeftVert];
	ClosestEdge.Right = PolygonVerticies[RightVert];

	//DrawDebugLine(GetWorld(), ClosestEdge.Left, ClosestEdge.Right, FColor(255, 0, 0), true, 0, 10.f);

	return ClosestEdge;
}

void UMyJumpNavigationComponent::CreateCustomPath(const TArray<FMyPolyEdge>& Portals, FVector Start, FVector Destination)
{
	//Clear old path
	AgentPathPoints.Empty();

	if (Portals.Num() < 1)
	{
		GoToNextPointOnCustomPath();
		return;
	}
	TArray<FMyPolyEdge> PortalsButNoHeight;

	//MAKE EVERYTHING 2D
	FVector StartButNoHeight = Start;
	StartButNoHeight.Z = 0;

	for (int i = 0; i < Portals.Num(); i++)
	{
		PortalsButNoHeight.Add(Portals[i]);
		PortalsButNoHeight[i].Left.Z = 0;
		PortalsButNoHeight[i].Right.Z = 0;
	}

	MyPortals = PortalsButNoHeight;

	MyPathPoints.Empty();
	MyPathPoints.Add(StartButNoHeight);

	//FMyPolyEdge Barrier1;
	Barrier1.Left = StartButNoHeight;
	Barrier1.Right = PortalsButNoHeight[0].Left;

	//FMyPolyEdge Barrier2;
	Barrier2.Left = StartButNoHeight;
	Barrier2.Right = PortalsButNoHeight[0].Right;

	float DotProduct = FVector::DotProduct(Barrier1.GetVectorTo(), Barrier2.GetVectorTo());
	Angle = DotProduct;

	if (DrawDebug && !PathfindingAuto)
	{
		DrawDebugLine(GetWorld(), Barrier1.Left, Barrier1.Right, FColor(0, 0, 255), true, 0, 10.f);
		DrawDebugLine(GetWorld(), Barrier2.Left, Barrier2.Right, FColor(255, 125, 0), true, 0, 10.f);
	}

	CurrentPathIndex = 0;
	DidStep2 = true;

	MyPortals3D.Empty();
	MyPortals3D = Portals;

	CurrentPathIndex = 0;
	PathComplete = false;
	LineIndex = 0;
	if (PathfindingAuto)
	{
		while (!PathComplete)
		{
			CreatePathIn2D();
		}
		PathComplete = false;
		CurrentPathIndex = 0;
		while (!PathComplete)
		{
			CreatePathIn3D();
		}

		FPathPoint finalPathPoint;
		finalPathPoint.Location = FinalDestination;
		finalPathPoint.IsJump = false;
		if (!AgentPathPoints[AgentPathPoints.Num() - 1].IsJump)
		{
			AgentPathPoints[AgentPathPoints.Num() - 1] = finalPathPoint;
		}
		else
		{
			AgentPathPoints.Add(finalPathPoint);
		}

		if (DrawDebug)
		{
			DrawDebugSphere(GetWorld(), finalPathPoint.Location, 5.f, 5, FColor(255, 0, 255), true, 0, 5.f);
			DrawDebugLine(GetWorld(), StartOfPath, AgentPathPoints[0].Location, FColor(255, 255, 0), true, 0, 10.f);

			//DRAW FINAL 3D PATH
			for (int fin = 1; fin < AgentPathPoints.Num(); fin++)
			{
				DrawDebugLine(GetWorld(), AgentPathPoints[fin].Location, AgentPathPoints[fin - 1].Location, FColor(255, 255, 0), true, 0, 10.f);
			}
		}

		CurrentPathIndex = 0;

		double endSeconds = FPlatformTime::Seconds();
		double differenceInMs = (endSeconds - startSeconds) * 1000.f;

		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, FString::Printf(TEXT("Found path in %f ms"), differenceInMs));

		GoToNextPointOnCustomPath();
	}
}

void UMyJumpNavigationComponent::CreatePathIn2D()
{
	FVector NewPathPoint;
	if (DidStep2)
	{
		//CHECK IF CAN REACH END FROM LAST PATH POINT
		bool Started = false;
		for (int i = 0; i < MyPortals.Num() - 1; i++)
		{
			if (!Started)
			{
				if (FMath::PointDistToSegment(MyPathPoints[MyPathPoints.Num() - 1], MyPortals[i].Left, MyPortals[i].Right) < 1.f || MyPathPoints.Num() == 1)
				{
					Started = true;
				}
			}

			if (Started)
			{
				FVector End = FinalDestination;
				End.Z = 0;
				FVector Intersect;
				if (!FindSegmentSegmentIntersection(MyPathPoints[MyPathPoints.Num() - 1], End, MyPortals[i].Left, MyPortals[i].Right, Intersect))
				{
					Started = false;
					break;
				}
			}
		}
		if (Started)
		{
			FVector End = FinalDestination;
			End.Z = 0;
			MyPathPoints.Add(End);
			PathComplete = true;

			if (!PathfindingAuto)
			{
				if (DrawDebug)
				{
					DrawDebugSphere(GetWorld(), End, 5.f, 5, FColor(255, 0, 0), true, 0, 5.f);
				}

				LineIndex = 0;
				CurrentPathIndex = 0;
				CreatePathIn3D();
			}
			return;
		}

		CurrentPathIndex++;
		if (CurrentPathIndex >= MyPortals.Num())
		{
			if (FVector::DistSquared(Barrier1.Left, Barrier1.Right) < FVector::DistSquared(Barrier2.Left, Barrier2.Right))
			{
				MyPathPoints.Add(Barrier1.Right);
			}
			else
			{
				MyPathPoints.Add(Barrier2.Right);
			}

			FVector End = FinalDestination;
			End.Z = 0;
			MyPathPoints.Add(End);
			PathComplete = true;

			if (!PathfindingAuto)
			{
				if (DrawDebug)
				{
					DrawDebugSphere(GetWorld(), End, 5.f, 5, FColor(255, 0, 0), true, 0, 5.f);
				}

				LineIndex = 0;
				CurrentPathIndex = 0;
				CreatePathIn3D();
			}
			return;
		}

		//CHECK IF BACK TRACKED
		float distToPrevPortal = FMath::PointDistToSegment(Barrier1.Left, MyPortals[CurrentPathIndex - 1].Left, MyPortals[CurrentPathIndex - 1].Right);
		float distToNextPortal = FMath::PointDistToSegment(Barrier1.Left, MyPortals[CurrentPathIndex].Left, MyPortals[CurrentPathIndex].Right);
		if (distToNextPortal <= distToPrevPortal)
		{
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

			if (DrawDebug && !PathfindingAuto)
			{
				DrawDebugSphere(GetWorld(), NewPathPoint, 5.f, 5, FColor(255, 0, 0), true, 0, 5.f);
			}
			return;
		}

		DidStep2 = false;

		//Update Barrier 1
		if (UpdateBarrier(Barrier1, Barrier2, MyPortals[CurrentPathIndex], Angle, NewPathPoint, FColor(0, 0, 255)))
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

				if (DrawDebug && !PathfindingAuto)
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
		if (UpdateBarrier(Barrier2, Barrier1, MyPortals[CurrentPathIndex], Angle, NewPathPoint, FColor(255, 125, 0)))
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

				if (DrawDebug && !PathfindingAuto)
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

void UMyJumpNavigationComponent::CreatePathIn3D()
{
	if (DrawDebug && !PathfindingAuto)
	{
		for (int j = 1; j < MyPathPoints.Num(); j++)
		{
			DrawDebugLine(GetWorld(), MyPathPoints[j], MyPathPoints[j - 1], FColor(255, 0, 0), true, 0, 10.f);
		}
	}

	if (CurrentPathIndex == 0)
	{
		FPathPoint firstPathPoint;
		firstPathPoint.IsJump = false;
		firstPathPoint.Location = StartOfPath;
		AgentPathPoints.Add(firstPathPoint);
		CurrentPathIndex++;

		if (DrawDebug && !PathfindingAuto)
		{
			DrawDebugSphere(GetWorld(), firstPathPoint.Location, 5.f, 5, FColor(255, 0, 255), true, 0, 20.f);
		}
		
		return;
	}

	//if (LineIndex < MyPathPoints.Num() - 1)
	//{
	//	if (DrawDebug)
	//	{
	//		DrawDebugLine(GetWorld(), MyPathPoints[LineIndex], MyPathPoints[LineIndex + 1], FColor(0, 0, 255), true, 0, 10.f);
	//	}
	//}
	//else
	//{
	//	PathComplete = true;
	//	return;
	//}

	if (CurrentPathIndex - 1 < MyPortals.Num())
	{
		if (DrawDebug && !PathfindingAuto)
		{
			DrawDebugLine(GetWorld(), MyPortals[CurrentPathIndex - 1].Left, MyPortals[CurrentPathIndex - 1].Right, FColor(0, 255, 255), true, 0, 10.f);
		}
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
			//Code to prevent adding multiple of the same pathpoint
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
		
		if (MyPortals3D[CurrentPathIndex - 1].IsJumpEdge)
		{
			newPathPoint.IsJump = true;

			//IF JUMP LANDING LOCATION IS TOO FAR, BRING IT CLOSER

			FVector LastPathPoint = AgentPathPoints[AgentPathPoints.Num() - 1].Location;
			LastPathPoint.Z = 0;
			if (FVector::Distance(newPathPoint.Location, LastPathPoint) > AgentMaxJumpDistance)
			{
				//Try shifting jump landing location closer to jump from location
				FVector ClosestPoint = FMath::ClosestPointOnInfiniteLine(MyPortals[CurrentPathIndex - 1].Left, MyPortals[CurrentPathIndex - 1].Right, LastPathPoint);
				float DesiredDistance = FMath::Sqrt((AgentMaxJumpDistance * AgentMaxJumpDistance) - (FVector::DistSquared(ClosestPoint, LastPathPoint)));
				FVector ShiftDirection = newPathPoint.Location - ClosestPoint;
				ShiftDirection.Normalize();
				FVector ShiftedPosition = ClosestPoint + (ShiftDirection * DesiredDistance);

				//Testing if shifted position is valid
				if (FMath::PointDistToSegment(ShiftedPosition, MyPortals[CurrentPathIndex - 1].Left, MyPortals[CurrentPathIndex - 1].Right) < 5.f)
				{
					newPathPoint.Location = ShiftedPosition;
				}
				else
				{
					//Try shifting jump from location instead
					ClosestPoint = FMath::ClosestPointOnInfiniteLine(MyPortals[CurrentPathIndex - 2].Left, MyPortals[CurrentPathIndex - 2].Right, newPathPoint.Location);
					DesiredDistance = FMath::Sqrt((AgentMaxJumpDistance * AgentMaxJumpDistance) - (FVector::DistSquared(ClosestPoint, newPathPoint.Location)));
					ShiftDirection = LastPathPoint - ClosestPoint;
					ShiftDirection.Normalize();
					ShiftedPosition = ClosestPoint + (ShiftDirection * DesiredDistance);

					//Testing if shifted position is valid
					if (FMath::PointDistToSegment(ShiftedPosition, MyPortals[CurrentPathIndex - 2].Left, MyPortals[CurrentPathIndex - 2].Right) < 5.f)
					{
						if (MyPortals3D[CurrentPathIndex - 2].Left.Z == MyPortals3D[CurrentPathIndex - 2].Right.Z)
						{
							ShiftedPosition.Z = MyPortals3D[CurrentPathIndex - 2].Left.Z;
							AgentPathPoints[AgentPathPoints.Num() - 1].Location = ShiftedPosition;
						}
						else
						{
							float percentageAlong = FVector::DistSquared(MyPortals[CurrentPathIndex - 2].Left, ShiftedPosition) / FVector::DistSquared(MyPortals[CurrentPathIndex - 2].Left, MyPortals[CurrentPathIndex - 2].Right);

							FVector DirectionAlong = MyPortals3D[CurrentPathIndex - 2].Right - MyPortals3D[CurrentPathIndex - 2].Left;
							DirectionAlong *= percentageAlong;
							FVector Position3D = MyPortals3D[CurrentPathIndex - 2].Left + DirectionAlong;

							AgentPathPoints[AgentPathPoints.Num() - 1].Location = Position3D;
						}
					}
					else
					{
						FVector Closest1;
						FVector Closest2;
						FMath::SegmentDistToSegment(MyPortals[CurrentPathIndex - 2].Left, MyPortals[CurrentPathIndex - 2].Right, MyPortals[CurrentPathIndex - 1].Left, MyPortals[CurrentPathIndex - 1].Right, Closest1, Closest2);

						if (MyPortals3D[CurrentPathIndex - 2].Left.Z == MyPortals3D[CurrentPathIndex - 2].Right.Z)
						{
							Closest1.Z = MyPortals3D[CurrentPathIndex - 2].Left.Z;
							AgentPathPoints[AgentPathPoints.Num() - 1].Location = Closest1;
						}
						else
						{
							float percentageAlong = FVector::DistSquared(MyPortals[CurrentPathIndex - 2].Left, Closest1) / FVector::DistSquared(MyPortals[CurrentPathIndex - 2].Left, MyPortals[CurrentPathIndex - 2].Right);

							FVector DirectionAlong = MyPortals3D[CurrentPathIndex - 2].Right - MyPortals3D[CurrentPathIndex - 2].Left;
							DirectionAlong *= percentageAlong;
							FVector Position3D = MyPortals3D[CurrentPathIndex - 2].Left + DirectionAlong;

							AgentPathPoints[AgentPathPoints.Num() - 1].Location = Position3D;
						}

						newPathPoint.Location = Closest2;
					}
				}
			}

		}

		//MOVE TO APPROPRIATE Z POSITION
		if (MyPortals3D[CurrentPathIndex - 1].Left.Z == MyPortals3D[CurrentPathIndex - 1].Right.Z)
		{
			newPathPoint.Location.Z = MyPortals3D[CurrentPathIndex - 1].Left.Z;
		}
		else
		{
			float percentageAlong = FVector::DistSquared(MyPortals[CurrentPathIndex - 1].Left, newPathPoint.Location) / FVector::DistSquared(MyPortals[CurrentPathIndex - 1].Left, MyPortals[CurrentPathIndex - 1].Right);

			FVector DirectionAlong = MyPortals3D[CurrentPathIndex - 1].Right - MyPortals3D[CurrentPathIndex - 1].Left;
			DirectionAlong *= percentageAlong;
			FVector Position3D = MyPortals3D[CurrentPathIndex - 1].Left + DirectionAlong;
			newPathPoint.Location.Z = Position3D.Z;
		}

		if (DrawDebug && !PathfindingAuto)
		{
			DrawDebugSphere(GetWorld(), newPathPoint.Location, 5.f, 5, FColor(255, 0, 255), true, 0, 50.f);
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

bool UMyJumpNavigationComponent::UpdateBarrier(FMyPolyEdge& BarrierToUpdate, FMyPolyEdge& OtherBarrier, const FMyPolyEdge& NextPortal, float& AngleBetweenBarriers, FVector& OutNewPathPoint, FColor ColourBarrier)
{
	FVector PreviousLocation = BarrierToUpdate.Right;
	FVector OtherBarrierVectorTo = OtherBarrier.GetVectorTo();
	FVector NewVectorTo1 = NextPortal.Left - BarrierToUpdate.Left;
	NewVectorTo1.Normalize();
	FVector NewVectorTo2 = NextPortal.Right - BarrierToUpdate.Left;
	NewVectorTo2.Normalize();

	float DotProduct1 = FVector::DotProduct(OtherBarrierVectorTo, NewVectorTo1);
	float DotProduct2 = FVector::DotProduct(OtherBarrierVectorTo, NewVectorTo2);

	if (DotProduct1 < DotProduct2)
	{
		BarrierToUpdate.Right = NextPortal.Left;
	}
	else
	{
		BarrierToUpdate.Right = NextPortal.Right;
	}

	//Calc new angle
	float newDotProduct = FVector::DotProduct(BarrierToUpdate.GetVectorTo(), OtherBarrier.GetVectorTo());

	FVector Intersect;
	FVector ExtendOtherBarrier = OtherBarrier.Left + (OtherBarrier.Right - OtherBarrier.Left) * 100.f;
	if (FindSegmentSegmentIntersection(PreviousLocation, BarrierToUpdate.Right, OtherBarrier.Left, ExtendOtherBarrier, Intersect))
	{
		OutNewPathPoint = OtherBarrier.Right;
		if (DrawDebug && !PathfindingAuto)
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

	if (DrawDebug && !PathfindingAuto)
	{
		DrawDebugLine(GetWorld(), BarrierToUpdate.Left, BarrierToUpdate.Right, ColourBarrier, true, 0, 10.f);
	}
	return false;
}

bool UMyJumpNavigationComponent::FindPointSegmentIntersection(const FVector Point, const FVector SegmentStart, const FVector SegmentEnd)
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

bool UMyJumpNavigationComponent::FindSegmentSegmentIntersection(const FVector Segment1Start, const FVector Segment1End, const FVector Segment2Start, const FVector Segment2End, FVector& IntersectionPoint)
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