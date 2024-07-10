// Copyright Sebastian Rubacha

#include "Player/GassiePlayerController.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "EnhancedInputSubsystems.h"
#include "GameplayTagContainer.h"
#include "GassieGameplayTags.h"
#include "NavigationPath.h"
#include "NavigationSystem.h"
#include "AbilitySystem/GassieAbilitySystemComponent.h"
#include "Components/SplineComponent.h"
#include "Input/GassieInputComponent.h"
#include "Interaction/EnemyInterface.h"

AGassiePlayerController::AGassiePlayerController()
{
	bReplicates = true;

	Spline = CreateDefaultSubobject<USplineComponent>("Spline");
}

void AGassiePlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(AuraContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if(Subsystem)
	{
		Subsystem->AddMappingContext(AuraContext, 0);
	}

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void AGassiePlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
}

void AGassiePlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;

	LastActor = ThisActor;
	ThisActor = CursorHit.GetActor();

	if(!LastActor)
	{
		if (ThisActor)
		{
			ThisActor->HighlightActor();
		}
	}
	else
	{
		if (!ThisActor)
		{
			LastActor->UnHighlightActor();
		}
		else
		{
			if (LastActor != ThisActor)
			{
				LastActor->UnHighlightActor();
				ThisActor->HighlightActor();
			}
		}
	}
}

void AGassiePlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

void AGassiePlayerController::AbilityInputTagPressed(FGameplayTag InputTag) //104.
{
	if (InputTag.MatchesTagExact(FGassieGameplayTags::Get().InputTag_LMB))
	{
		bTargeting = ThisActor ? true : false;
		bAutoRunning = false;
	}
}

void AGassiePlayerController::AbilityInputTagReleased(FGameplayTag InputTag) //105.
{
	if (!InputTag.MatchesTagExact(FGassieGameplayTags::Get().InputTag_LMB))
	{
		GetASC()->AbilityInputTagReleased(InputTag);
		return;
	}

	if (bTargeting)
	{
		if (InputTag.MatchesTagExact(FGassieGameplayTags::Get().InputTag_LMB))
		{
			GetASC()->AbilityInputTagReleased(InputTag);
		}
	}

	else
	{
		APawn* ControlledPawn = GetPawn();
		if (FollowTime <= ShortPressThreshold && ControlledPawn)
		{
			if (UNavigationPath* NavPath = UNavigationSystemV1::FindPathToLocationSynchronously(this, ControlledPawn->GetActorLocation(), CachedDestination))
			{
				Spline->ClearSplinePoints();
				for(const FVector& PointLoc : NavPath->PathPoints)
				{
					Spline->AddSplinePoint(PointLoc, ESplineCoordinateSpace::World);
					DrawDebugSphere(GetWorld(), PointLoc, 8.f, 8, FColor::Green, false, 5.f);
				}
				bAutoRunning = true;
			}
		}
		FollowTime = 0.f;
		bTargeting = false;
	}
}

void AGassiePlayerController::AbilityInputTagHeld(FGameplayTag InputTag) //104.
{
	if (!InputTag.MatchesTagExact(FGassieGameplayTags::Get().InputTag_LMB))
	{
		GetASC()->AbilityInputTagHeld(InputTag);
		return;
	}
	
	if (bTargeting)
	{
		if (InputTag.MatchesTagExact(FGassieGameplayTags::Get().InputTag_LMB))
		{
			GetASC()->AbilityInputTagHeld(InputTag);
		}
	}

	else
	{
		FollowTime += GetWorld()->GetDeltaSeconds();

		FHitResult Hit;
		if (GetHitResultUnderCursor(ECC_Visibility, false, Hit))
		{
			CachedDestination = Hit.ImpactPoint;
		}

		if (APawn* ControlledPawn = GetPawn())
		{
			const FVector WorldDirection = (CachedDestination - ControlledPawn->GetActorLocation()).GetSafeNormal();
			ControlledPawn->AddMovementInput(WorldDirection);
		}
	}
}

UGassieAbilitySystemComponent* AGassiePlayerController::GetASC()
{
	if (GassieAbilitySystemComponent == nullptr)
	{
		GassieAbilitySystemComponent = Cast<UGassieAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetPawn<APawn>()));
	}
	return GassieAbilitySystemComponent;
}

void AGassiePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UGassieInputComponent* GassieInputComponent =  CastChecked<UGassieInputComponent>(InputComponent);
	GassieInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AGassiePlayerController::Move);
	GassieInputComponent->BindAbilityActions(InputConfig, this, &ThisClass::AbilityInputTagPressed, &ThisClass::AbilityInputTagReleased, &ThisClass::AbilityInputTagHeld);
}
