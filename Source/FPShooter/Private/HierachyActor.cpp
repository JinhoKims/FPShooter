// Fill out your copyright notice in the Description page of Project Settings.


#include "HierachyActor.h"

// Sets default values
AHierachyActor::AHierachyActor() // ���� ������ ���ϴ� ����
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// ������Ʈ ����
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	ChildScenceComponent = CreateDefaultSubobject<USceneComponent>("ChildScenceComponent");
	BoxOne = CreateDefaultSubobject<UStaticMeshComponent>("BoxOne");
	BoxTwo = CreateDefaultSubobject<UStaticMeshComponent>("BoxTwo");

	// ������Ʈ�� �޽� ���̱�
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cone.Cone'"));
	if (MeshAsset.Succeeded())
	{
		BoxOne->SetStaticMesh(MeshAsset.Object); // boxOne�� boxTwo ��� ������ �޽ø� ������.
		BoxTwo->SetStaticMesh(MeshAsset.Object);
	}

	// �������� ����
	RootComponent = Root;
	BoxOne->AttachTo(Root);
	BoxTwo->AttachTo(ChildScenceComponent);
	ChildScenceComponent->AttachTo(Root);
	ChildScenceComponent->SetRelativeTransform(FTransform(FRotator(0, 0, 0), FVector(250, 0, 0), FVector(0.1f))); // ȸ��, ��ǥ, ������ ����
}

// Called when the game starts or when spawned
void AHierachyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHierachyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

