// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TPC not possessed"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TPC is possesing: %s"), *(ControlledTank->GetName()));
	}	
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick( DeltaTime );
	AimTowardCrossHair();
	UE_LOG(LogTemp, Warning, TEXT("TPC is ticking"));
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardCrossHair()
{
	if (!GetControlledTank()) { return; }
}