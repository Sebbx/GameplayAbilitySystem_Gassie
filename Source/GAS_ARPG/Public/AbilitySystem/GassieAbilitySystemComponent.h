// Copyright Sebastian Rubacha

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GassieAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class GAS_ARPG_API UGassieAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	void AbilityActorInfoSet(); //53.
	
protected:
	//53. GameplayEffect Delegates
	void EffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle);
	
};
