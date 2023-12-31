// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent* BarrelToSet)
{
	Barrel = BarrelToSet;

}

 void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	 if (!Barrel){ return; }

	 FVector OutLaunchVelocity;
	 FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	 bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	 (
		 this,
		 OutLaunchVelocity,
		 StartLocation,
		 HitLocation,
		 LaunchSpeed,
		 ESuggestProjVelocityTraceOption::DoNotTrace
	 );
		 // Calculate the OutLaunchVelecity
		 if (bHaveAimSolution)
		 {
			 auto AimDirection = OutLaunchVelocity.GetSafeNormal();
			// auto TankName = GetOwner()->GetName();
			 //UE_LOG(LogTemp, Warning, TEXT("%s Aiming at  %s "), *TankName, *AimDirection.ToString());
			 MoveBarrelTowards(AimDirection);
		 }
		// if no solution found do noting
}

 void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
 {
	 // Work difference between curent barrel rotation, and AimDerection
	 auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	 auto AimAsRotator = AimDirection.Rotation();
	 auto DeltaRotator = AimAsRotator - BarrelRotator;
	 UE_LOG(LogTemp, Warning, TEXT(" AimAsRotator: %s "), *AimAsRotator.ToString());

	 // Move the barrel the right amount this frame


	 // Given a max elevation speed, and frame time
 }
	 