// Copyright Sebastian Rubacha

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GassieAbilitySystemComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FEffectAssetTags, const FGameplayTagContainer&); //55.Broadcasting Effect Asset Tags

/**
 * 
 */
UCLASS()
class GAS_ARPG_API UGassieAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	void AbilityActorInfoSet(); //53.
	FEffectAssetTags EffectAssetTagsDelegate; //55. 

	void AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& StartupAbilities); //97. Granting Abilities
	
protected:
	void EffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle); //53. GameplayEffect Delegates
	
};
