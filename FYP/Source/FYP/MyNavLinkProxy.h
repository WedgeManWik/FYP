// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Navigation/NavLinkProxy.h"
#include "MyNavLinkProxy.generated.h"

UCLASS()
class FYP_API AMyNavLinkProxy : public ANavLinkProxy
{
	GENERATED_BODY()

public:

	AMyNavLinkProxy();

	virtual void BeginPlay() override;

	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

	UFUNCTION(BlueprintCallable)
		void UpdateSmartLinkProperties();
	
};
