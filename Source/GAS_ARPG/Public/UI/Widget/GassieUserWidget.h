// Copyright Sebastian Rubacha

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GassieUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class GAS_ARPG_API UGassieUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
	
};
