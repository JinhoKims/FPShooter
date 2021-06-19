// Fill out your copyright notice in the Description page of Project Settings.

#include "StyledHUDGameMode.h"
#include "FPShooter.h"
#include "FPShooterStyle.h"

void AStyledHUDGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	Hudwidget = SNew(SVerticalBox) + SVerticalBox::Slot().HAlign(HAlign_Center).VAlign(VAlign_Center) // SNew 메크로를 사용해 VerticalBox을 생성한다. VerticlaBox은 위젯을 수직으로 배열하는 컨테이너(도화지)다.
		[
			SNew(SButton).ButtonStyle(FPShooterStyle::Get(), "NormalButtonBrush").ContentPadding(FMargin(16)).Content() // 컨테이너(도화지)에 버튼을 생성하고 미리 생성한 사용자 정의 "NormalButtonBrush" 스타일을 적용한다. Get()으로 스타일 객체를 가져왔다.
			[
				SNew(STextBlock).TextStyle(FPShooterStyle::Get(), "NormalButtonText").Text(FText::FromString("Styled Button")) // 버튼의 라벨(텍스트)블록을 생성하고 라벨에 스타일과 텍스트 내용을 적용한다.
			]
		];
		
	GEngine->GameViewport->AddViewportWidgetForPlayer(GetWorld()->GetFirstLocalPlayerFromController(), Hudwidget.ToSharedRef(), 1); // 생성한 위젯을 뷰포트에 출력한다.
}
