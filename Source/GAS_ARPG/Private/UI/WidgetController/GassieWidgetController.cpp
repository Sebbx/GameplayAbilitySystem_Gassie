// Copyright Sebastian Rubacha


#include "UI/WidgetController/GassieWidgetController.h"

void UGassieWidgetController::SetWidgetControllerParams(const FWidgetControllerParams WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void UGassieWidgetController::BroadcastInitialValues()
{
	
}

void UGassieWidgetController::BindCallbacksToDependencies()
{
	
}
