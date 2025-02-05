// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"

#include "PokeComponent.h"
#include "PokemonClass.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"



void ABullet::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!SweepResult.GetActor()) return;
	if(SweepResult.GetActor()->FindComponentByClass<UPokeComponent>()&&AttackElement.IsValid())
	{
		Cast<APokemonClass>(SweepResult.GetActor())->ReceiveDamage(AttackElement,Damage);
		this->Destroy();
	}
	
}

void ABullet::Initialize(const FGameplayTag& InAttackElement, const int InDamage)
{
	AttackElement = InAttackElement;
	Damage = InDamage;
}

// Sets default values
ABullet::ABullet()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	USphereComponent* SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	RootComponent = SphereCollision;
	SphereCollision->InitSphereRadius(20.0f);

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(RootComponent);
	const static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Assets/Bullet.Bullet"));

	if (MeshAsset.Succeeded())
	{
		MeshComponent->SetStaticMesh(MeshAsset.Object);
	}
	
	UProjectileMovementComponent* ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->InitialSpeed = Speed;
	ProjectileMovement->MaxSpeed = 3000.0f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = false;
	
	SphereCollision->OnComponentBeginOverlap.AddDynamic(this,&ABullet::OnBeginOverlap);
	
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	Direction = GetActorForwardVector();
	
}

// Called every frame
void ABullet::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveForward(DeltaTime);
}

void ABullet::MoveForward(const float DeltaTime)
{
	const FVector NewLocation = GetActorLocation() + (Direction * Speed * DeltaTime);
	SetActorLocation(NewLocation);
}

