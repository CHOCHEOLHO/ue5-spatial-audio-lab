// Copyright Epic Games, Inc. All Rights Reserved.


#include "ue5spatialaudiolabPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "ue5spatialaudiolabCameraManager.h"
#include "Blueprint/UserWidget.h"
#include "ue5spatialaudiolab.h"
#include "Widgets/Input/SVirtualJoystick.h"

Aue5spatialaudiolabPlayerController::Aue5spatialaudiolabPlayerController()
{
	// set the player camera manager class
	PlayerCameraManagerClass = Aue5spatialaudiolabCameraManager::StaticClass();
}

void Aue5spatialaudiolabPlayerController::BeginPlay()
{
	Super::BeginPlay();

	
	// only spawn touch controls on local player controllers
	if (SVirtualJoystick::ShouldDisplayTouchInterface() && IsLocalPlayerController())
	{
		// spawn the mobile controls widget
		MobileControlsWidget = CreateWidget<UUserWidget>(this, MobileControlsWidgetClass);

		if (MobileControlsWidget)
		{
			// add the controls to the player screen
			MobileControlsWidget->AddToPlayerScreen(0);

		} else {

			UE_LOG(Logue5spatialaudiolab, Error, TEXT("Could not spawn mobile controls widget."));

		}

	}
}

void Aue5spatialaudiolabPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// only add IMCs for local player controllers
	if (IsLocalPlayerController())
	{
		// Add Input Mapping Context
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
			{
				Subsystem->AddMappingContext(CurrentContext, 0);
			}

			// only add these IMCs if we're not using mobile touch input
			if (!SVirtualJoystick::ShouldDisplayTouchInterface())
			{
				for (UInputMappingContext* CurrentContext : MobileExcludedMappingContexts)
				{
					Subsystem->AddMappingContext(CurrentContext, 0);
				}
			}
		}
	}
	
}
