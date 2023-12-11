// Fill out your copyright notice in the Description page of Project Settings.


#include "MyNavLinkGenerator.h"
#include "NavMesh/RecastNavMesh.h"
#include "Kismet/KismetSystemLibrary.h"

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
					FPotentialNavLinkSpawn PotentialNavLink = CreatePotentialNavLink(CurrentPolygonVertices[j], CurrentPolygonVertices[0]);
					SpawnPotentialNavLink(PotentialNavLink.Location, PotentialNavLink.Rotation);
					//PotentialNavLinkSpawns.Add(CreatePotentialNavLink(CurrentPolygonVertices[j], CurrentPolygonVertices[0]));
				}
			}
			else
			{
				if (!DoesAdjacentEdgeExist(CurrentPolygonVertices[j], CurrentPolygonVertices[j + 1], CurrentPolygonEdges))
				{
					FPotentialNavLinkSpawn PotentialNavLink = CreatePotentialNavLink(CurrentPolygonVertices[j], CurrentPolygonVertices[j+1]);
					SpawnPotentialNavLink(PotentialNavLink.Location, PotentialNavLink.Rotation);
					//PotentialNavLinkSpawns.Add(CreatePotentialNavLink(CurrentPolygonVertices[j], CurrentPolygonVertices[j + 1]));
				}
			}
		}

	}

	for (int i = 0; i < PotentialNavLinkSpawns.Num(); i++)
	{
		FVector EndLoc = PotentialNavLinkSpawns[i].Location + (PotentialNavLinkSpawns[i].Rotation);
		EndLoc.Z -= 200;
		SpawnNavLinkBetweenVerticies(PotentialNavLinkSpawns[i].Location, EndLoc);
		SpawnNavLink(PotentialNavLinkSpawns[i].Location, EndLoc);
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

void AMyNavLinkGenerator::SpawnNavLinkBetweenVerticies(FVector& Start, FVector& End)
{
	UWorld* const world = GetWorld();
	if (world == nullptr) { return; }

	FHitResult hit(ForceInit);
	TArray<AActor*> ActorsToIgnore;
	UKismetSystemLibrary::LineTraceSingle(world, Start, End,
		UEngineTypes::ConvertToTraceType(ECC_GameTraceChannel2), false, ActorsToIgnore,
		EDrawDebugTrace::Persistent, hit, true, FLinearColor::Red, FLinearColor::Red, 200);

	//double MidX = (Start.X + End.X) / 2.0f;
	//double MidY = (Start.Y + End.Y) / 2.0f;
	//double MidZ = (Start.Z + End.Z) / 2.0f;

	//FVector Location(MidX, MidY, MidZ);
	//FRotator Rotation(0.0f, 0.0f, 0.0f);


	//FActorSpawnParameters SpawnInfo;
	//SpawnInfo.Owner = GetOwner();
	//SpawnInfo.Instigator = GetInstigator();
	//SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	//GetWorld()->SpawnActor<AActor>(_NavLink, Location, Rotation, SpawnInfo);
}

FPotentialNavLinkSpawn AMyNavLinkGenerator::CreatePotentialNavLink(FVector& Start, FVector& End)
{
	double MidX = (Start.X + End.X) / 2.0f;
	double MidY = (Start.Y + End.Y) / 2.0f;
	double MidZ = (Start.Z + End.Z) / 2.0f;

	FVector ThisEdge = Start - End;

	FVector Location(MidX, MidY, MidZ);
	FVector DirectionOut = FVector::CrossProduct(ThisEdge, FVector(0, 0, 1));
	DirectionOut.Normalize();
	DirectionOut *= 100;

	return FPotentialNavLinkSpawn(Location, DirectionOut);
}
