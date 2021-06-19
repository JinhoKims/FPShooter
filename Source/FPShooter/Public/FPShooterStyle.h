// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SlateBasics.h"
#include "SlateExtras.h"

/**
 * 
 */
class FPSHOOTER_API FPShooterStyle // 위젯의 스타일(색상,크기)을 정의할 수 있는 클래스
{
public:

	static void Initialize();
	static void ShutDown();
	static void ReloadTextures();
	static const ISlateStyle& Get();
	static FName GetStyleSetName();
	static TSharedRef<class FSlateStyleSet> Create(); // SlateStyle은 Slate 문법으로 스킨 위젯에 접근할 수 있는 여러 스타일을 가지고 있는 셋이다.
	static TSharedPtr<class FSlateStyleSet> FPShooterStyleInstance;

};
