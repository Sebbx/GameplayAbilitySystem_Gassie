// Copyright Sebastian Rubacha


#include "UI/Widget/GassieUserWidget.h"

void UGassieUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
