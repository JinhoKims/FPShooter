// Fill out your copyright notice in the Description page of Project Settings.

#include "AtributeGameMode.h"

void AAtributeGameMode::BeginPlay()
{
	Super::BeginPlay();
	Widget = SNew(SVerticalBox) // 위젯 생성 후 포인터에 저장
		+ SVerticalBox::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(SButton)
			.Content()
		[
			SNew(STextBlock)
			.Text(TAttribute<FText>::Create(TAttribute<FText>::FGetter::CreateUObject(this, &AAtributeGameMode::GetButtonLabel))) // 버튼 라벨(텍스트)에 함수 바인딩
			// FGetter를 통해 GetButtonLabel의 반환 값을 라벨에 출력한다.
		]
		];

	GEngine->GameViewport->AddViewportWidgetForPlayer(GetWorld()->GetFirstLocalPlayerFromController(), Widget.ToSharedRef(), 1); // 화면에 위젯 출력
}

FText AAtributeGameMode::GetButtonLabel() const
{
	FVector ActorLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation(); // 현재 위치 저장
	
	return FText::FromString(FString::Printf(TEXT("%f, %f, %f"), ActorLocation.X, ActorLocation.Y, ActorLocation.Z)); // 저장한 위치를 텍스트로 반환 
}
