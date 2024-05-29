// Copyright Sebastian Rubacha


#include "UI/WidgetController/OverlayWidgetController.h"

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
