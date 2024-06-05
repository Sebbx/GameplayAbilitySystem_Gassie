#pragma once

#include "CoreMinimal.h"
#include "Character/GassieCharacterBase.h"
#include "GassieCharacter.generated.h"

UCLASS()
class GAS_ARPG_API AGassieCharacter : public AGassieCharacterBase
{
	GENERATED_BODY()
public:
	AGassieCharacter();
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

private:
	virtual void InitAbilityActorInfo() override;
	
};
