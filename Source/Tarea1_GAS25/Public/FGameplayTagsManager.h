#pragma once
#include "GameplayTagContainer.h"
#include "GameplayTagsManager.h"

#define LOAD_TAGS(ArrayTagNames,ArrayTags)\
for (int i = 0; i < ArrayTagNames.Num(); i++)\
{if(!ArrayTagNames[i].IsNone())\
ArrayTags.Add(UGameplayTagsManager::Get().AddNativeGameplayTag(ArrayTagNames[i]));}

class FGameplayTagsManager:public  FNoncopyable
{
	static FGameplayTagsManager* Singleton;
	
	TArray<FGameplayTag> CharacterClassTags;
	TArray<FGameplayTag> PokeElementsTags;
	TArray<FGameplayTag> PokeAttacksTags;
	TArray<FGameplayTag> PokeClassTags;
	
	TArray<FName> CharacterClassTagNames;
	TArray<FName> PokeElementsTagNames;
	TArray<FName> PokeAttacksTagNames;
	TArray<FName> PokeClassTagNames;

public:
	//Lazy Load
	static FGameplayTagsManager& Get()
	{
		if (!Singleton)
		{
			Singleton = new FGameplayTagsManager();
			return *Singleton;
		}
		return *Singleton;
	}

	

	void InitGameplayTags()
	{
		InitTextTags();
		InitTags();
	}

	void InitTextTags()
	{
		//CharacterClass
		CharacterClassTagNames.Add(TEXT("Gameplay.CharacterClass.Warrior"));
		CharacterClassTagNames.Add(TEXT("Gameplay.CharacterClass.Mage"));
		CharacterClassTagNames.Add(TEXT("Gameplay.CharacterClass.Archer"));
		//PokemonElements
		PokeElementsTagNames.Add(TEXT("Gameplay.PokeElement.Fire"));
		PokeElementsTagNames.Add(TEXT("Gameplay.PokeElement.Water"));
		PokeElementsTagNames.Add(TEXT("Gameplay.PokeElement.Wind"));
		PokeElementsTagNames.Add(TEXT("Gameplay.PokeElement.Earth"));
		PokeElementsTagNames.Add(TEXT("Gameplay.PokeElement.Leaf"));
		PokeElementsTagNames.Add(TEXT("Gameplay.PokeElement.Flyer"));
		//PokemonAttacks
		PokeAttacksTagNames.Add(TEXT("Gameplay.PokeAttacks.FireBlast"));
		PokeAttacksTagNames.Add(TEXT("Gameplay.PokeAttacks.Surf"));
		PokeAttacksTagNames.Add(TEXT("Gameplay.PokeAttacks.Whirlwind"));
		PokeAttacksTagNames.Add(TEXT("Gameplay.PokeAttacks.Earthquake"));
		PokeAttacksTagNames.Add(TEXT("Gameplay.PokeAttacks.VineWhip"));
		//PokemonClass
		PokeClassTagNames.Add(TEXT("Gameplay.PokeClass.Cyndaquil"));
		PokeClassTagNames.Add(TEXT("Gameplay.PokeClass.Totodile"));
		PokeClassTagNames.Add(TEXT("Gameplay.PokeClass.Chikorita"));
		PokeClassTagNames.Add(TEXT("Gameplay.PokeClass.Liten"));
		PokeClassTagNames.Add(TEXT("Gameplay.PokeClass.Sylveon"));
		PokeClassTagNames.Add(TEXT("Gameplay.PokeClass.Nidoking"));
	}
	
	void InitTags()
	{
		LOAD_TAGS(CharacterClassTagNames, CharacterClassTags);
		LOAD_TAGS(PokeClassTagNames, PokeClassTags);
		LOAD_TAGS(PokeAttacksTagNames, PokeAttacksTags);
		LOAD_TAGS(PokeElementsTagNames, PokeElementsTags);
		
	}

	TArray<FGameplayTag>& GetAllElementsTags(){return PokeElementsTags;}
	
};
