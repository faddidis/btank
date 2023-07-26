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

// Called every frame
void ATankPlayerConroller::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	 AimTowardsCrosshair();
	//UE_LOG(LogTemp, Warning, TEXT("Player controller ticking"));

}


ATank* ATankPlayerConroller::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerConroller::AimTowardsCrosshair() 
{
	if (!GetControlledTank()) { return; }
		// Get world location if linetrace thorough crosshair
		// If it hits the landscape
				// Tell controled tank to aim at this point

}