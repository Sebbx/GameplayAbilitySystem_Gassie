// Copyright Sebastian Rubacha

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GassieHUD.generated.h"

class UAttributeMenuWidgetController;
class UAttributeSet;
class UAbilitySystemComponent;
struct FWidgetControllerParams;
class UOverlayWidgetController;
class UGassieUserWidget;
/**
 * 
 */
UCLASS()
class GAS_ARPG_API AGassieHUD : public AHUD
{
	GENERATED_BODY()
public:

	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);
	UAttributeMenuWidgetController* GetAttributeMenuWidgetController (const FWidgetControllerParams& WCParams);

	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);

private:
	UPROPERTY()
	TObjectPtr<UGassieUserWidget> OverlayWidget;

	UPROPERTY()
	TObjectPtr<UAttributeMenuWidgetController> AttributeMenuWidget;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> OverlayWidgetClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> AttributeMenuWidgetClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UAttributeMenuWidgetController> AttributeMenuWidgetControllerClass;

	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	TObjectPtr<UAttributeMenuWidgetController> AttributeMenuWidgetController;
};
