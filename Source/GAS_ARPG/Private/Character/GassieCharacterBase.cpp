#include "Character/GassieCharacterBase.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/GassieAbilitySystemComponent.h"

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

void AGassieCharacterBase::InitializeDefaultAttributes() const
{
	ApplyEffectToSelf(DefaultPrimaryAttributes, 1.f);
	ApplyEffectToSelf(DefaultSecondaryAttributes, 1.f);
	ApplyEffectToSelf(DefaultVitalAttributes, 1.f);
}

void AGassieCharacterBase::ApplyEffectToSelf(const TSubclassOf<UGameplayEffect> GameplayEffectClass, const float Level) const
{
	check (IsValid(GetAbilitySystemComponent()));
	check(GameplayEffectClass);
	FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	ContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(GameplayEffectClass, Level, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
}

void AGassieCharacterBase::AddCharacterAbilities()
{// Only on server
	UGassieAbilitySystemComponent* GassieASC = CastChecked<UGassieAbilitySystemComponent>(AbilitySystemComponent);
	if (!HasAuthority()) return;

	GassieASC->AddCharacterAbilities(StartupAbilities);
}



