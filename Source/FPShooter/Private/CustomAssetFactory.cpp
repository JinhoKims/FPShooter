// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomAssetFactory.h"
#include "MyCustomAsset.h"
#include "FPShooter.h"

UCustomAssetFactory::UCustomAssetFactory() :Super()
{
    bCreateNew = true;
    bEditAfterNew = true;
    SupportedClass = UMyCustomAsset::StaticClass(); // 팩토리가 생성할 객체 타입(MyCustomAsset)에 대한 리플렉션 정보를 해당 객체에 저장한다.
}

UObject* UCustomAssetFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext)
{
    auto NewObjectAsset = NewObject<UMyCustomAsset>(InParent, InClass, InName, Flags); // 객체 타입을 결정하여 인스턴스 생성
    return NewObjectAsset;
}
