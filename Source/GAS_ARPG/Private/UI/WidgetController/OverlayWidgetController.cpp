// Copyright Sebastian Rubacha


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/GassieAbilitySystemComponent.h"
#include "AbilitySystem/GassieAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UGassieAttributeSet* GassieAttributes = CastChecked<UGassieAttributeSet>(AttributeSet);
	OnHealthChanged.Broadcast(GassieAttributes->GetHealth());
	OnMaxHealthChanged.Broadcast(GassieAttributes->GetMaxHealth());
	OnManaChanged.Broadcast(GassieAttributes->GetMana());
	OnMaxManaChanged.Broadcast(GassieAttributes->GetMaxMana());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UGassieAttributeSet* GassieAttributes = CastChecked<UGassieAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(GassieAttributes->GetHealthAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnHealthChanged.Broadcast(Data.NewValue);
		});

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(GassieAttributes->GetMaxHealthAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnMaxHealthChanged.Broadcast(Data.NewValue);
		});
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(GassieAttributes->GetManaAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnManaChanged.Broadcast(Data.NewValue);
		});

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(GassieAttributes->GetMaxManaAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnMaxManaChanged.Broadcast(Data.NewValue);
		});
	
	//55. Broadcasted from UGassieAbilitySystemComponent::EffectApplied
	Cast<UGassieAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTagsDelegate.AddLambda(
	[this](const FGameplayTagContainer& AssetTags)
	{
		for (const FGameplayTag& Tag : AssetTags)
		{
			// 57.
			/* Wywołanie GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag); nie jest możliwe do wykonania bez 'capture', ponieważ Lambda to anonimowa funkcja i nie może wiedzieć nic o istniejących obiektach, w tym przypadku
			OverlayWidgetComponent.
			Jeśli chcemy się dostać do member variable, wtedy ten obiekt który ma member variable musi zostać 'capture' w lambdzie (nawiasy kwagdratowe)*/

			// 58.
			// "A.1".MatchesTag("A") will return True, "A".MatchesTag("A.1") will return False
			
			if (Tag.MatchesTag(FGameplayTag::RequestGameplayTag(FName("Message"))))
			{
				const FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag);
				MessageWidgetRowDelegate.Broadcast(*Row);
			}
		}
	});
}
