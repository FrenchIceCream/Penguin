// Copyright Epic Games, Inc. All Rights Reserved.


#include "PenguinGameModeBase.h"
#include "GameFramework/Actor.h"

APenguinGameModeBase::APenguinGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APenguinGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle UnusedHandle;
	GetWorldTimerManager().SetTimer(UnusedHandle, this, &APenguinGameModeBase::SpawnPlayerRecharge, FMath::RandRange(1,3), true);
}

void APenguinGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APenguinGameModeBase::SpawnPlayerRecharge()
{
	float RandX = FMath::RandRange(Spawn_X_Min, Spawn_X_Max);
	float RandY = FMath::RandRange(Spawn_Y_Min, Spawn_Y_Max);

	FVector SpawnPosition = FVector(RandX, RandY, Spawn_Z);
	FRotator SpawnRotation = FRotator(0, 0, 0);

	GetWorld()->SpawnActor(PlayerRecharge, &SpawnPosition, &SpawnRotation);
}
