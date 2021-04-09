// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBaseClass.generated.h"

UCLASS()
class UNREAL_CPP_COMBAT_API ACharacterBaseClass : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterBaseClass();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintReadWrite, Category = Health)
	int CurrentHealth = 10;

	UPROPERTY(BlueprintReadWrite, Category = Health)
	int MaxHealth = 10;

	#pragma region ATTRIBUTES
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = Skills)
	int Strength;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = Skills)
	int Dexterity;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = Skills)
	int Constitution;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = Skills)
	int Intelligence;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = Skills)
	int Wisdom;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = Skills)
	int Charisma;
	#pragma endregion

	#pragma region SKILLS
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
	#pragma endregion


	#pragma region MOVEMENT FUNCTIONS
	UFUNCTION()
	void MoveForward(float value);

	UFUNCTION()
	void MoveRight(float value);
	#pragma endregion

	#pragma region MOVEMENT BOOLEANS
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
	#pragma endregion

	#pragma region MOVEMENT SPEED PROPERTIES
	UPROPERTY(EditDefaultsOnly, Category = Movement)
	float RunSpeed = 350.0f;

	UPROPERTY(EditDefaultsOnly, Category = Movement)
	float AimRunSpeed = 200.0f;

	UPROPERTY(EditDefaultsOnly, Category = Movement)
	float SprintSpeed = 600.0f;
	#pragma endregion
};
