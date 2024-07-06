// Copyright Sebastian Rubacha


#include "AbilitySystem/GassieAbilitySystemLibrary.h"

#include "Kismet/GameplayStatics.h"
#include "Player/GassiePlayerState.h"
#include "UI/HUD/GassieHUD.h"
#include "UI/WidgetController/GassieWidgetController.h"

UOverlayWidgetController* UGassieAbilitySystemLibrary::GetOverlayWidgetController(const UObject* WorldContextObject)
{
	APlayerController* PC =  UGameplayStatics::GetPlayerController(WorldContextObject, 0);
	{
		if (AGassieHUD* GassieHUD = Cast<AGassieHUD>(PC->GetHUD()))
		{
			AGassiePlayerState* PS = PC->GetPlayerState<AGassiePlayerState>();
			UAbilitySystemComponent* ASC =  PS->GetAbilitySystemComponent();
			UAttributeSet* AS = PS->GetAttributeSet();
			const FWidgetControllerParams WidgetControllerParams (PC, PS, ASC, AS);
			return GassieHUD->GetOverlayWidgetController(WidgetControllerParams);
		}
	}
	return nullptr;
}

UAttributeMenuWidgetController* UGassieAbilitySystemLibrary::GetAttributeMenuWidgetController(const UObject* WorldContextObject)
{
	APlayerController* PC =  UGameplayStatics::GetPlayerController(WorldContextObject, 0);
	{
		if (AGassieHUD* GassieHUD = Cast<AGassieHUD>(PC->GetHUD()))
		{
			AGassiePlayerState* PS = PC->GetPlayerState<AGassiePlayerState>();
			UAbilitySystemComponent* ASC =  PS->GetAbilitySystemComponent();
			UAttributeSet* AS = PS->GetAttributeSet();
			const FWidgetControllerParams WidgetControllerParams (PC, PS, ASC, AS);
			return GassieHUD->GetAttributeMenuWidgetController(WidgetControllerParams);
		}
	}
	return nullptr;
}
