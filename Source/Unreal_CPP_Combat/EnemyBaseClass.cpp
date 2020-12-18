// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBaseClass.h"

// Sets default values
AEnemyBaseClass::AEnemyBaseClass()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("AttackWidgetComponent"));
	WidgetComponent->SetupAttachment(RootComponent);

	//OnClicked.AddDynamic(this, &AEnemyBaseClass::OnClicked);
	GetMesh()->OnClicked.AddDynamic(this, &AEnemyBaseClass::OnEnemyClicked);
	
	//GetCapsuleComponent()->OnClicked.AddDynamic(this, &AEnemyBaseClass::OnClicked);	
	
}

// Called when the game starts or when spawned
void AEnemyBaseClass::BeginPlay()
{
	Super::BeginPlay();

	//Widget = CreateWidget(GetWorld(), WidgetClass, TEXT("AttackWidget"));
	//WidgetComponent->SetWidget(Widget);
	/*
	FString thisname = WidgetComponent->GetAttachParent()->GetName();
	UE_LOG(LogTemp, Log, TEXT("Attached %s"), );
	WidgetComponent->SetRelativeLocation(FVector(300, 800, 400));
	UE_LOG(LogTemp, Log, TEXT("Relative location %f"), WidgetComponent->GetRelativeLocation().X);
	UE_LOG(LogTemp, Log, TEXT("Relative location %f"), WidgetComponent->GetComponentLocation().X);
	UE_LOG(LogTemp, Log, TEXT("Setting up widgetcomponent"));
	WidgetComponent->SetUsingAbsoluteLocation(false);
	WidgetComponent->SetWorldTransform(FTransform(FVector(0)));
	WidgetComponent->SetRelativeTransform(FTransform(FVector(0)));
	WidgetComponent->SetRelativeLocation(FVector(300, 800, 400));*/

	
	/*WidgetComponent->SetAbsolute(false, false, false);
	WidgetComponent->SetRelativeLocation(FVector(0, 0, 400));
	WidgetComponent->AddRelativeLocation(FVector(400));

*/
	//WidgetComponent->SetUsingAbsoluteLocation(false);
	//WidgetComponent->SetRelativeLocation(FVector(0, 0, 90));
	

	CurrentHP = MaxHP;
	HPPercent = CurrentHP / MaxHP;
	Defense = 10 + FMath::Floor((Dexterity - 10.0f) / 2.0f);
}

// Called every frame
void AEnemyBaseClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//AddActorLocalOffset(FVector(0, 10, 0));
	//AddMovementInput(FVector(5, 5, 0), 500.0f);
}

// Called to bind functionality to input
void AEnemyBaseClass::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AEnemyBaseClass::DecreaseHP(int change)
{
	CurrentHP -= change;
	HPPercent = (float)CurrentHP / (float)MaxHP;
}

void AEnemyBaseClass::IncreaseHP(int change)
{
	CurrentHP = FMath::Clamp(CurrentHP + change, 0, MaxHP);

	HPPercent = (float)CurrentHP / (float)MaxHP;
}

void AEnemyBaseClass::OnEnemyClicked(UPrimitiveComponent* pComponent, FKey inKey)
{
	UE_LOG(LogTemp, Log, TEXT("WAS CLICKED"));
}