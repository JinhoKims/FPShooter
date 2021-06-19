// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "CustomHUDGameMode.generated.h"

/**
 * 
 */
UCLASS()
class FPSHOOTER_API ACustomHUDGameMode : public AGameMode // HUD 클래스를 모드에 넣기 위한 게임모드
{
	GENERATED_BODY()

public:
	ACustomHUDGameMode();
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY()
	FTimerHandle HUDToggleTimer; // 타이머핸들

	FReply ButtonClicked(); 

private:
	TSharedPtr<SVerticalBox> widget; // 위젯(버튼) 포인터
	TSharedPtr<STextBlock> ButtonLabel; // 버튼의 라벨(텍스트박스)을 가리키는 포인터
	
};
