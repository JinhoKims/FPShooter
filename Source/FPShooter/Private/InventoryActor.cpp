// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryActor.h"

AInventoryActor::AInventoryActor() :Super()
{
	PrimaryActorTick.bCanEverTick = true;
	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cone.Cone'")); // Cone ���
	if (MeshAsset.Object != nullptr)
	{
		GetStaticMeshComponent()->SetStaticMesh(MeshAsset.Object);
		GetStaticMeshComponent()->SetCollisionProfileName(FName(TEXT("Pawn"))); // Pawn �ݸ���
	}
	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
	SetActorEnableCollision(true);
}

void AInventoryActor::PickUp() // �Ⱦ� �� ����
{
	SetActorTickEnabled(false);
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
}

void AInventoryActor::PutDown(FTransform TargetLocation) // �������� �� Ȱ��ȭ
{
	SetActorTickEnabled(true);
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
	SetActorLocation(TargetLocation.GetLocation()); // ���� ��ġ�� �̵�
}
