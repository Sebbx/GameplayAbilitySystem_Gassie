#include "Character/GassieCharacterBase.h"

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

