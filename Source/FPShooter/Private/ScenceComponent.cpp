// Fill out your copyright notice in the Description page of Project Settings.


#include "ScenceComponent.h"
#include "HierachyActor.h"

// Sets default values for this component's properties
UScenceComponent::UScenceComponent() // �� ������Ʈ : Ʈ�������� ���� ���� ������Ʈ
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UScenceComponent::BeginPlay()
{
	Super::BeginPlay();

	Spawn();
	// ...
	
}


// Called every frame
void UScenceComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UScenceComponent::Spawn()
{
	UWorld* TheWorld = GetWorld(); // ���� ��ü(���͸� ���� ��Ű�� ����)
	if (TheWorld != nullptr)
	{
		FTransform ComponentTransform(this->GetComponentTransform()); // �� ������Ʈ�� ��ǥ(�� �� ������Ʈ�� ��ǥ�� ���� �� �ִ�.)
		TheWorld->SpawnActor(ActorToSpawn, &ComponentTransform); // HierachyActor ���͸� �θ� Ŭ���� ScenceCompoent�� ��ǥ�� ������Ų��.
	}
}

