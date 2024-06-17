#include "Character/GassieCharacterBase.h"

#include "AbilitySystemComponent.h"

AGassieCharacterBase::AGassieCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
	
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName ("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* AGassieCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* AGassieCharacterBase::GetAttributeSet() const
{
	return AttributeSet;
}

void AGassieCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGassieCharacterBase::InitAbilityActorInfo()
{
}

void AGassieCharacterBase::InitializePrimaryAttributes() const
{
	check (IsValid(GetAbilitySystemComponent()));
	check(DefaultPrimaryAttributes);
	const FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(DefaultPrimaryAttributes, 1.f, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
}

