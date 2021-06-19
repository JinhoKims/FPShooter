// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomHUDGameMode.h"
#include "CustomHUD.h"
#include "ScalingUIPlayerController.h"

ACustomHUDGameMode::ACustomHUDGameMode()
{
	HUDClass = AScalingUIPlayerController::StaticClass();
}

void ACustomHUDGameMode::BeginPlay()
{
	Super::BeginPlay();
	widget = SNew(SVerticalBox) // UI(버튼) 제작
		+ SVerticalBox::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(SButton).OnClicked(FOnClicked::CreateUObject(this, &ACustomHUDGameMode::ButtonClicked)).Content() // 버튼 생성 후 이벤트에 버튼클릭함수 바인딩
			[
				SAssignNew(ButtonLabel, STextBlock).Text(FText::FromString(TEXT("Click me!"))) // 버튼이 라벨(텍스트박스)주소를 포인터에 저장
			]
		];

	GEngine->GameViewport->AddViewportWidgetForPlayer(GetWorld()->GetFirstLocalPlayerFromController(), widget.ToSharedRef(), 1); // 뷰포트에 위젯을 출력
	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true; // 커서 활성화
	GEngine->GetFirstLocalPlayerController(GetWorld())->SetInputMode(FInputModeUIOnly().SetWidgetToFocus(widget)); // 플레이어 컨트롤러를 대상으로 입력모드를 마우스모드로 변경 


	//GetWorld()->GetTimerManager().SetTimer(HUDToggleTimer, FTimerDelegate::CreateLambda([this] // 타이머 델리게이트 설정
	//	{
	//		if (this->widget->GetVisibility().IsVisible()) // 현재 위젯의 상태에 따라
	//		{
	//			this->widget->SetVisibility(EVisibility::Hidden); // 활성화
	//		}
	//		else
	//		{
	//			this->widget->SetVisibility(EVisibility::Visible); // 비활성화
	//		}
	//	}), 5, true); // 5초 간격마다 반복 작동
}

void ACustomHUDGameMode::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	GetWorld()->GetTimerManager().ClearTimer(HUDToggleTimer); // 타이머 삭제
}

FReply ACustomHUDGameMode::ButtonClicked()
{
	ButtonLabel->SetText(FString(TEXT("Clicked!"))); // 텍스트 변경
	return FReply::Handled();
}