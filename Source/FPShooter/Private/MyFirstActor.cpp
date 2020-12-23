// Fill out your copyright notice in the Description page of Project Settings.


#include "MyFirstActor.h"

// Sets default values
AMyFirstActor::AMyFirstActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject< USceneComponent>("Root");
	ChildSceneCoimponent = CreateDefaultSubobject<USceneComponent>("ChildSceneComponent");
	BoxOne = CreateDefaultSubobject<UStaticMeshComponent>("BoxOne");
	BoxTwo = CreateDefaultSubobject<UStaticMeshComponent>("BoxTwo");
	

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	if (MeshAsset.Succeeded())
	{
		BoxOne->SetStaticMesh(MeshAsset.Object);
		BoxTwo->SetStaticMesh(MeshAsset.Object);
	}
	RootComponent = Root; // ��Ʈ ������Ʈ ����
	BoxOne->SetupAttachment(Root); // ���� ������Ʈ�� ������ ���̱�
	ChildSceneCoimponent->SetupAttachment(Root);
	BoxTwo->SetupAttachment(ChildSceneCoimponent);
	ChildSceneCoimponent->SetRelativeTransform(FTransform(FRotator(0, 0, 0), FVector(200, 0, 0), FVector(0.1f))); // ���� ȸ��, ��ġ, �������� ��Ÿ��

}

// Called when the game starts or when spawned
void AMyFirstActor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMyFirstActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

