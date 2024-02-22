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
		void TraceJumpAtEdge(FVector Start, FVector End, FVector Direction);

	UFUNCTION(BlueprintImplementableEvent)
		void TraceJumpAtCorner(FVector Location, FVector Direction1, FVector Direction2);

	UFUNCTION(BlueprintImplementableEvent)
		void FinishedGenerating();

	bool IsSameEdge(FNavigationPortalEdge& Edge1, FNavigationPortalEdge& Edge2);

	bool DoShareSameEdges(TArray<FNavigationPortalEdge>& EdgeArray1, TArray<FNavigationPortalEdge>& EdgeArray2);

	bool DoesEdgeShareNeighbour(FNavigationPortalEdge& Edge, TArray<NavNodeRef>& Neighbours, ARecastNavMesh* Nav);

	bool DoesAdjacentEdgeExist(FVector& Start, FVector& End, TArray<FNavigationPortalEdge>& EdgeArray);

	void SpawnPotentialNavLinksBetweenVerticies(FVector& Start, FVector& End);

	bool FindEdgeWithMatchingVertex(FNavigationPortalEdge& ThisEdge, FVector& Vertex, TArray<FNavigationPortalEdge>& EdgeArray, FNavigationPortalEdge& OutMatchingEdge);

	FVector GetDirecionOut(FVector& Start, FVector& End);

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool GenerateCornerLinks;

private:
	double startSeconds;
};
