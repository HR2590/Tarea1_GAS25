// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AttackBase.generated.h"

/**
 * 
 */
UCLASS()
class TAREA1_GAS25_API UAttackBase : public UObject
{
	GENERATED_BODY()
public:
	virtual void TryAttack();
};
UCLASS()
class TAREA1_GAS25_API UAttackWarrior : public UAttackBase
{
	GENERATED_BODY()
public:
	virtual void TryAttack() override;
};

UCLASS()
class TAREA1_GAS25_API UAttackMage : public UAttackBase
{
	GENERATED_BODY()
public:
	virtual void TryAttack() override;
};
UCLASS()
class TAREA1_GAS25_API UAttackArcher : public UAttackBase
{
	GENERATED_BODY()
public:
	virtual void TryAttack() override;
};


