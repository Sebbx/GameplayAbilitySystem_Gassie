// Copyright Sebastian Rubacha

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/GassieWidgetController.h"
#include "AttributeMenuWidgetController.generated.h"

/**
 *  89. Attribute Menu Widget Controller
 */
UCLASS()
class GAS_ARPG_API UAttributeMenuWidgetController : public UGassieWidgetController
{
	GENERATED_BODY()
	
	virtual void BroadcastInitialValues() override;
	virtual void BindCallbacksToDependencies() override;
	
};
