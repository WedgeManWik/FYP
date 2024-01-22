// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "FYPPlayerController.generated.h"

/** Forward declaration to improve compiling times */
class UNiagaraSystem;

UCLASS()
class AFYPPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AFYPPlayerController();

	UFUNCTION(BlueprintImplementableEvent)
		void DrawPath();

	UFUNCTION(BlueprintImplementableEvent)
		void FindNavData();

	UFUNCTION(BlueprintCallable)
		void FindPath(ARecastNavMesh* Nav);

	UFUNCTION(BlueprintImplementableEvent)
		void FollowPath(const TArray<FVector>& PathPoints);

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


	//STRING PULLING

	inline float triarea2(const float* a, const float* b, const float* c)
	{
		const float ax = b[0] - a[0];
		const float ay = b[1] - a[1];
		const float bx = c[0] - a[0];
		const float by = c[1] - a[1];
		return bx * ay - ax * by;
	}

	inline void vcpy(float line1[2], const float line2[2])
	{
		line1[0] = line2[0];
		line1[1] = line2[1];
	}

	inline bool vequal(const float* a, const float* b)
	{
		if (a == b)
		{
			return true;
		}
		return false;
	}

	int stringPull(const float* portals, int nportals, float* pts, const int maxPts);


private:
	FVector CachedDestination;

	bool bIsTouch; // Is it a touch device
	float FollowTime; // For how long it has been pressed
};


