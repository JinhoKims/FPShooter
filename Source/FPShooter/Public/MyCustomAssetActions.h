// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetTypeActions_Base.h" // 애셋 컨텍스트 메뉴 명령 특화 클래스

/**
 * 
 */
class FPSHOOTER_API MyCustomAssetActions : public FAssetTypeActions_Base // 컨텍스트(우클릭) 메뉴를 확장할 수 있는 클래스를 상속한 애셋에 대한 사용자 정의 컨텍스트 메뉴 클래스 
{
public:

	virtual bool HasActions(const TArray<UObject*>& InObjects) const override; // 애셋에 적용할 수 있는 액션(여기선 컨텍스트 메뉴)이 있는지 확인용
	virtual void GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder) override; // 애셋이 구현한 액션을 반환
	virtual FText GetName() const override; // 애셋 미리보기
	virtual FColor GetTypeColor() const override;   // 미리보기 색상
	virtual uint32 GetCategories() override; // 애셋 생성 카테고리 위치(기타로 설정)
	virtual UClass* GetSupportedClass() const override; // 애셋의 원형(클래스) 반환

	void MyCustomAssetContext_Clicked(); // 액션(컨텍스트 매뉴) 구현부
};
