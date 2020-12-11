// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Math/UnrealMathUtility.h"
#include "ThirdPersonCharacter.generated.h"

UCLASS()
class UNREAL_CPP_COMBAT_API AThirdPersonCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AThirdPersonCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void MoveForward(float value);

	UFUNCTION()
	void MoveRight(float value);	

	void Jump() override;
	void StopJumping() override;

	void Sprint();
	void StopSprinting();

	void Aim();
	void StopAiming();

	UPROPERTY(VisibleDefaultsOnly, Category = Camera)
	USpringArmComponent* CameraSpringArmComponent;

	UPROPERTY(VisibleDefaultsOnly, Category = Camera)
	UCameraComponent* ThirdPersonCamera;

	UPROPERTY(BlueprintReadWrite, Category = Movement)
	bool SprintPressed;

	UPROPERTY(BlueprintReadWrite, Category = Movement)
	bool CrouchPressed;

	UPROPERTY(BlueprintReadWrite, Category = Movement)
	bool JumpPressed;

	UPROPERTY(BlueprintReadWrite, Category = Movement)
	bool DisableMovement;

	UPROPERTY(BlueprintReadWrite, Category = Shooting)
	bool AimPressed;	

	UPROPERTY(EditDefaultsOnly, Category = Camera)
	float DefaultCameraDistance = 300.0f;

	UPROPERTY(EditDefaultsOnly, Category = Camera)
	float AimingCameraDistance = 100.0f;

	UPROPERTY(EditDefaultsOnly, Category = Camera)
	float YShoulderOffset = 50.0f;

	UPROPERTY(BlueprintReadWrite, Category = Camera)
	float DesiredSpringLength = DefaultCameraDistance;

	UPROPERTY(EditDefaultsOnly, Category = Movement)
	float RunSpeed = 350.0f;

	UPROPERTY(EditDefaultsOnly, Category = Movement)
	float SprintSpeed = 600.0f;

private:
	float CurrentSpringLength = DefaultCameraDistance;
};
