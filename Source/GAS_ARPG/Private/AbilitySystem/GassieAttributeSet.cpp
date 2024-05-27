// Copyright Sebastian Rubacha


#include "AbilitySystem/GassieAttributeSet.h"


#include "Net/UnrealNetwork.h"


UGassieAttributeSet::UGassieAttributeSet()
{
	InitHealth(100.f);
	InitMaxHealth(100.f);
	InitMana(70.f);
	InitMaxMana(70.f);
}

void UGassieAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UGassieAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGassieAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGassieAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGassieAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
}

void UGassieAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGassieAttributeSet, Health, OldHealth);
}

void UGassieAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGassieAttributeSet, MaxHealth, OldMaxHealth);
}

void UGassieAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGassieAttributeSet, Mana, OldMana);
}

void UGassieAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGassieAttributeSet, MaxMana, OldMaxMana);
}
