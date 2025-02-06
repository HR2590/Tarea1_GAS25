// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "PokeAttack.h"
#include "Components/ActorComponent.h"
#include "PokeComponent.generated.h"

USTRUCT(Blueprintable, BlueprintType)
struct FPokeAttributeRow:public FTableRowBase
{
	GENERATED_BODY()
	FPokeAttributeRow();
	UPROPERTY(EditAnywhere,BlueprintReadWrite) FName DisplayName;
	UPROPERTY(EditAnywhere,BlueprintReadWrite) FGameplayTag PokemonClassTag;	
	UPROPERTY(EditAnywhere,BlueprintReadWrite) FGameplayTag PokemonFirstElementTag;	
	UPROPERTY(EditAnywhere,BlueprintReadWrite) FGameplayTag PokemonSecondElementTag;	
	UPROPERTY(EditAnywhere,BlueprintReadWrite) float CurrentHealth;	
	UPROPERTY(EditAnywhere,BlueprintReadWrite) float MaxHealth;	
	UPROPERTY(EditAnywhere,BlueprintReadWrite) float BaseAttack;	
	UPROPERTY(EditAnywhere,BlueprintReadWrite) TArray<FGameplayTag> PokeAttacksTags;
	UPROPERTY(EditAnywhere,BlueprintReadWrite) FColor TextureColor;
	UPROPERTY(EditAnywhere,BlueprintReadWrite) UStaticMesh* Mesh;

};
UCLASS(ClassGroup=(PokeComponent), meta=(BlueprintSpawnableComponent))
class TAREA1_GAS25_API UPokeComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

protected:
	FPokeAttributeRow* Attributes;
	FPokeElementsRelationRow* FirstElementAttributes;
	FPokeElementsRelationRow* SecondElementAttributes;
	TStaticArray<FPokeAttackRow*,4> AttackAttributes;

	FPokeElementsRelationRow* GetPokeElementRow(const UDataTable* InDataTable,const FGameplayTag& InElementTagToFind) const;
	FPokeAttributeRow* GetPokeAttributeRow(const UDataTable* InDataTable,const FGameplayTag& InElementTagToFind) const;
	FPokeAttackRow* GetPokeAttackRow(const UDataTable* InDataTable,const FGameplayTag& InAttackNameToFind) const;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta=(AllowPrivateAccess=true))FGameplayTag PokeClassTag;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta=(AllowPrivateAccess=true))UDataTable* PokemonData;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta=(AllowPrivateAccess=true))UDataTable* AttacksData;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta=(AllowPrivateAccess=true))UDataTable* MultiplierData;
public:
	UFUNCTION(BlueprintCallable)void InitializePokemon();
	UFUNCTION(BlueprintCallable)void InitializePokemonAttributes();
	UFUNCTION(BlueprintCallable)void InitializeElementAttributes();
	UFUNCTION(BlueprintCallable)void InitializeAttacksAttributes();
	
	UFUNCTION(BlueprintCallable)FPokeAttributeRow& GetPokemonAttributes() const;
	UFUNCTION(BlueprintCallable)FPokeAttackRow GetAttackAttributes(int InIndex);
	UFUNCTION(BlueprintCallable)FPokeElementsRelationRow GetMultiplierAttributes(const bool InSelection) const;

	virtual void BeginPlay() override;
};
