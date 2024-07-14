// Copyright Sebastian Rubacha

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GassieProjectile.generated.h"

class UProjectileMovementComponent;
class USphereComponent;

UCLASS()
class GAS_ARPG_API AGassieProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	AGassieProjectile();

	TObjectPtr<UProjectileMovementComponent> ProjectileMovement;

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFrommSweep, const FHitResult& SweepResult);
	
private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> Sphere;
};
