// Copyright Sebastian Rubacha
// 99. Input Config Data Asset
#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "GassieInputConfig.generated.h"

USTRUCT(BlueprintType)
struct FGassieInputAction
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	const class UInputAction* InputAction = nullptr;

	UPROPERTY(EditDefaultsOnly)
	FGameplayTag GameplayTag = FGameplayTag();
	
};
/**
 * 
 */
UCLASS()
class GAS_ARPG_API UGassieInputConfig : public UDataAsset
{
	GENERATED_BODY()
public:
	const UInputAction* FindAbilityInputActionForTag(const FGameplayTag& InputTag, bool bLogNotFound = false) const;
		
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FGassieInputAction> AbilityInputActions;
	
};
