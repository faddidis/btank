// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerConroller.generated.h" // Must be the last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerConroller : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank* GetControlledTank() const;

	
	
};
