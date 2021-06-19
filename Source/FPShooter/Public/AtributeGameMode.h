// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "AtributeGameMode.generated.h"

/**
 * 
 */
UCLASS()
class FPSHOOTER_API AAtributeGameMode : public AGameMode
{
	GENERATED_BODY()
	
private:
	TSharedPtr<SVerticalBox> Widget;

public:
	virtual void BeginPlay() override;
	FText GetButtonLabel() const;
};
