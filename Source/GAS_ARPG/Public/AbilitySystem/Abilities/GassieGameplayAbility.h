// Copyright Sebastian Rubacha

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GassieGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class GAS_ARPG_API UGassieGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	FGameplayTag StartupInputTag;


};
