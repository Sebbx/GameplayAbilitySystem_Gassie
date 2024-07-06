// Copyright Sebastian Rubacha


#include "UI/WidgetController/AttributeMenuWidgetController.h"
#include "AbilitySystem/GassieAttributeSet.h"
#include "AbilitySystem/Data/AttributeInfo.h"

void UAttributeMenuWidgetController::BindCallbacksToDependencies()
{
	//95. Responding to Attribute Changes
	UGassieAttributeSet* AS = CastChecked<UGassieAttributeSet>(AttributeSet);
	check(AttributeInfo);
	for(auto& Pair : AS->TagsToAttributes)
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Pair.Value()).AddLambda(
		[this, Pair](const FOnAttributeChangeData& Data)
		{
			BroadcastAttributeInfo(Pair.Key, Pair.Value());
		});
}

void UAttributeMenuWidgetController::BroadcastInitialValues()
{// 92. Attribute Info Delegate, 94. Mapping Tags to Attributes
	UGassieAttributeSet* AS = CastChecked<UGassieAttributeSet>(AttributeSet);
	check(AttributeInfo);
	for (auto& Pair : AS->TagsToAttributes)
	{
		BroadcastAttributeInfo(Pair.Key, Pair.Value());
	}
}

void UAttributeMenuWidgetController::BroadcastAttributeInfo(const FGameplayTag& AttributeTag,const FGameplayAttribute& Attribute) const
{
	FGassieAttributeInfo Info =  AttributeInfo->FindAttributeInfoOrTag(AttributeTag);
	Info.AttributeValue = Attribute.GetNumericValue(AttributeSet);
	AttributeInfoDelegate.Broadcast(Info);
}
