// Copyright Sebastian Rubacha


#include "UI/WidgetController/AttributeMenuWidgetController.h"
#include "AbilitySystem/GassieAttributeSet.h"
#include "AbilitySystem/Data/AttributeInfo.h"
#include "GassieGameplayTags.h"

void UAttributeMenuWidgetController::BindCallbacksToDependencies()
{
	
}

void UAttributeMenuWidgetController::BroadcastInitialValues()
{// 92. Attribute Info Delegate
	UGassieAttributeSet* AS = CastChecked<UGassieAttributeSet>(AttributeSet);

	check(AttributeInfo);
	
	FGassieAttributeInfo Info = AttributeInfo->FindAttributeInfoOrTag(FGassieGameplayTags::Get().Attributes_Primary_Strength);
	Info.AttributeValue = AS->GetStrength();
	AttributeInfoDelegate.Broadcast(Info);
}
