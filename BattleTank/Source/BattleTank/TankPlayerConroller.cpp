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
		//UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *HitLocation.ToString());

				// TODO Tell controled tank to aim at this point)
	}

}

// Get world location of linetrace thorough crosshair, true if hits the landscape
bool ATankPlayerConroller::GetSightRayLocation(FVector& HitLocation) const
{

	//Find the crosshair position
	int32	 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	UE_LOG(LogTemp, Warning, TEXT("Screen Location: %s"), *ScreenLocation.ToString());
	// "De-project" the position of the crosshair to a world direction
	// Line-trace along that look direction, and see what we hit (up to max range)
	//HitLocation = FVector(1.0);
	return true;
}
