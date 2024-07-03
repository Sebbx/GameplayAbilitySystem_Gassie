// Copyright Sebastian Rubacha


#include "AbilitySystem/Data/AttributeInfo.h"

FGassieAttributeInfo UAttributeInfo::FindAttributeInfoOrTag(const FGameplayTag& AttributeTag, bool bLogNotFound) const
{
	for (const FGassieAttributeInfo& Info : AttributeInformation)
	{
		if (Info.AttributeTag == AttributeTag)
		{
			return Info;
		}
	}

	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Can't Find Info for AttributeTag [%s] on AttributeInfo [%s]."), *AttributeTag.ToString(), *GetNameSafe(this));
	}

	return FGassieAttributeInfo();
}
