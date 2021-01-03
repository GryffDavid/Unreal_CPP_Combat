// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/PointLightComponent.h"
#include "BlasterBoltProjectile.generated.h"

UCLASS()
class UNREAL_CPP_COMBAT_API ABlasterBoltProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlasterBoltProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
	USphereComponent* CollisionComponent;

	UPROPERTY(VisibleAnywhere, Category = Movement)
	UProjectileMovementComponent* ProjectileMovementComponent;

	UPROPERTY(EditDefaultsOnly, Category = Light)
	UPointLightComponent* ProjectileLightComponent;

	UFUNCTION(BlueprintCallable)
	void ToggleActivePause(bool isPaused);

	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
	UStaticMeshComponent* ProjectileMeshComponent;

	UPROPERTY(EditDefaultsOnly, Category = Material)
	UMaterialInstanceDynamic* ProjectileMaterialInstance;

	UPROPERTY(BlueprintReadWrite, Category = Projectile)
	FVector StartingVelocity;

	UPROPERTY(BlueprintReadWrite, Category = Projectile, meta=(ExposeOnSpawn=true))
	bool CanHit;

	UPROPERTY(BlueprintReadWrite, Category = Projectile, meta = (ExposeOnSpawn = true))
	int DamageToDo;
	
	/*UFUNCTION()
	void OnHit(UPrimitiveComponent* hitComponent, AActor* otherActor, UPrimitiveComponent* otherComponent, FVector normalImpulse, const FHitResult& hit);*/

};
