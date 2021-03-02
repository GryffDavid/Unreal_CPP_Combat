// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBaseClass.h"

// Sets default values
AEnemyBaseClass::AEnemyBaseClass()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	GetMesh()->OnClicked.AddDynamic(this, &AEnemyBaseClass::OnEnemyClicked);

	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("AttackWidgetComponent"));	
	WidgetComponent->SetupAttachment(RootComponent);
	WidgetComponent->RegisterComponent();	
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

bool AEnemyBaseClass::DecreaseHP(int change)
{
	CurrentHP -= change;
	HPPercent = (float)CurrentHP / (float)MaxHP;

	//If the enemy is below 0 HP after the change,
	//this function returns true. Meaning dead.
	if (CurrentHP <= 0)
	{
		WidgetComponent->SetVisibility(false);
		IsTargeted = false;
		return true;
	}
	
	return false;
}

void AEnemyBaseClass::IncreaseHP(int change)
{
	CurrentHP = FMath::Clamp(CurrentHP + change, 0, MaxHP);
	HPPercent = (float)CurrentHP / (float)MaxHP;
}

void AEnemyBaseClass::OnEnemyClicked(UPrimitiveComponent* pComponent, FKey inKey)
{	
	WidgetComponent->SetVisibility(true);
	IsTargeted = true;

	//Make sure all other enemies (That aren't this enemy instance)
	//Are set as not targeted and their AttackWidgets aren't visible.
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemyBaseClass::StaticClass(), FoundActors);
	
	for (AActor* actor : FoundActors)
	{
		AEnemyBaseClass* enemyActor = Cast<AEnemyBaseClass>(actor);

		if (enemyActor != this)
		{
			enemyActor->IsTargeted = false;
			enemyActor->WidgetComponent->SetVisibility(enemyActor->IsTargeted);
		}
	}	
}