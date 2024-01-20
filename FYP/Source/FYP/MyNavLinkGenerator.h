// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyNavLinkGenerator.generated.h"

class ARecastNavMesh;

UCLASS()
class FYP_API AMyNavLinkGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	AMyNavLinkGenerator();

	UFUNCTION(BlueprintCallable)
		void GenerateNavMeshLinks(ARecastNavMesh* Nav);

	UFUNCTION(BlueprintImplementableEvent)
		void SpawnPotentialNavLink(FVector Location, FVector Direction);

	UFUNCTION(BlueprintImplementableEvent)
		void SpawnNavJumpLinkArea(FVector Start, FVector End, FVector Direction);

	bool IsSameEdge(FNavigationPortalEdge& Edge1, FNavigationPortalEdge& Edge2);

	bool DoShareSameEdges(TArray<FNavigationPortalEdge>& EdgeArray1, TArray<FNavigationPortalEdge>& EdgeArray2);

	bool DoesEdgeShareNeighbour(FNavigationPortalEdge& Edge, TArray<NavNodeRef>& Neighbours, ARecastNavMesh* Nav);

	bool DoesAdjacentEdgeExist(FVector& Start, FVector& End, TArray<FNavigationPortalEdge>& EdgeArray);

	void SpawnPotentialNavLinksBetweenVerticies(FVector& Start, FVector& End);

	FNavigationPortalEdge& FindEdgeWithMatchingVertex(FNavigationPortalEdge& ThisEdge, FVector& Vertex, TArray<FNavigationPortalEdge>& EdgeArray);

	FVector GetDirecionOut(FVector& Start, FVector& End);

	UPROPERTY(EditAnywhere)
		int32 AgentJumpHeight;

	UPROPERTY(EditAnywhere)
		int32 AgentJumpDistance;

	UPROPERTY(EditAnywhere)
		int32 DistBetweenNavLinks;
};
