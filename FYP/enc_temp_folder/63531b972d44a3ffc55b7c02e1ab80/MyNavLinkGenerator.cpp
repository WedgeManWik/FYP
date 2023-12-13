// Fill out your copyright notice in the Description page of Project Settings.


#include "MyNavLinkGenerator.h"
#include "NavMesh/RecastNavMesh.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
AMyNavLinkGenerator::AMyNavLinkGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	DistBetweenNavLinks = 100;
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

	TArray<FPotentialNavLinkSpawn> PotentialNavLinkSpawns;

	for (int i = 0; i < EachPolys.Num(); i++)
	{
		//Get all edges of current polygon
		TArray<FNavigationPortalEdge> CurrentPolygonEdges;
		Nav->GetPolyEdges(EachPolys[i].Ref, CurrentPolygonEdges);

		//Get all vertices of current polygon
		TArray<FVector> CurrentPolygonVertices;
		Nav->GetPolyVerts(EachPolys[i].Ref, CurrentPolygonVertices);

		for (int j = 0; j < CurrentPolygonVertices.Num(); j++)
		{
			if (j == CurrentPolygonVertices.Num() - 1)
			{
				if (!DoesAdjacentEdgeExist(CurrentPolygonVertices[j], CurrentPolygonVertices[0], CurrentPolygonEdges))
				{
					SpawnPotentialNavLinksBetweenVerticies(CurrentPolygonVertices[j], CurrentPolygonVertices[0]);
					SpawnPotentialNavLinksOnVertex(CurrentPolygonVertices[j], CurrentPolygonVertices[j - 1], CurrentPolygonVertices[0]);
				}
			}
			else
			{
				if (j == 0)
				{
					SpawnPotentialNavLinksOnVertex(CurrentPolygonVertices[j], CurrentPolygonVertices[CurrentPolygonVertices.Num() - 1], CurrentPolygonVertices[1]);
				}
				else if (!DoesAdjacentEdgeExist(CurrentPolygonVertices[j], CurrentPolygonVertices[j + 1], CurrentPolygonEdges))
				{
					SpawnPotentialNavLinksBetweenVerticies(CurrentPolygonVertices[j], CurrentPolygonVertices[j + 1]);
					SpawnPotentialNavLinksOnVertex(CurrentPolygonVertices[j], CurrentPolygonVertices[j - 1], CurrentPolygonVertices[j + 1]);
				}
			}
		}

	}
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
	int32 EdgeDistances = (TotalDistance % DistBetweenNavLinks) / 2;
	int32 numPotentialLinksToSpawn = (TotalDistance - (EdgeDistances * 2)) / DistBetweenNavLinks;

	FVector Direction = End - Start;
	Direction.Normalize();

	FVector DirectionOut = FVector::CrossProduct(Direction, FVector(0, 0, 1));
	DirectionOut.Normalize();
	DirectionOut *= -1;

	FVector FirstPotentialNavLink = Start + Direction * EdgeDistances;
	SpawnPotentialNavLink(FirstPotentialNavLink, DirectionOut);

	for (int i = 0; i < numPotentialLinksToSpawn; i++)
	{
		FVector SpawnLocation = Start + (Direction * (EdgeDistances + DistBetweenNavLinks * i));
		SpawnPotentialNavLink(SpawnLocation, DirectionOut);
	}

	FVector LastPotentialNavLink = End - (Direction * EdgeDistances);
	SpawnPotentialNavLink(LastPotentialNavLink, DirectionOut);
}

void AMyNavLinkGenerator::SpawnPotentialNavLinksOnVertex(FVector& VertexLocation, FVector& Neighbour1, FVector& Neighbour2)
{
	FVector Direction1 = VertexLocation - Neighbour1;
	FVector Direction2 = VertexLocation - Neighbour2;
	Direction1.Normalize();
	Direction2.Normalize();

	float Angle = FVector::DotProduct(Direction2, Direction1);

	UWorld* const world = GetWorld();
	if (world == nullptr) { return; }

	FVector Direction = Neighbour1.RotateAngleAxis(Angle * -0.5f, FVector(0, 0, 1));
	Direction.Normalize();

	//SpawnPotentialNavLink(VertexLocation, Direction);

	FVector End1 = VertexLocation + (Direction1 * 50);
	FVector End2 = VertexLocation + (Direction2 * 50);

	FHitResult hit(ForceInit);
	TArray<AActor*> ActorsToIgnore;
	UKismetSystemLibrary::LineTraceSingle(world, VertexLocation, End1,
		UEngineTypes::ConvertToTraceType(ECC_GameTraceChannel2), false, ActorsToIgnore,
		EDrawDebugTrace::Persistent, hit, true, FLinearColor::Red, FLinearColor::Red, 200);

	UKismetSystemLibrary::LineTraceSingle(world, VertexLocation, End2,
		UEngineTypes::ConvertToTraceType(ECC_GameTraceChannel2), false, ActorsToIgnore,
		EDrawDebugTrace::Persistent, hit, true, FLinearColor::Red, FLinearColor::Red, 200);

	//int32 numPotentialNavLinksToSpawn = FMath::Floor(Angle / 0.1f);

	//UWorld* const world = GetWorld();
	//if (world == nullptr) { return; }

	//FHitResult hit(ForceInit);
	//TArray<AActor*> ActorsToIgnore;
	//for (int i = 0; i < numPotentialNavLinksToSpawn; i++)
	//{
		//FVector Direction = Neighbour1.RotateAngleAxis(9, FVector(0, 0, 1));
		////SpawnPotentialNavLink(VertexLocation, Direction);

		//FVector End = VertexLocation + (Direction * 50);

		//UKismetSystemLibrary::LineTraceSingle(world, VertexLocation, End,
		//	UEngineTypes::ConvertToTraceType(ECC_GameTraceChannel2), false, ActorsToIgnore,
		//	EDrawDebugTrace::Persistent, hit, true, FLinearColor::Red, FLinearColor::Red, 200);
	//}
}
