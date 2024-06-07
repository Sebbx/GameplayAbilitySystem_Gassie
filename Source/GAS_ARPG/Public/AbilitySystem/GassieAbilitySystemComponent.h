// Copyright Sebastian Rubacha

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GassieAbilitySystemComponent.generated.h"

//55.Broadcasting Effect Asset Tags
DECLARE_MULTICAST_DELEGATE_OneParam(FEffectAssetTags, const FGameplayTagContainer&);

/**
 * 
 */
UCLASS()
class GAS_ARPG_API UGassieAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	void AbilityActorInfoSet(); //53.
	FEffectAssetTags EffectAssetTags; //55
	
	
protected:
	//53. GameplayEffect Delegates
	void EffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle);
	
};
