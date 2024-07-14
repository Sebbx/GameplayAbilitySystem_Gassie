// Copyright Sebastian Rubacha

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GassiePlayerController.generated.h"


class USplineComponent;
class UGassieAbilitySystemComponent;
struct FGameplayTag;
class UGassieInputConfig;
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
	FHitResult CursorHit;

	void AbilityInputTagPressed(FGameplayTag InputTag); //101. Callbacks for Ability Input
	void AbilityInputTagReleased(FGameplayTag InputTag);
	void AbilityInputTagHeld(FGameplayTag InputTag);
	
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UGassieInputConfig> InputConfig;

	TObjectPtr<UGassieAbilitySystemComponent> GassieAbilitySystemComponent;

	UGassieAbilitySystemComponent* GetASC();

	FVector CachedDestination = FVector::ZeroVector; //104. Setting Up Click to Move
	float FollowTime = 0.f;
	float ShortPressThreshold = 0.5f;
	bool bAutoRunning= false;
	bool bTargeting = false;

	UPROPERTY(EditDefaultsOnly)
	float AutoRunAcceptanceRadius = 50.f;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USplineComponent> Spline;

	void AutoRun();
	
};
