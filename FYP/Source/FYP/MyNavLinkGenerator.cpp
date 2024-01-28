// Fill out your copyright notice in the Description page of Project Settings.


#include "MyNavLinkGenerator.h"
#include "NavMesh/RecastNavMesh.h"
#include "Kismet/KismetSystemLibrary.h"
#include "NavigationSystem.h"

// Sets default values
AMyNavLinkGenerator::AMyNavLinkGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void AMyNavLinkGenerator::GenerateNavMeshLinks(ARecastNavMesh* Nav)
{
	TArray<NavNodeRef> PolyRefs;

	int32 NumTiles = Nav->GetNavMeshTilesCount();

	TArray<FNavPoly> EachPolys;

	FBox TileBounds;

	for (int i = 0; i < NumTiles; i++)
	{
		TileBounds = Nav->GetNavMeshTileBounds(i);
		if (TileBounds.IsValid == 0) { continue; }
		Nav->GetPolysInTile(i, EachPolys);

		if (EachPolys.Num() > 0)
		{
			for (int j = 0; j < EachPolys.Num(); j++)
			{
				PolyRefs.Add(EachPolys[j].Ref);
			}
		}

	}

	//ANavigationData* Data = UNavigationSystemV1::GetNavDataForProps(Controller->GetNavAgentPropertiesRef())

	TArray<FNavigationPortalEdge> NavMeshEdges;

	for (int i = 0; i < EachPolys.Num(); i++)
	{
		//Get all edges of current polygon
		TArray<FNavigationPortalEdge> CurrentPolygonEdges;
		Nav->GetPolyEdges(EachPolys[i].Ref, CurrentPolygonEdges);

		//Get all vertices of current polygon
		TArray<FVector> CurrentPolygonVertices;
		Nav->GetPolyVerts(EachPolys[i].Ref, CurrentPolygonVertices);

		//Spawns potential nav links on edges of navmesh
		for (int j = 0; j < CurrentPolygonVertices.Num(); j++)
		{
			if (j == CurrentPolygonVertices.Num() - 1)
			{
				if (!DoesAdjacentEdgeExist(CurrentPolygonVertices[j], CurrentPolygonVertices[0], CurrentPolygonEdges))
				{
					//SpawnPotentialNavLinksBetweenVerticies(CurrentPolygonVertices[j], CurrentPolygonVertices[0]);
					//NavMeshEdges.Add(FNavigationPortalEdge(CurrentPolygonVertices[j], CurrentPolygonVertices[0], EachPolys[i].Ref));
					SpawnNavJumpLinkArea(CurrentPolygonVertices[j], CurrentPolygonVertices[0], GetDirecionOut(CurrentPolygonVertices[j], CurrentPolygonVertices[0]));
				}
			}
			else
			{
				if (!DoesAdjacentEdgeExist(CurrentPolygonVertices[j], CurrentPolygonVertices[j + 1], CurrentPolygonEdges))
				{
					//SpawnPotentialNavLinksBetweenVerticies(CurrentPolygonVertices[j], CurrentPolygonVertices[j + 1]);
					//NavMeshEdges.Add(FNavigationPortalEdge(CurrentPolygonVertices[j], CurrentPolygonVertices[j + 1], EachPolys[i].Ref));
					SpawnNavJumpLinkArea(CurrentPolygonVertices[j], CurrentPolygonVertices[j + 1], GetDirecionOut(CurrentPolygonVertices[j], CurrentPolygonVertices[j + 1]));
				}
			}
		}
	}

	//Spawns Potential nav links on corners of navmesh

	//for (int i = 0; i < NavMeshEdges.Num(); i++)
	//{
	//	FNavigationPortalEdge MatchingEdge = FindEdgeWithMatchingVertex(NavMeshEdges[i], NavMeshEdges[i].Left, NavMeshEdges);

	//	FVector Direction1 = NavMeshEdges[i].Left - NavMeshEdges[i].Right;
	//	FVector Direction2 = MatchingEdge.Right == NavMeshEdges[i].Left ? MatchingEdge.Right - MatchingEdge.Left : MatchingEdge.Left - MatchingEdge.Right;
	//	Direction1.Normalize();
	//	Direction2.Normalize();
	//	
	//	float DotProd = FVector::DotProduct(Direction1, Direction2);

	//	int numPotentialNavLinksToSpawn = DotProd >= 0.0f ? FMath::Floor((1 - DotProd) / 0.3f) : FMath::Floor((1 + (DotProd * -1)) / 0.3f);

	//	UWorld* const world = GetWorld();
	//	if (world == nullptr || numPotentialNavLinksToSpawn <= 0) { return; }
	//	
	//	for (int j = 0; j < numPotentialNavLinksToSpawn; j++)
	//	{
	//		//FVector End = NavMeshEdges[i].Left + Direction1.RotateAngleAxis(-27 * j, FVector(0, 0, 1));

	//		//FHitResult hit(ForceInit);
	//		//TArray<AActor*> ActorsToIgnore;
	//		//UKismetSystemLibrary::LineTraceSingle(world, NavMeshEdges[i].Left, End,
	//		//	UEngineTypes::ConvertToTraceType(ECC_GameTraceChannel2), false, ActorsToIgnore,
	//		//	EDrawDebugTrace::Persistent, hit, true, FLinearColor::Red, FLinearColor::Red, 200);

	//		SpawnPotentialNavLink(NavMeshEdges[i].Left, Direction1.RotateAngleAxis(-27 * j, FVector(0, 0, 1)));
	//	}
	//}
}

bool AMyNavLinkGenerator::IsSameEdge(FNavigationPortalEdge& Edge1, FNavigationPortalEdge& Edge2)
{
	if (Edge1.Left == Edge2.Left || Edge1.Left == Edge2.Right)
	{
		if (Edge1.Right == Edge2.Left || Edge1.Right == Edge2.Right)
		{
			return true;
		}
	}
	return false;
}

bool AMyNavLinkGenerator::DoShareSameEdges(TArray<FNavigationPortalEdge>& EdgeArray1, TArray<FNavigationPortalEdge>& EdgeArray2)
{
	for (int i = 0; i < EdgeArray1.Num(); i++)
	{
		for (int j = 0; j < EdgeArray2.Num(); j++)
		{
			if (IsSameEdge(EdgeArray1[i], EdgeArray2[j]))
			{
				return true;
			}
		}
	}
	return false;
}

bool AMyNavLinkGenerator::DoesEdgeShareNeighbour(FNavigationPortalEdge& Edge, TArray<NavNodeRef>& Neighbours, ARecastNavMesh* Nav)
{
	for (int i = 0; i < Neighbours.Num(); i++)
	{
		TArray<FNavigationPortalEdge> Edges;
		Nav->GetPolyEdges(Neighbours[i], Edges);

		for (int j = 0; j < Edges.Num(); j++)
		{
			if (IsSameEdge(Edge, Edges[j]))
			{
				return true;
			}
		}
	}

	return false;
}

bool AMyNavLinkGenerator::DoesAdjacentEdgeExist(FVector& Start, FVector& End, TArray<FNavigationPortalEdge>& EdgeArray)
{
	for (int i = 0; i < EdgeArray.Num(); i++)
	{
		if (EdgeArray[i].Left == Start || EdgeArray[i].Right == End)
		{
			if (EdgeArray[i].Right == Start || EdgeArray[i].Right == End)
			{
				return true;
			}
		}
	}
	return false;
}

void AMyNavLinkGenerator::SpawnPotentialNavLinksBetweenVerticies(FVector& Start, FVector& End)
{
	int32 TotalDistance = FVector::Dist(Start,End);
	int32 EdgeDistances = (TotalDistance % 100) / 2;
	int32 numPotentialLinksToSpawn = (TotalDistance - (EdgeDistances * 2)) / 100;

	FVector Direction = End - Start;
	Direction.Normalize();

	FVector DirectionOut = FVector::CrossProduct(Direction, FVector(0, 0, 1));
	DirectionOut.Normalize();
	DirectionOut *= -1;

	FVector FirstPotentialNavLink = Start + Direction * EdgeDistances;
	SpawnPotentialNavLink(FirstPotentialNavLink, DirectionOut);

	for (int i = 0; i < numPotentialLinksToSpawn; i++)
	{
		FVector SpawnLocation = Start + (Direction * (EdgeDistances + 100 * i));
		SpawnPotentialNavLink(SpawnLocation, DirectionOut);
	}

	FVector LastPotentialNavLink = End - (Direction * EdgeDistances);
	SpawnPotentialNavLink(LastPotentialNavLink, DirectionOut);
}

FNavigationPortalEdge& AMyNavLinkGenerator::FindEdgeWithMatchingVertex(FNavigationPortalEdge& ThisEdge, FVector& Vertex, TArray<FNavigationPortalEdge>& EdgeArray)
{
	for (int i = 0; i < EdgeArray.Num(); i++)
	{
		if (EdgeArray[i].Left == Vertex || EdgeArray[i].Right == Vertex)
		{
			if (EdgeArray[i].Left == ThisEdge.Left && EdgeArray[i].Right == ThisEdge.Right)
			{
				//Same edge
			}
			else
			{
				return EdgeArray[i];
			}
		}
	}

	return ThisEdge;
}

FVector AMyNavLinkGenerator::GetDirecionOut(FVector& Start, FVector& End)
{
	int32 TotalDistance = FVector::Dist(Start, End);
	int32 EdgeDistances = (TotalDistance % 100) / 2;

	FVector Direction = End - Start;
	Direction.Normalize();

	FVector DirectionOut = FVector::CrossProduct(Direction, FVector(0, 0, 1));
	DirectionOut.Normalize();
	DirectionOut *= -1;

	return DirectionOut;
}
