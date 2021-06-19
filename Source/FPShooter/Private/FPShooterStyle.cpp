// Fill out your copyright notice in the Description page of Project Settings.


#include "FPShooterStyle.h"
#include "FPShooter.h"
#include "Slate/SlateGameResources.h"

TSharedPtr<FSlateStyleSet>FPShooterStyle::FPShooterStyleInstance = NULL;

void FPShooterStyle::Initialize() // 모듈 로드 시 초기화 함수
{
	if (!FPShooterStyleInstance.IsValid())
	{
		FPShooterStyleInstance = Create(); // Create 멤버함수를 호출하여 Style 객체를 인스턴스화
		FSlateStyleRegistry::RegisterSlateStyle(*FPShooterStyleInstance); // 사용자 정의 스타일을 등록
	}
}

void FPShooterStyle::ShutDown() // 묘듈 해제 시 포인터 비활성화 함수
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*FPShooterStyleInstance);
	ensure(FPShooterStyleInstance.IsUnique());
	FPShooterStyleInstance.Reset();
}


FName FPShooterStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("FPShooterStyle")); return StyleSetName;
}

// 사전 메크로 정의 (파일 경로를 간략화하기 위해)
#define IMAGE_BRUSH(RelativePath, ...) FSlateImageBrush(FPaths::ProjectContentDir() / "Slate"/ RelativePath+ TEXT(".png"), __VA_ARGS__ )
#define BOX_BRUSH(RelativePath, ...) FSlateBoxBrush(FPaths::ProjectContentDir() / "Slate"/ RelativePath+ TEXT(".png"), __VA_ARGS__ )
#define BORDER_BRUSH(RelativePath, ...) FSlateBorderBrush(FPaths::ProjectContentDir() / "Slate"/ RelativePath+ TEXT(".png"), __VA_ARGS__ )
#define TTF_FONT(RelativePath, ...) FSlateFontInfo(FPaths::ProjectContentDir() / "Slate"/ RelativePath+ TEXT("..ttf"), __VA_ARGS__ )
#define OTF_FONT(RelativePath, ...) FSlateFontInfo(FPaths::ProjectContentDir() / "Slate"/ RelativePath+ TEXT(".otf"), __VA_ARGS__ )


TSharedRef<class FSlateStyleSet> FPShooterStyle::Create()
{
	TSharedRef<FSlateStyleSet>StyleRef = FSlateGameResources::New(FPShooterStyle::GetStyleSetName(), "/Content/Slate", "/Content/Slate"); // 스타일셋 객채 생성
	FSlateStyleSet& Style = StyleRef.Get(); // 힙에 생성한 스타일셋 인스턴스의 주소를 저장
	// 사용자 정의 스타일을 생성한다.
	Style.Set("NormalButtonBrush", FButtonStyle().SetNormal(BOX_BRUSH("Button",	FVector2D(54, 54), FMargin(14.0f / 54.0f)))); // 노말버튼브러쉬는 버튼이 일반적인 상태일 때의 스타일(크기, 위치)이다.
	Style.Set("NormalButtonText", FTextBlockStyle(FTextBlockStyle::GetDefault()).SetColorAndOpacity(FSlateColor(FLinearColor(1, 1, 1, 1)))); // 노말버튼텍스트는 일반적인 상태일 때의 스타일(색상)이다.
	
	return StyleRef; // Map 형식으로 저장된 사용자정의 스타일 주소를 반환한다.
}

#undef IMAGE_BRUSH
#undef BOX_BRUSH
#undef BORDER_BRUSH
#undef TTF_FONT
#undef OTF_FONT

void FPShooterStyle::ReloadTextures()
{
	FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
}

const ISlateStyle& FPShooterStyle::Get()
{
	return *FPShooterStyleInstance;
}