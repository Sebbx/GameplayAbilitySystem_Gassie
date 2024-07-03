// Copyright Sebastian Rubacha


#include "GassieAssetManager.h"
#include "GassieGameplayTags.h"

UGassieAssetManager& UGassieAssetManager::Get()
{
	check (GEngine)
	UGassieAssetManager* GassieAssetManager = Cast<UGassieAssetManager>(GEngine->AssetManager);
	return *GassieAssetManager;
}

void UGassieAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	FGassieGameplayTags::InitializeNativeGameplayTags();
}
