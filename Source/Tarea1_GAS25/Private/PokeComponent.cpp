// Fill out your copyright notice in the Description page of Project Settings.


#include "PokeComponent.h"
#include "AbilitySystemPawn.h"


#define GET_ROW_ATTRIBUTE(InDataTable,InElementTag,T,RowTag)\
if (InDataTable){\
	TArray<T*> OutData;\
	InDataTable->GetAllRows<T>(TEXT(""), OutData);\
	if (!OutData.IsEmpty()){\
		T** Attr = OutData.FindByPredicate([this,InElementTag](T* Row)\
			{return Row->RowTag.MatchesTag(InElementTag);});\
			if (Attr) { return *Attr; }}};return nullptr;\



void UPokeComponent::BeginPlay()
{
	Super::BeginPlay();
	InitializePokemon();
}

void UPokeComponent::InitializePokemon()
{
	InitializePokemonAttributes();
	InitializeElementAttributes();
	InitializeAttacksAttributes();
}

void UPokeComponent::InitializePokemonAttributes()
{
	if(!PokemonData||!PokeClassTag.IsValid()) return;
	Attributes=GetPokeAttributeRow(PokemonData,PokeClassTag);
	
}


FPokeAttributeRow::FPokeAttributeRow(): CurrentHealth(1000.0f), MaxHealth(1000.0f),
BaseAttack(100), TextureColor(FColor::Black),Mesh(nullptr)
{
	
}

FPokeElementsRelationRow* UPokeComponent::GetPokeElementRow(const UDataTable* InDataTable,const FGameplayTag& InElementTagToFind) const
{
	GET_ROW_ATTRIBUTE(InDataTable,InElementTagToFind,FPokeElementsRelationRow,PrimaryElement);
}

FPokeAttributeRow* UPokeComponent::GetPokeAttributeRow(const UDataTable* InDataTable,const FGameplayTag& InElementTagToFind) const
{
	GET_ROW_ATTRIBUTE(InDataTable,InElementTagToFind,FPokeAttributeRow,PokemonClassTag);
}

FPokeAttackRow* UPokeComponent::GetPokeAttackRow(const UDataTable* InDataTable,const  FGameplayTag& InAttackNameToFind) const
{
	GET_ROW_ATTRIBUTE(InDataTable,InAttackNameToFind,FPokeAttackRow,NameAttack)

}

void UPokeComponent::InitializeElementAttributes()
{
	if(!Attributes||!MultiplierData||!Attributes->PokemonFirstElementTag.IsValid()||
		!Attributes->PokemonSecondElementTag.IsValid()) return;
	FirstElementAttributes=GetPokeElementRow(MultiplierData,Attributes->PokemonFirstElementTag);
	SecondElementAttributes=GetPokeElementRow(MultiplierData,Attributes->PokemonSecondElementTag);
}

void UPokeComponent::InitializeAttacksAttributes()
{
	if(!Attributes||!AttacksData) return;
	
	for (int i = 0; i < Attributes->PokeAttacksTags.Num(); i++)
	{
		AttackAttributes[i]=GetPokeAttackRow(AttacksData,Attributes->PokeAttacksTags[i]);
	};
	
}



FPokeAttributeRow& UPokeComponent::GetPokemonAttributes()
{
		return Attributes?*Attributes:*(new FPokeAttributeRow());
	
}

FPokeAttackRow UPokeComponent::GetAttackAttributes(int InIndex)
{
	const int Index = FMath::Clamp(InIndex, 0, 3);
	if(AttackAttributes.IsEmpty()||!AttackAttributes[Index]) return FPokeAttackRow();
	return *AttackAttributes[Index];
}

FPokeElementsRelationRow UPokeComponent::GetMultiplierAttributes(const bool InSelection) const
{
	if(!FirstElementAttributes&&!InSelection) return FPokeElementsRelationRow();
	if(!SecondElementAttributes&&InSelection) return FPokeElementsRelationRow();
	return InSelection?*SecondElementAttributes:*FirstElementAttributes;
}


