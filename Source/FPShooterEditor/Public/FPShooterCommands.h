// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EditorStyleSet.h"

/**
 * 
 */
class FPSHOOTEREDITOR_API FPShooterCommands : public TCommands<FPShooterCommands> // 에디터에 생성할 버튼과 엔진을 연결하기 위한 명령(UI 제어) 클래스 
																				  // 언리얼 에디터 UI는 명령의 개념을 기반으로 작동된다. 명령은 에디터 UI와 수행해야 할 작업(함수) 간의 느슨한 결합을 허용하는 디자인 패턴이다.
{			
public:
	FPShooterCommands() :TCommands(FName(TEXT("UE4_Cookbook")), FText::FromString("Cookbook Commands"), NAME_None, FEditorStyle::GetStyleSetName()) {}
	virtual void RegisterCommands() override;  // 명령 객체를 만드는 데 필요한 TCommands 파생 클래스를 허용한다.
	TSharedPtr<FUICommandInfo> MyButton; // FUICommandInfo 클래스로 UI 버튼이 브로드캐스팅하는 함수를 명령(UI)에 바인딩할 수 있다.
};
