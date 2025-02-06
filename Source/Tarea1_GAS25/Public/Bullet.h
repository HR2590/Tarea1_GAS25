// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PokeAttack.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

UCLASS()
class TAREA1_GAS25_API ABullet : public AActor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Movement",meta=(AllowPrivateAccess=true))float Speed=300.0f;
	UPROPERTY(VisibleAnywhere, Category = "Components",meta=(AllowPrivateAccess=true)) UStaticMeshComponent* MeshComponent;
public:
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	ABullet();
	UFUNCTION(BlueprintCallable)void Initialize(const FGameplayTag& InAttackElement,int InDamage);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	FVector Direction;
	FGameplayTag AttackElement;
	int Damage;
	void MoveForward(float DeltaTime);
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	

};
