// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "StyledHUDGameMode.generated.h"

/**
 * 
 */
UCLASS()
class FPSHOOTER_API AStyledHUDGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:
	TSharedPtr<SVerticalBox> Hudwidget;

	virtual void BeginPlay() override;
};
