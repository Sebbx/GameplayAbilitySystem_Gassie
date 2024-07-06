// Copyright Sebastian Rubacha

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "AttributeInfo.generated.h"
/**
 * 88. Attribute Info Data Asset
 */

USTRUCT(BlueprintType)
struct FGassieAttributeInfo
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FGameplayTag AttributeTag = FGameplayTag();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText AttributeName = FText();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText AttributeDescription = FText();

	UPROPERTY(BlueprintReadOnly)
	float AttributeValue = 0.f;
};

UCLASS()
class GAS_ARPG_API UAttributeInfo : public UDataAsset
{
	GENERATED_BODY()
public:
	FGassieAttributeInfo FindAttributeInfoOrTag(const FGameplayTag& AttributeTag, bool bLogNotFound = false) const;
	
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FGassieAttributeInfo> AttributeInformation;
	
	
};
