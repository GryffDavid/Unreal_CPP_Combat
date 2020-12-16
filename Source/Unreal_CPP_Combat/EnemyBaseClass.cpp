// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBaseClass.h"

// Sets default values
AEnemyBaseClass::AEnemyBaseClass()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//MyCollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("ButtSphereComponent"));
	//MyCollisionComponent->SetupAttachment(RootComponent);

	//MyAttackWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("BUTTATTACKCOMPONENT"));
	//MyAttackWidget->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AEnemyBaseClass::BeginPlay()
{
	Super::BeginPlay();

	CurrentHP = MaxHP;
	HPPercent = CurrentHP / MaxHP;
	Defense = 10 + FMath::Floor((Dexterity - 10.0f) / 2.0f);
}

// Called every frame
void AEnemyBaseClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyBaseClass::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

