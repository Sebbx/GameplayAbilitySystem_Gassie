// Copyright Sebastian Rubacha


#include "Player/GassiePlayerState.h"

#include "AbilitySystem/GassieAbilitySystemComponent.h"
#include "AbilitySystem/GassieAttributeSet.h"
#include "Net/UnrealNetwork.h"

AGassiePlayerState::AGassiePlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UGassieAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UGassieAttributeSet>("AttributeSet");

	
	NetUpdateFrequency = 100.f;
}

void AGassiePlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AGassiePlayerState, Level);
}

UAbilitySystemComponent* AGassiePlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* AGassiePlayerState::GetAttributeSet() const
{
	return AttributeSet;
}

void AGassiePlayerState::OnRep_Level(int32 OldLevel)
{
	
}
