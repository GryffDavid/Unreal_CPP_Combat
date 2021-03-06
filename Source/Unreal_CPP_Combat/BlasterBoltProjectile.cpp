// Fill out your copyright notice in the Description page of Project Settings.


#include "BlasterBoltProjectile.h"

// Sets default values
ABlasterBoltProjectile::ABlasterBoltProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!RootComponent)
	{
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectileSceneComponent"));
	}

	if (!CollisionComponent)
	{
		CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
		CollisionComponent->BodyInstance.SetCollisionProfileName(TEXT("Projectile"));
		//CollisionComponent->OnComponentHit.AddDynamic(this, &ABlasterBoltProjectile::OnHit);
		CollisionComponent->InitSphereRadius(15.0f);
		RootComponent = CollisionComponent;
	}

	if (!ProjectileMovementComponent)
	{
		ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
		ProjectileMovementComponent->SetUpdatedComponent(CollisionComponent);
		ProjectileMovementComponent->InitialSpeed = 3500.0f;
		ProjectileMovementComponent->MaxSpeed = 3500.0f;
		ProjectileMovementComponent->bRotationFollowsVelocity = true;
		ProjectileMovementComponent->bShouldBounce = true;
		ProjectileMovementComponent->Bounciness = 0.3f;
		ProjectileMovementComponent->ProjectileGravityScale = 0.0f;
	}

	if (!ProjectileLightComponent)
	{
		ProjectileLightComponent = CreateDefaultSubobject<UPointLightComponent>(TEXT("ProjectileLightComponent"));
		ProjectileLightComponent->SetupAttachment(RootComponent);
		ProjectileLightComponent->AttenuationRadius = 250.0f;
		ProjectileLightComponent->Intensity = 500.0f;
	}

	if (!ProjectileMeshComponent)
	{
		ProjectileMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMeshComponent"));

		static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("'/Game/Meshes/M_Sphere.M_Sphere'"));

		if (Mesh.Succeeded())
		{
			ProjectileMeshComponent->SetStaticMesh(Mesh.Object);
		}
	}

	ProjectileMeshComponent->SetMaterial(0, ProjectileMaterialInstance);
	ProjectileMeshComponent->SetRelativeScale3D(FVector(0.5f, 0.01f, 0.01f));
	ProjectileMeshComponent->SetupAttachment(RootComponent);
	ProjectileMeshComponent->CastShadow = false;

	InitialLifeSpan = 3.0f;
}

// Called when the game starts or when spawned
void ABlasterBoltProjectile::BeginPlay()
{
	Super::BeginPlay();
	StartingVelocity = GetActorRotation().Vector() * ProjectileMovementComponent->InitialSpeed;
	
}

// Called every frame
void ABlasterBoltProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABlasterBoltProjectile::ToggleActivePause(bool isPaused)
{
	if (isPaused)
	{
		ProjectileMovementComponent->Velocity = FVector(0);
		SetLifeSpan(0);
	}
	else
	{
		ProjectileMovementComponent->Velocity = StartingVelocity;
		SetLifeSpan(3.5f);
	}
}


