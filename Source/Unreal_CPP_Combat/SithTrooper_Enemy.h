// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyBaseClass.h"
#include "Components/PrimitiveComponent.h"
#include "Components/CapsuleComponent.h"
#include "SithTrooper_Enemy.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTestDelegate);

UCLASS()
class UNREAL_CPP_COMBAT_API ASithTrooper_Enemy : public AEnemyBaseClass
{
	GENERATED_BODY()

public:
	ASithTrooper_Enemy();

	UFUNCTION()
	void TestFunction();

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = Test)
	FTestDelegate OnTestDelegate;
	
	UPROPERTY(BlueprintReadWrite, Category = Combat)
	bool IsTargeted = false;

};
