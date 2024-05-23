#include "Character/GassieCharacterBase.h"

AGassieCharacterBase::AGassieCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
	
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName ("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AGassieCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

