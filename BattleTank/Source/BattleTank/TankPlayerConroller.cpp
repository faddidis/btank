// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerConroller.h"

void ATankPlayerConroller::BeginPlay()
{
	Super:: BeginPlay();
	auto ControlledTank = GetControlledTank();

	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing a tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possesing: %s"), *(ControlledTank->GetName()));

	}

}

ATank* ATankPlayerConroller::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}


