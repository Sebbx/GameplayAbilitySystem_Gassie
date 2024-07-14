// Copyright Sebastian Rubacha


#include "AbilitySystem/GassieAbilitySystemComponent.h"

#include "AbilitySystem/Abilities/GassieGameplayAbility.h"

void UGassieAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UGassieAbilitySystemComponent::ClientEffectApplied);
}

void UGassieAbilitySystemComponent::AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& StartupAbilities) //97, 102
{
	for (const TSubclassOf<UGameplayAbility> AbilityClass : StartupAbilities)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilityClass, 1);
		if (const UGassieGameplayAbility* GassieAbility = Cast<UGassieGameplayAbility>(AbilitySpec.Ability))
		{
			AbilitySpec.DynamicAbilityTags.AddTag(GassieAbility->StartupInputTag);
			GiveAbility(AbilitySpec);
		}
	}
}

void UGassieAbilitySystemComponent::AbilityInputTagHeld(const FGameplayTag& InputTag) //102
{
	if (!InputTag.IsValid()) return;
	
	for(FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities()) 	// GetActivatableAbilities() - Get abilities that can be activated
	{
		if (AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag))
		{   
			AbilitySpecInputPressed(AbilitySpec); //This only tells ability that input was pressed, you can override virtual function onpressed to implement some functionality
			if (!AbilitySpec.IsActive())
			{
				TryActivateAbility(AbilitySpec.Handle);
			}
		}
	}
}

void UGassieAbilitySystemComponent::AbilityInputTagReleased(const FGameplayTag& InputTag)
{
	if (!InputTag.IsValid()) return;
	
	for(FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities()) 	// GetActivatableAbilities() - Get abilities that can be activated
	{
		if (AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag))
		{
			AbilitySpecInputReleased(AbilitySpec); //This only tells ability that input was released, you can override virtual function onreleased to implement some functionality
		}
	}
}

void UGassieAbilitySystemComponent::ClientEffectApplied_Implementation(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	FGameplayTagContainer TagContainer;	//54.
	EffectSpec.GetAllAssetTags(TagContainer);

	EffectAssetTagsDelegate.Broadcast(TagContainer); //55.
	
}
