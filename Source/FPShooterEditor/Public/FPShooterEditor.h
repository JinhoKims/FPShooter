#pragma once

#include "Engine.h"
#include "UnrealEd.h"
#include "FPShooterCommands.h"
#include "Interfaces/IMainFrameModule.h"

class FFPShooterEditorModule : public IModuleInterface // 에디터에 상단 툴바에 버튼을 구현하기 위한 클래스
{
public:
	virtual void StartupModule() override; // 모듈이 초기화될 때 실행되는 함수
	virtual void ShutdownModule() override; // 종료될 때 실행되는 함수
	TSharedPtr<FExtender> ToolbarExtender; // Extender 클래스를 사용하면 에디터 툴바에 추가할 수 있는 일련의 명령 함수 매핑을 만들 수 있다.
	TSharedPtr<const FExtensionBase> Extension; // 목록 확장
	TArray<TSharedPtr<class IAssetTypeActions>> CreatedAssetTypeActions; // 애셋 액션 인스턴스들의 주소 저장용 배열

	void MyButton_Clicked() // 버튼 클릭 효과
	{
		TSharedRef<SWindow> CookbookWindow = SNew(SWindow).Title(FText::FromString(TEXT("Cookbook Window"))).ClientSize(FVector2D(800, 400)).SupportsMaximize(false).SupportsMinimize(false)[SNew(SVerticalBox) + SVerticalBox::Slot().HAlign(HAlign_Center).VAlign(VAlign_Center)[SNew(STextBlock).Text(FText::FromString(TEXT("Hello from Slate")))]]; // 버튼 클릭 시 윈도우 생성 효과
		IMainFrameModule& MainFrameModule = FModuleManager::LoadModuleChecked<IMainFrameModule>(TEXT("MainFrame"));

		if (MainFrameModule.GetParentWindow().IsValid())
		{
			FSlateApplication::Get().AddWindowAsNativeChild(CookbookWindow, MainFrameModule.GetParentWindow().ToSharedRef());
		}
		else
		{
			FSlateApplication::Get().AddWindow(CookbookWindow);
		}
	}

	void AddToolbarExtension(FToolBarBuilder& builder) // 버튼 디자인
	{
		FSlateIcon IconBrush = FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.ViewOptions", "LevelEditor.ViewOptions.Small"); // 버튼의 아이콘 선정
		builder.AddToolBarButton(FPShooterCommands::Get().MyButton, NAME_None, FText::FromString("My Button"), FText::FromString("Click me to display a message"), IconBrush, NAME_None); // 버튼 속성 적용
	}

	void AddMenuExtension(FMenuBuilder& builder)
	{
		FSlateIcon IconBrush = FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.ViewOptions", "LevelEditor.ViewOptions.Small");
		builder.AddMenuEntry(FPShooterCommands::Get().MyButton);
	}
};