// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCustomAssetActions.h"
#include "MyCustomAsset.h"
#include "EditorStyle.h"
#include "MainFrame/Public/MainFrame.h"

bool MyCustomAssetActions::HasActions(const TArray<UObject*>& InObjects) const
{
    return true;
}

void MyCustomAssetActions::GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder)
{
    MenuBuilder.AddMenuEntry( // 컨텍스트 메뉴 생성
        FText::FromString("CustomAssetAction"),
        FText::FromString("Action from Cookbook Recipe"),
        FSlateIcon(),
        FUIAction(FExecuteAction::CreateRaw(this, &MyCustomAssetActions::MyCustomAssetContext_Clicked), FCanExecuteAction())); // 우클릭 시 실행할 액션(함수) 등록
}

FText MyCustomAssetActions::GetName() const
{
    return FText::FromString(TEXT("My Custom Asset"));
}

UClass* MyCustomAssetActions::GetSupportedClass() const
{
    return UMyCustomAsset::StaticClass(); // 애셋의 원형 클래스
}

FColor MyCustomAssetActions::GetTypeColor() const
{
    return FColor::Emerald;
}

uint32 MyCustomAssetActions::GetCategories()
{
    return EAssetTypeCategories::Misc;
}

void MyCustomAssetActions::MyCustomAssetContext_Clicked()
{
    TSharedRef<SWindow> CookbookWindow = SNew(SWindow).Title(FText::FromString(TEXT("Cookbook Window"))).ClientSize(FVector2D(800, 400)).SupportsMaximize(false).SupportsMinimize(false);
    // 윈도우 생성
    IMainFrameModule& MainFrameModule = FModuleManager::LoadModuleChecked<IMainFrameModule>(TEXT("MainFrame")); // 생성된 새 창에서 에디터의 메인 어플리케이션 프레임 모듈을 불러온다.

    if (MainFrameModule.GetParentWindow().IsValid()) // 에디터에 이미 최상위 창이 존재한다면
    {
        FSlateApplication::Get().AddWindowAsNativeChild(CookbookWindow, MainFrameModule.GetParentWindow().ToSharedRef()); // 새 창을 자식으로 생성한다.
    }
    else
    {
        FSlateApplication::Get().AddWindow(CookbookWindow); // 그게 아니면 새로 창을 생성한다. (부모가 됨)
    }
}
