// Fill out your copyright notice in the Description page of Project Settings.


#include "BarracksUnit.h"

// Sets default values
ABarracksUnit::ABarracksUnit()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VisualRepresentation = CreateDefaultSubobject<UParticleSystemComponent>("SpawnPoint"); // ���� ����(��ƼŬ)
	auto ParticleSystem = ConstructorHelpers::FObjectFinder<UParticleSystem>(TEXT("ParticleSystem'/Engine/Tutorial/SubEditors/TutorialAssets/TutorialParticleSystem.TutorialParticleSystem'"));
	if (ParticleSystem.Succeeded())
	{
		VisualRepresentation->SetTemplate(ParticleSystem.Object);
	}
	VisualRepresentation->SetRelativeScale3D(FVector(3.0, 3.0, 3.0)); // ��ƼŬ�� ������ ����
	VisualRepresentation->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform); // ������ ��ƼŬ�� ����(���� ĳ����)�� ��ӽ�Ŵ(���� ��ǥ�� ������)
	// ���ǻ��� : ��� Ÿ�̹��� BeginPlay�� �����ϸ� ��ƼŬ�� �� �߾ӿ� �����ǰ� ���� ��ӵǱ⿡(��Ʈ�� �ٿ����⿡) �̸� �����ڿ��� ��� ������ ó�����ش�.
	SpawnCollisionHandlingMethod = ESpawnActorCollisionHandlingMethod::AlwaysSpawn; // ������ ������ ���θ��°� ���� ��� ��� ���� ����(�����ϰ� ����)
	
}

// Called when the game starts or when spawned
void ABarracksUnit::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABarracksUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetActorLocation(GetActorLocation() + FVector(15, 0, -0.1)); // ������ ������ �� �����Ӹ��� 10��ŭ ����
}

// Called to bind functionality to input
void ABarracksUnit::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

