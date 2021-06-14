// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "CustomAssetFactory.generated.h"

/**
 * 
 */
UCLASS()
class FPSHOOTER_API UCustomAssetFactory : public UFactory // UFactory 클래스는 팩토리 디자인 패턴을 제공하는 클래스다. (팩토리 패턴 : 부모 클래스 객체를 인스턴스화 할 때 자식 클래스로 인스턴화 하는 디자인 패턴)
{														
	GENERATED_BODY()
public:
	UCustomAssetFactory();
	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext) override;
	// 팩토리 패턴으로 객체를 생성하는 함수
};
