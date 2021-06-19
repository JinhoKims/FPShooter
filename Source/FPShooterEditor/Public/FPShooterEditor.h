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

	IConsoleCommand* DisplayTestCommand; // 사용자정의 콘솔 명령어 포인터1
	IConsoleCommand* DisplayUserSpecifiedWindow; // 사용자정의 콘솔 명령어 포인터2

	void MyButton_Clicked() // 버튼 클릭 효과
	{
		TSharedRef<SWindow> CookbookWindow = SNew(SWindow).Title(FText::FromString(TEXT("Cookbook Window"))).ClientSize(FVector2D(800, 400)).SupportsMaximize(false).SupportsMinimize(false)[SNew(SVerticalBox) + SVerticalBox::Slot().HAlign(HAlign_Center).VAlign(VAlign_Center)[SNew(STextBlock).Text(FText::FromString(TEXT("Hello from Slate")))]]; // 버튼 클릭 시 윈도우(창) 생성
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

	void AddMenuExtension(FMenuBuilder& builder) // 메뉴 디자인
	{
		FSlateIcon IconBrush = FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.ViewOptions", "LevelEditor.ViewOptions.Small");
		builder.AddMenuEntry(FPShooterCommands::Get().MyButton);
	}

	void DisplayWindow(FString WindowTitle) // 화면 창을 생성하는 함수 (사용자 정의 콘솔 명령어에서 사용)
	{
		TSharedRef<SWindow> CookbookWindow = SNew(SWindow).Title(FText::FromString(WindowTitle)).ClientSize(FVector2D(800, 400)).SupportsMaximize(false).SupportsMinimize(false); // WindowTitle 인자를 제목으로한 창을 생성 (최대화, 최소화 불가)
		
		// 메인프레임 모듈은 에디터를 관리하는 상위 모듈이다.
		IMainFrameModule& MainFrameModule = FModuleManager::LoadModuleChecked<IMainFrameModule>(TEXT("MainFrame")); // 생성된 새 창에서 엔진의 메인 어플리케이션 프레임 모듈을 불러온다.
		if (MainFrameModule.GetParentWindow().IsValid())  // 엔진에 이미 최상위 창(에디터)이 존재한다면
		{
			FSlateApplication::Get().AddWindowAsNativeChild(CookbookWindow, MainFrameModule.GetParentWindow().ToSharedRef());  // 새 창을 자식으로 생성한다.
		}
		else
		{
			FSlateApplication::Get().AddWindow(CookbookWindow); // 그게 아니면 새로운 창을 생성한다.
		}
		// ※ 언리얼 엔진의 창 구분은 배경에 줄무늬(///)가 있을 경우 독립적인 최상위 창이고, 배경이 민무늬면 이미 생성된 특정 창의 자식 창이다. 
	}
};