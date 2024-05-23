// Copyright Sebastian Rubacha

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GassiePlayerController.generated.h"


class UInputMappingContext;
UCLASS()
class GAS_ARPG_API AGassiePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AGassiePlayerController();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> AuraContext;
};
