// Copyright Sebastian Rubacha

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/GassieGameplayAbility.h"
#include "GassieProjectileSpell.generated.h"

class AGassieProjectile;
/**
 * 
 */
UCLASS()
class GAS_ARPG_API UGassieProjectileSpell : public UGassieGameplayAbility
{
	GENERATED_BODY()
	
protected:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<AGassieProjectile> ProjectileClass;
};
