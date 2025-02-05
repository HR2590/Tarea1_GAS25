// Fill out your copyright notice in the Description page of Project Settings.


#include "PokemonClass.h"

#include "AbilitySystemPawn.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/WidgetComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

#define GET_POKE_MULTIPLIER(AttackData,TargetTag)\
	AttackData.Elements.FindByPredicate([this,TargetTag](const FPokeMultiplierRow& Element){\
	return Element.SecondElementTag.MatchesTag(TargetTag);});

class UEnhancedInputLocalPlayerSubsystem;

APokemonClass::APokemonClass()
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

	AbilityComponent=CreateDefaultSubobject<UPokeComponent>(TEXT("PokemonComponent"));
	HealthBarWidget=CreateDefaultSubobject<UWidgetComponent>(TEXT("Widget"));
	HealthBarWidget->SetupAttachment(RootComponent);

	PokemonMesh=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PokemonMesh"));
	PokemonMesh->SetupAttachment(RootComponent);

	SpawnAttackLocation=CreateDefaultSubobject<UArrowComponent>(TEXT("AttackSpawnLocation"));
	SpawnAttackLocation->SetupAttachment(RootComponent);
}

void APokemonClass::Attack(const int InIndex)
{
	const int Index=FMath::Clamp(InIndex,0,3);
	if(!AbilityComponent)return;
	if(AbilityComponent->GetAttackAttributes(Index).NumberOfUses>0)
	{
		
		AbilityComponent->GetAttackAttributes(Index).
		Attack->GetDefaultObject<UPokeAttackBase>()->
		Attack(SpawnAttackLocation->GetComponentTransform(),GetWorld(),
			AbilityComponent->GetAttackAttributes(Index).PrimaryElement,
			AbilityComponent->GetAttackAttributes(Index).Damage);
	}
		
	
}

void APokemonClass::ReceiveDamage(const FGameplayTag& AttackElement, const float& Damage)
{
	if(!AttackElement.IsValid()||!AbilityComponent)return;
	
	FPokeElementsRelationRow Row=AbilityComponent->GetMultiplierAttributes(false);
	const FPokeMultiplierRow* FirstMultiplier=GET_POKE_MULTIPLIER(Row,AttackElement);

	Row=AbilityComponent->GetMultiplierAttributes(true);
	const FPokeMultiplierRow* SecondMultiplier=GET_POKE_MULTIPLIER(Row,AttackElement);

	float CurrentHealth=AbilityComponent->GetPokemonAttributes().CurrentHealth;
	const float MaxHealth=AbilityComponent->GetPokemonAttributes().MaxHealth;
	CurrentHealth=CurrentHealth-((FirstMultiplier->Multiplier+SecondMultiplier->Multiplier)*Damage);
	
	AbilityComponent->GetPokemonAttributes().CurrentHealth=FMath::Clamp(CurrentHealth,0.0f,MaxHealth);
	CurrentHealth=AbilityComponent->GetPokemonAttributes().CurrentHealth/MaxHealth;
	OnUpdateHealthHUD(CurrentHealth);
}

void APokemonClass::AddMappingContext() const
{
	if (const APlayerController* PlayerController=Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* InputSystem=ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			InputSystem->AddMappingContext(DefaultMappingContext,0);
		}
	}
}



void APokemonClass::BeginPlay()
{
	Super::BeginPlay();
	AddMappingContext();
}



void APokemonClass::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhancedInputComponent=Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(Attack1Input,ETriggerEvent::Started,this,&ThisClass::Attack,0);
		EnhancedInputComponent->BindAction(Attack2Input,ETriggerEvent::Started,this,&ThisClass::Attack,1);
		EnhancedInputComponent->BindAction(Attack3Input,ETriggerEvent::Started,this,&ThisClass::Attack,2);
		EnhancedInputComponent->BindAction(Attack4Input,ETriggerEvent::Started,this,&ThisClass::Attack,3);
		EnhancedInputComponent->BindAction(BaseAttackInput,ETriggerEvent::Started,this,&ThisClass::Attack,0);
	}

}


//Future Features
void APokemonClass::AddTag(const FGameplayTag& InTag)
{
}

void APokemonClass::RemoveTag(const FGameplayTag& InTag)
{
}

void APokemonClass::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const
{
}
