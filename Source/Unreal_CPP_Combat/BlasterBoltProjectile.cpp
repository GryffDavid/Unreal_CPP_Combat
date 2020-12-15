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
		CollisionComponent->OnComponentHit.AddDynamic(this, &ABlasterBoltProjectile::OnHit);
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

	if (!ProjectileMeshComponent)
	{
		ProjectileMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMeshComponent"));

		static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("'/Game/Meshes/Sphere.Sphere'"));

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
	
}

// Called every frame
void ABlasterBoltProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABlasterBoltProjectile::FireInDirection(const FVector & shootDirection)
{
	ProjectileMovementComponent->Velocity = shootDirection * ProjectileMovementComponent->InitialSpeed;
}

void ABlasterBoltProjectile::OnHit(UPrimitiveComponent * hitComponent, AActor * otherActor, UPrimitiveComponent * otherComponent, FVector normalImpulse, const FHitResult & hit)
{
	if (otherActor != this && otherComponent->IsSimulatingPhysics())
	{
		otherComponent->AddImpulseAtLocation(ProjectileMovementComponent->Velocity * 100.0f, hit.ImpactPoint);
	}

	Destroy();
}

