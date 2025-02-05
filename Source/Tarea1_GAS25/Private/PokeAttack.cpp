// Fill out your copyright notice in the Description page of Project Settings.


#include "PokeAttack.h"
#include "Bullet.h"
#include "FGameplayTagsManager.h"


FPokeMultiplierRow::FPokeMultiplierRow():Multiplier(0.0f){}

FPokeMultiplierRow::FPokeMultiplierRow(const FGameplayTag& InElement, const float& InMultiplier)
{
	SecondElementTag=InElement;
	Multiplier=InMultiplier;
}

FPokeElementsRelationRow::FPokeElementsRelationRow()
{
	TArray<FGameplayTag> AllElements= FGameplayTagsManager::Get().GetAllElementsTags();
	if (AllElements.IsEmpty()) return;
	for (const auto& InElement : AllElements)
	{
		Elements.Add(FPokeMultiplierRow(InElement,0.0f));
	}
}



void UPokeAttackBase::Attack(const FTransform& InTransform,UWorld* InWorld,const FGameplayTag& InAttackElement, const int Damage)
{
	if (!InWorld)return;
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Black, TEXT("AttackBase"));
	const FVector SpawnLocation = InTransform.GetLocation();
	const FRotator SpawnRotation = InTransform.GetRotation().Rotator();
	ABullet* Bullet=InWorld->SpawnActor<ABullet>(SpawnLocation, SpawnRotation);
	Bullet->Initialize(InAttackElement,Damage);
}

void UPokeAttackFire::Attack(const FTransform& InTransform,UWorld* InWorld,const FGameplayTag& InAttackElement, const int Damage)
{
	if (!InWorld)return;
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, TEXT("AttackFire"));
	const FVector SpawnLocation = InTransform.GetLocation() ;
	const FRotator SpawnRotation = InTransform.GetRotation().Rotator();
	ABullet* Bullet=InWorld->SpawnActor<ABullet>(SpawnLocation, SpawnRotation);
	Bullet->Initialize(InAttackElement,Damage);
}

void UPokeAttackWater::Attack(const FTransform& InTransform,UWorld* InWorld,const FGameplayTag& InAttackElement, const int Damage)
{
	if (!InWorld)return;
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, TEXT("AttackWater"));
	const FVector SpawnLocation = InTransform.GetLocation() ;
	const FRotator SpawnRotation = InTransform.GetRotation().Rotator();
	ABullet* Bullet=InWorld->SpawnActor<ABullet>(SpawnLocation, SpawnRotation);
	Bullet->Initialize(InAttackElement,Damage);
}

void UPokeAttackEarth::Attack(const FTransform& InTransform,UWorld* InWorld,const FGameplayTag& InAttackElement, const int Damage)
{
	if (!InWorld)return;
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green, TEXT("AttackEarth"));
	const FVector SpawnLocation = InTransform.GetLocation() ;
	const FRotator SpawnRotation = InTransform.GetRotation().Rotator();
	ABullet* Bullet=InWorld->SpawnActor<ABullet>(SpawnLocation, SpawnRotation);
	Bullet->Initialize(InAttackElement,Damage);
}

void UPokeAttackWind::Attack(const FTransform& InTransform,UWorld* InWorld,const FGameplayTag& InAttackElement, const int Damage)
{
	if (!InWorld)return;
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Emerald, TEXT("AttackWind"));
	const FVector SpawnLocation = InTransform.GetLocation() ;
	const FRotator SpawnRotation = InTransform.GetRotation().Rotator();
	ABullet* Bullet=InWorld->SpawnActor<ABullet>(SpawnLocation, SpawnRotation);
	Bullet->Initialize(InAttackElement,Damage);
}

void UPokeAttackLeaf::Attack(const FTransform& InTransform,UWorld* InWorld,const FGameplayTag& InAttackElement, const int Damage)
{
	if (!InWorld)return;
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("AttackLeaf"));
	const FVector SpawnLocation = InTransform.GetLocation() ;
	const FRotator SpawnRotation = InTransform.GetRotation().Rotator();
	ABullet* Bullet=InWorld->SpawnActor<ABullet>(SpawnLocation, SpawnRotation);
	Bullet->Initialize(InAttackElement,Damage);
}



