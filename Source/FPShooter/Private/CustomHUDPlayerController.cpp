// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomHUDPlayerController.h"

void ACustomHUDPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// SNew를 통하여 버튼 위젯 디자인
	TSharedRef<SVerticalBox> widget = SNew(SVerticalBox) + SVerticalBox::Slot().HAlign(HAlign_Center).VAlign(VAlign_Center)[SNew(SButton).Content()[SNew(STextBlock).Text(FText::FromString(TEXT("Test button")))]];
	GEngine->GameViewport->AddViewportWidgetForPlayer(GetLocalPlayer(), widget, 1); // 뷰포트에 위젯 출력
}
