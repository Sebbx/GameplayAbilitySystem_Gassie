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
public:
	AGassieEnemy();

	/** Enemy Interface */
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	/** end Enemy Interface */

	/** Combat Interface */
	virtual int32 GetPlayerLevel() override;
	/** end Combat Interface */

protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defaults")
	int32 Level = 1;

};
