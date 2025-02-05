// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagAssetInterface.h"
#include "UObject/Interface.h"
#include "GameplayTagCustomInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(NotBlueprintable)
class UGameplayTagCustomInterface : public UGameplayTagAssetInterface
{
	GENERATED_BODY()
	
};

class TAREA1_GAS25_API IGameplayTagCustomInterface:public IGameplayTagAssetInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable,Category="GameplayTags")
	virtual void AddTag(const FGameplayTag& InTag)=0;

	UFUNCTION(BlueprintCallable,Category="GameplayTags")
	virtual void RemoveTag(const FGameplayTag& InTag)=0;
};
