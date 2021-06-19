// Fill out your copyright notice in the Description page of Project Settings.

#include "FPShooter.h"
#include "CustomButtonWidget.h"

TSharedRef<SWidget> UCustomButtonWidget::RebuildWidget()
{
	MyButton = SNew(SCustomButton).ButtonClicked(BIND_UOBJECT_DELEGATE(FOnClicked, OnButtonClicked)); // SCustomButton 클래스의 인스턴스를 구성하고 OnButtonClicked 델리게이트를 바인딩한다. 

	return MyButton.ToSharedRef(); // SWidget을 저장한 포인터를 반환한다.
}

UCustomButtonWidget::UCustomButtonWidget() :Label(TEXT("Default Value")) // 버튼의 기본 텍스트를 지정한다.
{
}

FReply UCustomButtonWidget::OnButtonClicked()
{
	ButtonClicked.Broadcast(); // 버튼 클릭 시 특별한 효과는 없다.
	return FReply::Handled();
}

void UCustomButtonWidget::SynchronizeProperties()
{
	Super::SynchronizeProperties();

	TAttribute<FString> LabelBinding = OPTIONAL_BINDING(FString, Label); // 핵심 사항이다. 블루프린트에서 생성된 UWidget 클래스의 Label 속성을 네이티브 버튼(SWidget)의 Label에 연결한다.
	MyButton->Label = LabelBinding; // OPTIONAL_BINDING 메크로는 두 번째 매개변수(Label)를 FString형으로 반환하며 바인딩할 수 있는 메크로다. 

	// 블루프린트에서 UWidget의 Label 값은 GetGameTimeInSeconds라는 노드의 리턴 값이 저장되기에 Label은 경과 시간을 저장하고 최종적으로 라벨에 경과 시간이 출력된다.
}
