// Copyright Sebastian Rubacha


#include "Player/GassiePlayerState.h"

#include "AbilitySystem/GassieAbilitySystemComponent.h"
#include "AbilitySystem/GassieAttributeSet.h"

AGassiePlayerState::AGassiePlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UGassieAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UGassieAttributeSet>("AttributeSet");

	
	NetUpdateFrequency = 100.f;
}

UAbilitySystemComponent* AGassiePlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* AGassiePlayerState::GetAttributeSet() const
{
	return AttributeSet;
}
