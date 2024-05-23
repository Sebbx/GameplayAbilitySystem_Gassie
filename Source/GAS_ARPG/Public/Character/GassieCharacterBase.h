// Copyright Sebastian Rubacha

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GassieCharacterBase.generated.h"

// Preventing to being dragged out to the level
UCLASS(Abstract)
class GAS_ARPG_API AGassieCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AGassieCharacterBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;

};
