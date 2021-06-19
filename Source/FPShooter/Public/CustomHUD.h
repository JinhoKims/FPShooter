// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CustomHUD.generated.h"

/**
 * 
 */

UCLASS()
class FPSHOOTER_API ACustomHUD : public AHUD // HUD 구현 클래스
{
	GENERATED_BODY()
	
public:
	virtual void DrawHUD() override;
};
