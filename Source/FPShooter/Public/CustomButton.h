// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class FPSHOOTER_API SCustomButton : public SCompoundWidget // S=Slate 커스텀 위젯 클래스
{
public:
	SLATE_BEGIN_ARGS(SCustomButton) : _Label(TEXT("Default Value")), _ButtonClicked() {} // Slate 메크로의 시작. 변수 및 함수 설정
	SLATE_ATTRIBUTE(FString, Label) // TAttribute<FString> 생성 이름(Label)
	SLATE_EVENT(FOnClicked, ButtonClicked) // 위젯 내부에 어떤 일이 일어날 때 브로드캐스팅 할 수 있다.
	SLATE_END_ARGS() // 메크로 끝

	void Construct(const FArguments& InArgs); // 위젯이 인스턴스화될 때 초기화되는 함수
	TAttribute<FString> Label; // TAttribute는 델리게이트와 비슷한데 <FString> 값을 반환하는 함수를 바인딩하여 이벤트 후 반환된 값을 저장하는 변수다.
	FOnClicked ButtonClicked; // 델리게이트 선언

};
