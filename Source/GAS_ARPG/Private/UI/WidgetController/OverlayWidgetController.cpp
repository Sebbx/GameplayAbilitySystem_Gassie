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

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(GassieAttributes->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(GassieAttributes->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(GassieAttributes->GetManaAttribute()).AddUObject(this, &UOverlayWidgetController::ManaChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(GassieAttributes->GetMaxManaAttribute()).AddUObject(this, &UOverlayWidgetController::MaxManaChanged);

	//55.
	Cast<UGassieAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda(
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
				MessageWidgetRow.Broadcast(*Row);
			}

		}
	}
	);
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}
