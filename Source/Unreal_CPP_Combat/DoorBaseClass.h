// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DoorBaseClass.generated.h"

UENUM()
enum class EDoorType : uint8
{
	Basic,
	Security
};

UCLASS()
class UNREAL_CPP_COMBAT_API ADoorBaseClass : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoorBaseClass();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = Type)
	EDoorType DoorType = EDoorType::Basic;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = Skill)
	int SecurityCheck;

};
