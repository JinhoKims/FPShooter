// Fill out your copyright notice in the Description page of Project Settings.


#include "Barracks.h"
#include "BarracksUnit.h"

// Sets default values
ABarracks::ABarracks()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BulidingMesh = CreateDefaultSubobject<UStaticMeshComponent>("BulidingMesh");
	SpawnPoint = CreateDefaultSubobject<UParticleSystemComponent>("SpawnPoint");
	SpawnInterval = 5; // ���� ����

	// �跰 ��Ų
	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'")); 
	if (MeshAsset.Succeeded())
	{
		BulidingMesh->SetStaticMesh(MeshAsset.Object);
		BulidingMesh->SetCollisionProfileName(FName(TEXT("Pawn"))); // �ݸ���(�浹����) ����
	}

	// ���� ���� ǥ�ÿ�
	auto ParticleSystem = ConstructorHelpers::FObjectFinder<UParticleSystem>(TEXT("ParticleSystem'/Engine/Tutorial/SubEditors/TutorialAssets/TutorialParticleSystem.TutorialParticleSystem'"));
	if (ParticleSystem.Succeeded())
	{
		SpawnPoint->SetTemplate(ParticleSystem.Object);
	}

	RootComponent = BulidingMesh;
	SpawnPoint->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform); // ���� ����Ʈ�� ��Ʈ(�޽�)�� ���
	SpawnPoint->SetRelativeScale3D(FVector(0.5, 0.5, 0.5)); // ���� ����Ʈ�� ������ ����

	UnitToSpawn = ABarracksUnit::StaticClass(); // �������� ��ü ����
}

// Called when the game starts or when spawned
void ABarracks::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &ABarracks::SpawnUnit, SpawnInterval, true); // 5�� ���� ���� ����
}

// Called every frame
void ABarracks::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABarracks::SpawnUnit() // ���� ���� �Լ�
{
	FVector SpawnLocation = SpawnPoint->GetComponentLocation() + FVector(50, 0, 0); // ���� ����Ʈ�� ��ǥ
	GetWorld()->SpawnActor(UnitToSpawn, &SpawnLocation); // �ش� ��ġ�� UnitToSpawn ��ü ����
}

void ABarracks::EndPlay(const EEndPlayReason::Type EndPlayReason) // ���� ����� ȣ��Ǵ� �Լ�
{
	Super::EndPlay(EndPlayReason);
	GetWorld()->GetTimerManager().ClearTimer(SpawnTimerHandle); // �θ� Ŭ������ �ı��� �� ���� Ÿ�̸Ӹ� ����(��ȿ���� ����)
}

