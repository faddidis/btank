// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerConroller.h"

ATank* ATankPlayerConroller::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}


