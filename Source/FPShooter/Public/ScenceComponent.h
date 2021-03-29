// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "ScenceComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FPSHOOTER_API UScenceComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UScenceComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
	void Spawn(); // ���� �Լ�

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AHierachyActor> ActorToSpawn; // <���� Ŭ����(AActor)�� ���ѵǴ�> ����(HierachyActor) �ּҸ� �����ϱ� ���� �����ʹ�.
		
};
