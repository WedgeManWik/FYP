// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "FYPPlayerController.generated.h"

/** Forward declaration to improve compiling times */
class UNiagaraSystem;

USTRUCT(BlueprintType)
struct FJumpPoint
{
	GENERATED_BODY()

		UPROPERTY(BlueprintReadOnly)
		FVector Left;
	UPROPERTY(BlueprintReadOnly)
		FVector Right;
};

USTRUCT(BlueprintType)
struct FCustomPathPoint
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
		FVector Location;
	UPROPERTY(BlueprintReadOnly)
		bool IsJumpPoint;
};

UCLASS()
class AFYPPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AFYPPlayerController();

	UFUNCTION(BlueprintImplementableEvent)
		void CustomJump(FVector LowerLocation, FVector UpperLocation);

	UFUNCTION(BlueprintImplementableEvent)
		void CustomGoingToNextPoint(FJumpPoint JumpLink);

	UFUNCTION(BlueprintImplementableEvent)
		void FindNavData();

	UFUNCTION(BlueprintCallable)
		void FindPath(ARecastNavMesh* Nav);

	UFUNCTION(BlueprintCallable)
		void GoToNextPointOnCustomPath();

	/** Time Threshold to know if it was a short press */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	float ShortPressThreshold;

	/** FX Class that we will spawn when clicking */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UNiagaraSystem* FXCursor;

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;
	
	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputAction* SetDestinationClickAction;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputAction* SetDestinationTouchAction;

protected:
	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;

	virtual void SetupInputComponent() override;
	
	// To add mapping context
	virtual void BeginPlay();

	/** Input handlers for SetDestination action. */
	void OnInputStarted();
	void OnSetDestinationTriggered();
	void OnSetDestinationReleased();
	void OnTouchTriggered();
	void OnTouchReleased();

	UFUNCTION(BlueprintCallable)
	FVector GetGoalDestination();

	void FollowCustomPath();

private:
	FVector CachedDestination;

	bool bIsTouch; // Is it a touch device
	float FollowTime; // For how long it has been pressed

	TArray<FCustomPathPoint> CustomPath;

	TArray<FJumpPoint> JumpPoints;

	int CurrentPathIndex;
};


