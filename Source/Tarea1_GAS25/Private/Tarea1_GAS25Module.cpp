// Fill out your copyright notice in the Description page of Project Settings.


#include "Tarea1_GAS25/Public/Tarea1_GAS25Module.h"
#include "FGameplayTagsManager.h"
#include "GameplayTagsManager.h"


IMPLEMENT_MODULE(Tarea1_GAS25Module, Tarea1_GAS25Module)
DEFINE_LOG_CATEGORY(LogGASUTHUB25)


void Tarea1_GAS25Module::StartupModule()
{
	UGameplayTagsManager::OnLastChanceToAddNativeTags().AddLambda([]()
	{
		FGameplayTagsManager::Get().InitGameplayTags();
	
	});
}

// Add default functionality here for any ITarea1_GAS25Module functions that are not pure virtual.
void Tarea1_GAS25Module::ShutdownModule()
{
	IModuleInterface::ShutdownModule();
}
