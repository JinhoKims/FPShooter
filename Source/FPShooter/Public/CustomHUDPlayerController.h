// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CustomHUDPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class FPSHOOTER_API ACustomHUDPlayerController : public APlayerController // HUD 기능을 추가한 플레이어 컨트롤러
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
};
