// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomHUD.h"
#include "CanvasItem.h"
#include "Engine/Canvas.h"


void ACustomHUD::DrawHUD()
{
	Super::DrawHUD();
	Canvas->DrawText(GEngine->GetSmallFont(), TEXT("Test string to be printed to screen"), 10, 10); // 텍스트 생성 (10초)
	
	FCanvasBoxItem ProgressBar(FVector2D(5, 25), FVector2D(100, 5)); // 프로그래스 바 생성 방법1(좌표, 길이)
	Canvas->DrawItem(ProgressBar); // 캔버스에 드로우
	
	DrawRect(FLinearColor::Blue, 5, 25, 100, 5); // 프로그래스 바 생성 방법2(색상, 좌표, 길이)
}
