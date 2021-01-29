// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameJamGameMode.h"
#include "GameJamHUD.h"
#include "GameJamCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGameJamGameMode::AGameJamGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AGameJamHUD::StaticClass();
}
