// Copyright Sebastian Rubacha

#include "Actor/GassieEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/GassieAttributeSet.h"
#include "Components/SphereComponent.h"

AGassieEffectActor::AGassieEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
	
	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());

}

void AGassieEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UGassieAttributeSet* GassieAttributeSet = Cast<UGassieAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UGassieAttributeSet::StaticClass()));
		//TODO: Big no no
		UGassieAttributeSet* MutableGassieAttributeSet = const_cast<UGassieAttributeSet*>(GassieAttributeSet);
		MutableGassieAttributeSet->SetHealth(GassieAttributeSet->GetHealth() + 5.f);
		Destroy();
	}
}

void AGassieEffectActor::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}

void AGassieEffectActor::BeginPlay()
{
	Super::BeginPlay();
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AGassieEffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AGassieEffectActor::OnEndOverlap);
}

