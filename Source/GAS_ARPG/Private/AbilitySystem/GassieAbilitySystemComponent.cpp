// Copyright Sebastian Rubacha


#include "AbilitySystem/GassieAbilitySystemComponent.h"

void UGassieAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UGassieAbilitySystemComponent::EffectApplied);
}

void UGassieAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	//54.
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);
	//55.
	EffectAssetTagsDelegate.Broadcast(TagContainer);
	

}
