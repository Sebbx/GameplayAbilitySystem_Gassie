// Copyright Sebastian Rubacha


#include "Character/GassieCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/GassiePlayerState.h"

AGassieCharacter::AGassieCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void AGassieCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Init ability Actor info for the Server
	InitAbilityActorInfo();
}

void AGassieCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// Init ability Actor info for the Client
	InitAbilityActorInfo();
}

void AGassieCharacter::InitAbilityActorInfo()
{
	AGassiePlayerState* GassiePlayerState = GetPlayerState<AGassiePlayerState>();
	check(GassiePlayerState);
	GassiePlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(GassiePlayerState, this);
	AbilitySystemComponent = GassiePlayerState->GetAbilitySystemComponent();
	AttributeSet = GassiePlayerState->GetAttributeSet();
}
