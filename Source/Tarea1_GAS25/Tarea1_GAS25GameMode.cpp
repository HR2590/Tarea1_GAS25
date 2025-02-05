// Copyright Epic Games, Inc. All Rights Reserved.

#include "Tarea1_GAS25GameMode.h"
#include "Tarea1_GAS25PlayerController.h"
#include "Tarea1_GAS25Character.h"
#include "UObject/ConstructorHelpers.h"

ATarea1_GAS25GameMode::ATarea1_GAS25GameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ATarea1_GAS25PlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}