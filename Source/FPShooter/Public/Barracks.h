// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/Classes/Particles/ParticleSystemComponent.h"
#include "Barracks.generated.h"


UCLASS()
class FPSHOOTER_API ABarracks : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABarracks();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	UStaticMeshComponent* BulidingMesh;

	UPROPERTY()
	UParticleSystemComponent* SpawnPoint;

	UPROPERTY()
	UClass* UnitToSpawn; // ������ ���� ��ü

	UPROPERTY()
	float SpawnInterval; // ���� ����

	UFUNCTION()
	void SpawnUnit();

	UFUNCTION()
	void EndPlay(const EEndPlayReason::Type EndPlayReason) override; // ���� ���� �� ȣ��Ǵ� �Լ�

	UPROPERTY()
	FTimerHandle SpawnTimerHandle;

};
