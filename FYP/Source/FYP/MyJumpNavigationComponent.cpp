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
	PrimaryComponentTick.bCanEverTick = false;
	PathfindingAuto = true;
}

void UMyJumpNavigationComponent::Initialise(AController* Controller, AActor* Pawn)
{
	MyController = Controller;
	MyPawn = Pawn;
}

void UMyJumpNavigationComponent::BeginPlay()
{
	Nav = Cast<ARecastNavMesh>(UGameplayStatics::GetActorOfClass(GetWorld(), ARecastNavMesh::StaticClass()));
}

void UMyJumpNavigationComponent::CreateCustomJumpPath(const FVector& Start, const FVector& Destination)
{
	StartOfPath = Start;
	FinalDestination = Destination;

	FindPathPortals();
}

void UMyJumpNavigationComponent::FindPathPortals()
{
	UNavigationSystemV1* NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
	AActor* ControlledPawn = GetOwner();
	UNavigationPath* path = NavSys->FindPathToLocationSynchronously(this, StartOfPath, FinalDestination, ControlledPawn);

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

			if (!PathfindingAuto)
			{
				for (int j = 1; j < CurrentPolygonVertices.Num(); j++)
				{
					DrawDebugLine(GetWorld(), CurrentPolygonVertices[j], CurrentPolygonVertices[j - 1], FColor(0, 255, 0), true, 0, 5.f);
				}
				DrawDebugLine(GetWorld(), CurrentPolygonVertices[0], CurrentPolygonVertices[CurrentPolygonVertices.Num() - 1], FColor(0, 255, 0), true, 0, 5.f);

				DrawDebugSphere(GetWorld(), pathpoints[i], 5.f, 5, FColor(255, 0, 255), true, 0, 5.f);
			}

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
					//NEIGHBOUR 1 IS ALWAYS TOP, NEIGHBOUR 0 IS ALWAYS BOTTOM
					//DrawDebugSphere(GetWorld(), CurrentPolygonVertices[0], 5.f, 5, FColor(255, 255, 255), true, 0, 10.f);
					//DrawDebugSphere(GetWorld(), CurrentPolygonVertices[1], 5.f, 5, FColor(0, 0, 0), true, 0, 10.f);

					TArray<NavNodeRef> Neighbours;
					Nav->GetPolyNeighbors(nodeRef, Neighbours);

					TArray<FVector> BottomPolygonVertices;
					Nav->GetPolyVerts(Neighbours[0], BottomPolygonVertices);
					TArray<FVector> TopPolygonVertices;
					Nav->GetPolyVerts(Neighbours[1], TopPolygonVertices);

					//NEXT POLYGON
					//NavNodeRef nextNodeRef = pathpoints[i + 1].NodeRef;
					//TArray<FVector> NextPolygonVertices;
					//Nav->GetPolyVerts(nextNodeRef, NextPolygonVertices);

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
				}
			}
		}
	}
	if (!PathfindingAuto)
	{
		DrawDebugLine(GetWorld(), Portals[0].Left, Portals[0].Right, FColor(255, 0, 0), true, 0, 10.f);
		for (int i = 1; i < Portals.Num(); i++)
		{
			DrawDebugLine(GetWorld(), Portals[i].Left, Portals[i].Right, FColor(255, 0, 0), true, 0, 10.f);
			if (Portals[i].IsJumpEdge)
			{
				DrawDebugLine(GetWorld(), Portals[i].Left, Portals[i].Right, FColor(255, 255, 255), true, 0, 10.f);
				DrawDebugLine(GetWorld(), Portals[i - 1].Left, Portals[i - 1].Right, FColor(0, 0, 0), true, 0, 10.f);
			}
		}
	}
	CreateCustomPath(Portals, ControlledPawn->GetActorLocation(), FinalDestination);
}

void UMyJumpNavigationComponent::SwitchPathfindMode()
{
	PathfindingAuto = !PathfindingAuto;
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

FMyPolyEdge UMyJumpNavigationComponent::GetEdgeClosestToAnotherEdgeOnPolygon(const FMyPolyEdge& Edge, const TArray<FVector>& PolygonVerticies)
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

void UMyJumpNavigationComponent::CreateCustomPath(const TArray<FMyPolyEdge>& Portals, FVector Start, FVector Destination)
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
			CreatePathIn2D();
		}
		PathComplete = false;
		CurrentPathIndex = 0;
		LineIndex = 0;
		while (!PathComplete)
		{
			CreatePathIn3D();
		}

		FPathPoint finalPathPoint;
		finalPathPoint.Location = Destination;
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

void UMyJumpNavigationComponent::CreatePathIn2D()
{
	FVector NewPathPoint;
	bool IsParallel = false;
	if (DidStep2)
	{
		CurrentPathIndex++;
		if (CurrentPathIndex >= MyPortals.Num())
		{
			FVector End = FinalDestination;
			End.Z = 0;
			MyPathPoints.Add(End);
			PathComplete = true;

			if (!PathfindingAuto)
			{
				DrawDebugSphere(GetWorld(), End, 5.f, 5, FColor(255, 0, 0), true, 0, 5.f);

				LineIndex = 0;
				CurrentPathIndex = 0;
				CreatePathIn3D();
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

void UMyJumpNavigationComponent::CreatePathIn3D()
{
}

bool UMyJumpNavigationComponent::UpdateBarrier(FMyPolyEdge& BarrierToUpdate, FMyPolyEdge& OtherBarrier, const FMyPolyEdge& NextPortal, float& AngleBetweenBarriers, FVector& OutNewPathPoint, FColor ColourBarrier, bool& Parallel)
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
