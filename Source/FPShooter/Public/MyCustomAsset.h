// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyCustomAsset.generated.h"

/**
 * 
 */
UCLASS()
class FPSHOOTER_API UMyCustomAsset : public UObject // 새 에셋 정의
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category = "Custom Asset")
	FString Name; // 에셋 이름

};