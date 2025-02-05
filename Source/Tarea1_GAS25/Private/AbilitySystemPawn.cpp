// Fill out your copyright notice in the Description page of Project Settings.


#include "Tarea1_GAS25/Public/AbilitySystemPawn.h"


FCharacterAttributes::FCharacterAttributes(): Health(1000.0f), AttackStrength(100.0f), Speed(50.0f), AttackAnimation(nullptr)
{
}

void UAbilitySystemPawn::InitializeCharacter()
{

		if(CharacterData)
		{
			TArray<FCharacterAttributes*> OutData;
			CharacterData->GetAllRows(TEXT(""),OutData);
		
			if(!OutData.IsEmpty())
			{
				auto Lambda= [this](const FCharacterAttributes* Row)
				{
					return Row->CharacterClass.MatchesTag(ClassTag);	
				};
				FCharacterAttributes** Attr=OutData.FindByPredicate(Lambda);

				if(Attr)
				{
					Attributes=*Attr;
				}
				
			}
		
		}
	}




void UAbilitySystemPawn::InitAbilityActorInfo(AActor* InOwnerActor, AActor* InAvatarActor)
{
	Super::InitAbilityActorInfo(InOwnerActor, InAvatarActor);
}

void UAbilitySystemPawn::BeginPlay()
{
	Super::BeginPlay();
	InitializeCharacter();
}

FCharacterAttributes UAbilitySystemPawn::GetAttributes() const
{
	check(!Attributes);
	return *Attributes;
}
