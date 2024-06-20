// Copyright Sebastian Rubacha

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GassiePlayerController.generated.h"


class IEnemyInterface;
struct FInputActionValue;
class UInputAction;
class UInputMappingContext;
UCLASS()
class GAS_ARPG_API AGassiePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AGassiePlayerController();
	virtual void PlayerTick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> AuraContext;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> MoveAction;

	void Move(const FInputActionValue& InputActionValue);

	void CursorTrace();
	//Jeśli wyjebie błąd, trzeba zmienić na zwykły wskaźnik
	TScriptInterface<IEnemyInterface> LastActor;
	TScriptInterface<IEnemyInterface> ThisActor;
};
