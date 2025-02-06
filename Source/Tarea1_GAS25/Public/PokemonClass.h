// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagCustomInterface.h"
#include "InputAction.h"
#include "PokeComponent.h"
#include "GameFramework/Character.h"
#include "PokemonClass.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UWidgetComponent;
class UInputMappingContext;
class UAbilitySystemPawn;

UCLASS(Blueprintable)
class TAREA1_GAS25_API APokemonClass : public ACharacter,public IGameplayTagCustomInterface
{
	GENERATED_BODY()
	
	//Input Mapping
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="InputMapping",meta=(AllowPrivateAccess=true))
	UInputMappingContext* DefaultMappingContext;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="InputMapping",meta=(AllowPrivateAccess=true))
	UInputAction* BaseAttackInput;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="InputMapping",meta=(AllowPrivateAccess=true))
	UInputAction* Attack1Input;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="InputMapping",meta=(AllowPrivateAccess=true))
	UInputAction* Attack2Input;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="InputMapping",meta=(AllowPrivateAccess=true))
	UInputAction* Attack3Input;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="InputMapping",meta=(AllowPrivateAccess=true))
	UInputAction* Attack4Input;
	//Poke Component
	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta=(AllowPrivateAccess=true))UWidgetComponent* HealthBarWidget;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta=(AllowPrivateAccess=true))UStaticMeshComponent* PokemonMesh;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta=(AllowPrivateAccess=true))UArrowComponent* SpawnAttackLocation;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta=(AllowPrivateAccess=true))UPokeComponent* AbilityComponent;
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* TopDownCameraComponent;
	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;
	//Setup Player
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	//Poke Attack
	UPROPERTY()UPokeAttackBase* AttackObject;
public:
	APokemonClass();
	//** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	
	//Functions to interact
	UFUNCTION(BlueprintCallable)void Attack(const int InIndex);
	UFUNCTION(BlueprintCallable)void ReceiveDamage(const FGameplayTag& AttackElement,const float& Damage);
	UFUNCTION(BlueprintImplementableEvent,Category="UpdateHUD")void OnUpdateHealthHUD(const float& Health);
	UFUNCTION(BlueprintCallable)void AddMappingContext() const;

	
//Future Features
	virtual void AddTag(const FGameplayTag& InTag) override;
	virtual void RemoveTag(const FGameplayTag& InTag) override;
	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;

	//begin Play
	virtual void BeginPlay() override;


	
	
};
