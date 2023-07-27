// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerConroller.h"
#define OUT


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
	
	FVector  HitLocation; // Out Parameter
	if(GetSightRayLocation(HitLocation)) // Has "side-effect", is going to line trace
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());

				// TODO Tell controled tank to aim at this point)
	}

}

// Get world location of linetrace thorough crosshair, true if hits the landscape
bool ATankPlayerConroller::GetSightRayLocation(FVector& HitLocation) const
{
	HitLocation = FVector(1.0);
	return false;
}
