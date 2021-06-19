// Fill out your copyright notice in the Description page of Project Settings.


#include "SlateHUDGameMode.h"
#include "CustomHUDPlayerController.h"

ASlateHUDGameMode::ASlateHUDGameMode() :Super()
{
	PlayerControllerClass = ACustomHUDPlayerController::StaticClass(); // 게임모드의 플레이어컨트롤러를 CustomHUD컨트롤러 클래스로 변경
}

