// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "CustomButton.h"
#include "Framework/SlateDelegates.h"
#include "CustomButtonWidget.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_DELEGATE_RetVal(FString, FGetString); // 문자열 갱신 델리게이트
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FButtonClicked); // 버튼 클릭시의 델리게이트 선언 

UCLASS()
class FPSHOOTER_API UCustomButtonWidget : public UWidget // 블루프린트에 노출시키기 위한 UMG 위젯 클래스다. UWidget(프론트엔드) 객체는 SWidget(백엔드) 객체에 대한 참조가 있어야 한다.
{
	GENERATED_BODY()

protected:
	TSharedPtr<SCustomButton> MyButton; // SWidget 참조에 대한 공유 포인터
	virtual TSharedRef<SWidget> RebuildWidget() override; // 네이티브 위젯 재구성
	
public:
	UCustomButtonWidget();
	
	UPROPERTY(BlueprintAssignable)
	FButtonClicked ButtonClicked; // 메크로로 선언한 델리게이트를 객체로 만든다.

	FReply OnButtonClicked();

	UPROPERTY(BlueprintReadWrite, EditAnywhere) 
	FString Label; // 버튼 문자열
	
	UPROPERTY()
	FGetString LabelDelegate; 

	virtual void SynchronizeProperties() override; // UWidget 클래스(블프)에서 연결된 속성을 SWidget(C++)에 적용한다.
};
