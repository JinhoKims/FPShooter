// Fill out your copyright notice in the Description page of Project Settings.


#include "FPShooterCommands.h"



void FPShooterCommands::RegisterCommands()
{
	#define LOCTEXT_NAMESPACE ""
	UI_COMMAND(MyButton, "Cookbook", "Demo Cookbook Toolbar Command", EUserInterfaceActionType::Button, FInputGesture()); // 생성할 버튼(MyButton)에 명령을 기입한다.
	#undef LOCTEXT_NAMESPACE
}
