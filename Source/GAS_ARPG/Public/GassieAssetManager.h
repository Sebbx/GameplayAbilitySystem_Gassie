// Copyright Sebastian Rubacha

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "GassieAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class GAS_ARPG_API UGassieAssetManager : public UAssetManager
{
	GENERATED_BODY()
public:

	static UGassieAssetManager& Get();

protected:

	virtual void StartInitialLoading() override;
};
