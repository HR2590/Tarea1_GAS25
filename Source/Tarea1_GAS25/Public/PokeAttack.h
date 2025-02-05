
#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Object.h"
#include "PokeAttack.generated.h"

class UPokeAttackBase;

USTRUCT(Blueprintable,BlueprintType)
struct FPokeElementVisual:public FTableRowBase
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,BlueprintReadWrite)FGameplayTag ElementTag;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)TSoftObjectPtr<UTexture2D> IconElement;
};


USTRUCT(Blueprintable,BlueprintType)
struct FPokeMultiplierRow
{
	GENERATED_BODY()
	FPokeMultiplierRow();
	FPokeMultiplierRow(const FGameplayTag& InElement,const float& InMultiplier);
	UPROPERTY(EditAnywhere,BlueprintReadWrite) FGameplayTag SecondElementTag;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)float Multiplier;

};

USTRUCT(Blueprintable,BlueprintType)
struct FPokeElementsRelationRow:public FTableRowBase
{
	GENERATED_BODY()
	FPokeElementsRelationRow();
	UPROPERTY(EditAnywhere,BlueprintReadWrite) FGameplayTag PrimaryElement;
	UPROPERTY(EditAnywhere,BlueprintReadWrite) TArray<FPokeMultiplierRow> Elements;
};

USTRUCT(Blueprintable,BlueprintType)
struct FPokeAttackRow:public FTableRowBase
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,BlueprintReadWrite) FGameplayTag NameAttack;
	UPROPERTY(EditAnywhere,BlueprintReadWrite) FGameplayTag PrimaryElement;
	UPROPERTY(EditAnywhere,BlueprintReadWrite) float Damage = 100.0f;
	UPROPERTY(EditAnywhere,BlueprintReadWrite) int NumberOfUses = 10;
	UPROPERTY(EditAnywhere,BlueprintReadWrite) TSubclassOf<UPokeAttackBase> Attack;
};

UCLASS(Blueprintable,BlueprintType)
class TAREA1_GAS25_API UPokeAttackBase : public UObject
{
	GENERATED_BODY()

public:
	virtual void Attack(const FTransform& InTransform,UWorld* InWorld,const FGameplayTag& InAttackElement,int Damage);
	
};


UCLASS(Blueprintable,BlueprintType)
class TAREA1_GAS25_API UPokeAttackFire : public UPokeAttackBase 
{
	GENERATED_BODY()

public:
	virtual void Attack(const FTransform& InTransform,UWorld* InWorld,const FGameplayTag& InAttackElement,int Damage) override;
	
};

UCLASS(Blueprintable,BlueprintType)
class TAREA1_GAS25_API UPokeAttackWater : public UPokeAttackBase 
{
	GENERATED_BODY()

public:
	virtual void Attack(const FTransform& InTransform,UWorld* InWorld,const FGameplayTag& InAttackElement,int Damage) override;
	
};

UCLASS(Blueprintable,BlueprintType)
class TAREA1_GAS25_API UPokeAttackEarth : public UPokeAttackBase 
{
	GENERATED_BODY()

public:
	virtual void Attack(const FTransform& InTransform,UWorld* InWorld,const FGameplayTag& InAttackElement,int Damage) override;
	
};
UCLASS(Blueprintable,BlueprintType)
class TAREA1_GAS25_API UPokeAttackWind : public UPokeAttackBase 
{
	GENERATED_BODY()

public:
	virtual void Attack(const FTransform& InTransform,UWorld* InWorld,const FGameplayTag& InAttackElement,int Damage) override;
	
};
UCLASS(Blueprintable,BlueprintType)
class TAREA1_GAS25_API UPokeAttackLeaf: public UPokeAttackBase 
{
	GENERATED_BODY()

public:
	virtual void Attack(const FTransform& InTransform,UWorld* InWorld,const FGameplayTag& InAttackElement,int Damage) override;
	
};