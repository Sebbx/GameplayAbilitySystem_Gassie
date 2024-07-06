// Copyright Sebastian Rubacha

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/GassieWidgetController.h"
#include "AttributeMenuWidgetController.generated.h"

class UAttributeInfo;
// 92. Attribute Info Delegate
struct FGassieAttributeInfo;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAttributeInfoSignature, const FGassieAttributeInfo&, Info);
/**
 *  89. Attribute Menu Widget Controller
 */
UCLASS(BlueprintType, Blueprintable)
class GAS_ARPG_API UAttributeMenuWidgetController : public UGassieWidgetController
{
	GENERATED_BODY()

public:
	virtual void BroadcastInitialValues() override;
	virtual void BindCallbacksToDependencies() override;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FAttributeInfoSignature AttributeInfoDelegate;

protected:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UAttributeInfo> AttributeInfo;
	
};
