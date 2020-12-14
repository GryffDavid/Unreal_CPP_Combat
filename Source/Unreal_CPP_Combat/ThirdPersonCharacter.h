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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Sets default values for this character's properties
	AThirdPersonCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	//SKILLS
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = Skills)
	int ComputerUse;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = Skills)
	int Demolitions;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = Skills)
	int Stealth;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = Skills)
	int Awareness;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = Skills)
	int Persuade;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = Skills)
	int Repair;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = Skills)
	int Security;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = Skills)
	int TreatInjury;



	//MOVEMENT FUNCTIONS
	UFUNCTION()
	void MoveForward(float value);

	UFUNCTION()
	void MoveRight(float value);
	

	//CAMERA PROPERTIES
	UPROPERTY(BlueprintReadOnly, Category = Camera)
	USpringArmComponent* CameraSpringArmComponent;

	UPROPERTY(BlueprintReadOnly, Category = Camera)
	UCameraComponent* ThirdPersonCamera;

	UPROPERTY(BlueprintReadWrite, Category = Camera)
	float DesiredSpringLength = DefaultCameraDistance;

	UPROPERTY(BlueprintReadWrite, Category = Camera)
	float DefaultCameraDistance = 300.0f;

	UPROPERTY(BlueprintReadWrite, Category = Camera)
	float AimingCameraDistance = 100.0f;

	UPROPERTY(EditDefaultsOnly, Category = Camera)
	float YShoulderOffset = 50.0f;


	//MOVEMENT BOOLEANS
	UPROPERTY(BlueprintReadWrite, Category = Movement)
	bool DisableMovement;

	UPROPERTY(BlueprintReadWrite, Category = Movement)
	bool SprintPressed;

	UPROPERTY(BlueprintReadWrite, Category = Movement)
	bool CrouchPressed;

	UPROPERTY(BlueprintReadWrite, Category = Movement)
	bool JumpPressed;

	UPROPERTY(BlueprintReadWrite, Category = Shooting)
	bool AimPressed;

	UPROPERTY(BlueprintReadWrite, Category = Gameplay)
	bool CharacterActivePaused = false;


	//MOVEMENT SPEED PROPERTIES
	UPROPERTY(EditDefaultsOnly, Category = Movement)
	float RunSpeed = 350.0f;

	UPROPERTY(EditDefaultsOnly, Category = Movement)
	float AimRunSpeed = 200.0f;

	UPROPERTY(EditDefaultsOnly, Category = Movement)
	float SprintSpeed = 600.0f;

private:
	float CurrentSpringLength = DefaultCameraDistance;

	bool IsSprinting = false;

	void Jump() override;
	void StopJumping() override;

	void Sprint();
	void StopSprinting();

	void Aim();
	void StopAiming();
};
