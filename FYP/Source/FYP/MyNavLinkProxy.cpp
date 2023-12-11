
// Fill out your copyright notice in the Description page of Project Settings.

#include "MyNavLinkProxy.h"
#include "NavLinkCustomComponent.h"

AMyNavLinkProxy::AMyNavLinkProxy()
{

}

void AMyNavLinkProxy::BeginPlay()
{
	if (PointLinks.Num() == 1)
	{
		bSmartLinkIsRelevant = true;
		GetSmartLinkComp()->SetEnabledArea(PointLinks[0].GetAreaClass());
		PointLinks.Empty();
		GetSmartLinkComp()->SetNavigationRelevancy(bSmartLinkIsRelevant);
	}
}

void AMyNavLinkProxy::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	if (PointLinks.Num() == 1)
	{
		GetSmartLinkComp()->SetLinkData(PointLinks[0].Left, PointLinks[0].Right, PointLinks[0].Direction);
	}

	Super::PostEditChangeProperty(PropertyChangedEvent);
}

void AMyNavLinkProxy::UpdateSmartLinkProperties()
{
	if (PointLinks.Num() == 1)
	{
		GetSmartLinkComp()->SetLinkData(PointLinks[0].Left, PointLinks[0].Right, PointLinks[0].Direction);
	}
}
