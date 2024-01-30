// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyJumpNavigationComponent.generated.h"

class ARecastNavMesh;

USTRUCT(BlueprintType)
struct FPathPoint
{
	GENERATED_BODY()

		UPROPERTY(BlueprintReadOnly)
		FVector Location;
	UPROPERTY(BlueprintReadOnly)
		bool IsJump;
};

USTRUCT(BlueprintType)
struct FMyPolyEdge
{
	GENERATED_BODY()

		UPROPERTY(BlueprintReadOnly)
		FVector Left;
	UPROPERTY(BlueprintReadOnly)
		FVector Right;
	UPROPERTY(BlueprintReadOnly)
		bool IsJumpEdge;

	FVector GetVectorTo()
	{
		FVector Direction = Right - Left;
		Direction.Normalize();
		return Direction;
	}
};

UCLASS(Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class FYP_API UMyJumpNavigationComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMyJumpNavigationComponent();

	UFUNCTION(BlueprintCallable)
		void Initialise(AController* Controller, APawn* Pawn);

	UFUNCTION(BlueprintCallable)
		void CreateCustomJumpPath(UPARAM(ref) const FVector& Start, UPARAM(ref) const FVector& Destination, UPARAM(ref) const bool& ShouldDrawDebug, UPARAM(ref) const bool& IsAutoPathfinding);

	UFUNCTION(BlueprintCallable)
		void FindPathPortals();

	UFUNCTION(BlueprintCallable)
		bool DoNextPathFindingStep();

	UFUNCTION(BlueprintCallable)
		void GoToNextPointOnCustomPath();

	UFUNCTION(BlueprintImplementableEvent)
		void CustomGoingToNextPoint(FPathPoint PathPoint);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	FMyPolyEdge GetEdgeClosestToPointOnPolygon(const FVector& Point, const TArray<FVector>& PolygonVerticies);

	FMyPolyEdge GetEdgeClosestToAnotherEdgeOnPolygon(const FMyPolyEdge& Edge, const TArray<FVector>& PolygonVerticies);

	void CreateCustomPath(const TArray<FMyPolyEdge>& Portals, FVector Start, FVector Destination);

	void CreatePathIn2D();

	void CreatePathIn3D();

	bool UpdateBarrier(FMyPolyEdge& BarrierToUpdate, FMyPolyEdge& OtherBarrier, const FMyPolyEdge& NextPortal, float& AngleBetweenBarriers, FVector& OutNewPathPoint, FColor ColourBarrier, bool& Parallel);

	bool FindPointSegmentIntersection(const FVector Point, const FVector SegmentStart, const FVector SegmentEnd);

	bool FindSegmentSegmentIntersection(const FVector Segment1Start, const FVector Segment1End, const FVector Segment2Start, const FVector Segment2End, FVector& IntersectionPoint);

	FVector StartOfPath;
	FVector FinalDestination;
	TArray<FPathPoint> AgentPathPoints;
	TArray<FMyPolyEdge> MyPortals3D;
	TArray<FMyPolyEdge> MyPortals2D;
	TArray<FVector> MyPathPoints2D;
	FMyPolyEdge Barrier1;
	FMyPolyEdge Barrier2;
	float Angle;
	bool DidStep2;
	bool PathComplete;
	bool PathfindingAuto;
	int CurrentPathIndex;
	int LineIndex;
	bool DrawDebug;

	ARecastNavMesh* Nav;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TObjectPtr<AController> MyController;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TObjectPtr<APawn> MyPawn;
};
