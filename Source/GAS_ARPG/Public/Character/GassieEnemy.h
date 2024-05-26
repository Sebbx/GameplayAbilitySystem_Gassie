// Copyright Sebastian Rubacha

#pragma once

#include "CoreMinimal.h"
#include "Character/GassieCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "GassieEnemy.generated.h"


UCLASS()
class GAS_ARPG_API AGassieEnemy : public AGassieCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()
	AGassieEnemy();

	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;

public:
	UPROPERTY(BlueprintReadOnly)
	bool bHighLighted = false;
};
