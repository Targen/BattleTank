// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "TankPlayerController.generated.h"

class ATank;

UCLASS()
class BATTLETANKGAME_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = .5f;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = .3333f;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000.0f;

	ATank* GetControlledTank() const;

	// Start the tank moving the barrel so that it hits where the barrel intersects the world.
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
