// Fill out your copyright notice in the Description page of Project Settings.


#include "DelegateListener.h"
#include "FPShooterGameMode.h"

// Sets default values
ADelegateListener::ADelegateListener()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	PointLight = CreateDefaultSubobject<UPointLightComponent>("PointLight");
	RootComponent = PointLight;
	PointLight->SetVisibility(false);
}

// Called when the game starts or when spawned
void ADelegateListener::BeginPlay()
{
	Super::BeginPlay();

	if (GetWorld() != nullptr)
	{
		AGameModeBase* GameMode = UGameplayStatics::GetGameMode(GetWorld());
		AFPShooterGameMode* MyGameMode = Cast<AFPShooterGameMode>(GameMode);
		if (MyGameMode != nullptr)
		{
			MyGameMode->MyStandardDelegate.BindUObject(this, &ADelegateListener::EnableLight); // MyStandardDelegate ��������Ʈ�� EnableLight �Լ� ���ε�
		}
	}
}

// Called every frame
void ADelegateListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADelegateListener::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (GetWorld() != nullptr)
	{
		AGameModeBase* GameMode = UGameplayStatics::GetGameMode(GetWorld());
		AFPShooterGameMode* MyGameMode = Cast<AFPShooterGameMode>(GameMode);
		if (MyGameMode != nullptr)
		{
			MyGameMode->MyStandardDelegate.Unbind(); // ��������Ʈ�� ����ε�. MyStandardDelegate�� ����� �Լ�(EnableLight)�� ������
			// �̸� ���� DelegateListener ���Ͱ� ������ ���� �� ���Ӹ���� MyStandardDelegate �����Ͱ� ��۸� �����Ͱ� ���� �ʵ��� ������ �� �ִ�.
			GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("Exit")));
		}
	}
}

void ADelegateListener::EnableLight()
{
	PointLight->SetVisibility(LightStats);
	LightStats = !LightStats;
}
