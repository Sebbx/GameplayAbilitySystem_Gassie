// Copyright Sebastian Rubacha

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GassieEffectActor.generated.h"

class USphereComponent;

UCLASS()
class GAS_ARPG_API AGassieEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AGassieEffectActor();

	UFUNCTION()
	virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> Sphere;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> Mesh;

};
