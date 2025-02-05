// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameplayTagContainer.h"
#include "Public/GameplayTagCustomInterface.h"
#include "Tarea1_GAS25Character.generated.h"


class UAbilitySystemPawn;

UCLASS(Blueprintable)
class ATarea1_GAS25Character : public ACharacter,public IGameplayTagCustomInterface
{
	GENERATED_BODY()

public:
	ATarea1_GAS25Character();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;
	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	UFUNCTION(BlueprintCallable,Category="GameplayTags")
	virtual void AddTag(const FGameplayTag& InTag) override;
	UFUNCTION(BlueprintCallable,Category="GameplayTags")
	virtual void RemoveTag(const FGameplayTag& InTag) override;
	UFUNCTION(BlueprintCallable,Category="GameplayTags")
	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UAbilitySystemPawn* AbilityComponent;

	UFUNCTION(BlueprintCallable)
	void Attack();
	
private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;
};

