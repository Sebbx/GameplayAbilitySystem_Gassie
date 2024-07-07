// Copyright Sebastian Rubacha


#include "Input/GassieInputConfig.h"

const UInputAction* UGassieInputConfig::FindAbilityInputActionForTag(const FGameplayTag& InputTag, bool bLogNotFound) const
{
	for (const FGassieInputAction& AbilityInputAction : AbilityInputActions)
	{
		if (AbilityInputAction.InputAction && AbilityInputAction.GameplayTag == InputTag) return AbilityInputAction.InputAction;
	}

	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Can't find AbilityInputAction for InputTag [%s], on InputConfig [%s}"), *InputTag.ToString(), *GetNameSafe(this))
	}
	return nullptr;
}
