// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttackBase.h"
#include "Containers/StaticArray.h"
#include "AbilitySystemPawn.generated.h"


USTRUCT(Blueprintable, BlueprintType)
struct FCharacterAttributes:public FTableRowBase
{
	GENERATED_BODY()
	FCharacterAttributes();
	UPROPERTY(EditAnywhere,BlueprintReadWrite) FGameplayTag CharacterClass;	
	UPROPERTY(EditAnywhere,BlueprintReadWrite) float Health;	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)  float AttackStrength;	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)  float Speed;	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)  UAnimMontage* AttackAnimation;
	UPROPERTY(EditAnywhere,BlueprintReadWrite) TSubclassOf<UAttackBase> PrimaryAttack;


};

/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TAREA1_GAS25_API UAbilitySystemPawn : public UAbilitySystemComponent
{
	GENERATED_BODY()
	FCharacterAttributes* Attributes;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta=(AllowPrivateAccess=true)) FGameplayTag ClassTag;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta=(AllowPrivateAccess=true))UDataTable* CharacterData;
public:
	void InitializeCharacter();
	// Sets default values for this component's properties
	virtual void InitAbilityActorInfo(AActor* InOwnerActor, AActor* InAvatarActor) override;
	UFUNCTION(BlueprintCallable)FCharacterAttributes GetAttributes() const;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	





};
