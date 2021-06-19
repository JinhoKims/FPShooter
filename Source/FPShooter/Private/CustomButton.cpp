// Fill out your copyright notice in the Description page of Project Settings.

#include "FPShooter.h"
#include "CustomButton.h"

void SCustomButton::Construct(const FArguments& InArgs) // 인스턴스화 될 시 호출 함수
{
	Label = InArgs._Label;
	ButtonClicked = InArgs._ButtonClicked; // 멤버에 인자 전달
	ChildSlot.VAlign(VAlign_Center).HAlign(HAlign_Center) // 하위 계층으로 위젯 생성
		[
			SNew(SButton).OnClicked(ButtonClicked).Content() // 버튼도 생성
			[
				SNew(STextBlock).Text_Lambda([this] { return FText::FromString(Label.Get()); }) // 버튼의 라벨(텍스트)는 람다를 사용해 Label이 반환한 값으로 설정 (Label은 이벤트 후 반환된 값을 가지는 델리게이트다.)
			]
		];
}