// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Math/UnrealMathUtility.h"
#include "EnemyBaseClass.generated.h"

UCLASS()
class UNREAL_CPP_COMBAT_API AEnemyBaseClass : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyBaseClass();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	#pragma region ATTRIBUTES
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Skills)
	int Strength;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Skills)
	int Dexterity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Skills)
	int Constitution;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Skills)
	int Intelligence;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Skills)
	int Wisdom;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Skills)
	int Charisma;
	#pragma endregion

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Skills)
	int Defense;
};
