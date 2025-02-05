// Copyright Epic Games, Inc. All Rights Reserved.

#include "Tarea1_GAS25Character.h"

#include "AbilitySystemPawn.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "Materials/Material.h"
#include "Engine/World.h"

ATarea1_GAS25Character::ATarea1_GAS25Character()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	AbilityComponent=CreateDefaultSubobject<UAbilitySystemPawn>(TEXT("AbilityComponent"));
	
}

void ATarea1_GAS25Character::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
}

void ATarea1_GAS25Character::AddTag(const FGameplayTag& InTag)
{
}

void ATarea1_GAS25Character::RemoveTag(const FGameplayTag& InTag)
{
}

void ATarea1_GAS25Character::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const
{
}

void ATarea1_GAS25Character::Attack()
{
	check(!AbilityComponent);
	if(const TSubclassOf<UAttackBase> PrimaryAttack=AbilityComponent->GetAttributes().PrimaryAttack)
	{
		PrimaryAttack->GetDefaultObject<UAttackBase>()->TryAttack();
	}
}



