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
    IMainFrameModule& MainFrameModule = FModuleManager::LoadModuleChecked<IMainFrameModule>(TEXT("MainFrame")); // MainFrame 모듈 불러오기

    if (MainFrameModule.GetParentWindow().IsValid()) // 이미 부모 창이 있을 경우
    {
        FSlateApplication::Get().AddWindowAsNativeChild(CookbookWindow, MainFrameModule.GetParentWindow().ToSharedRef()); // 자식으로 창 생성
    }
    else
    {
        FSlateApplication::Get().AddWindow(CookbookWindow); // 새로 창 생성 (부모가 됨)
    }
}
