// Fill out your copyright notice in the Description page of Project Settings.


#include "OrbitingMovementComponent.h"

// Sets default values for this component's properties
UOrbitingMovementComponent::UOrbitingMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	RotationSpeed = 20;  // �� �ʸ��� ������Ʈ�� ȸ���ϴ� ����
	OrbitDistance = 100; // ������Ʈ�� �������� �����̱� ���� ȸ���ؾ� �ϴ� �Ÿ�
	CurrentValue = 0; // ���� �������� ȸ�� ��ġ
	RotateToFaceOutwards = true; // ���� ����
	
}


// Called when the game starts
void UOrbitingMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UOrbitingMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{ 
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	float CurrentValueInRadinas = FMath::DegreesToRadians<float>(CurrentValue); // CurentValue�� ��׸� �������� ���� ������ �ٲ۴�.
	SetRelativeLocation(FVector(OrbitDistance *
		FMath::Cos(CurrentValueInRadinas), OrbitDistance *
		FMath::Sin(CurrentValueInRadinas), GetRelativeLocation().Z)); // ȸ�� ��ġ�� ���
	if (RotateToFaceOutwards)
	{
		FVector LookDir = (GetRelativeLocation()).GetSafeNormal();
		FRotator LookAtRot = LookDir.Rotation();
		SetRelativeRotation(LookAtRot); // ȸ�� ������ ���
	}
	CurrentValue = FMath::Fmod(CurrentValue + (RotationSpeed * DeltaTime), 360);
}

