// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterBaseClass.h"

// Sets default values
ACharacterBaseClass::ACharacterBaseClass()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACharacterBaseClass::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACharacterBaseClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacterBaseClass::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ACharacterBaseClass::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACharacterBaseClass::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &ACharacterBaseClass::AddControllerYawInput).bExecuteWhenPaused = true;
	PlayerInputComponent->BindAxis("LookUp", this, &ACharacterBaseClass::AddControllerPitchInput).bExecuteWhenPaused = true;
	PlayerInputComponent->SetTickableWhenPaused(true);

	//PlayerInputComponent->AxisBindings[0].bExecuteWhenPaused = true;
	//PlayerInputComponent->AxisBindings[1].bExecuteWhenPaused = true;
	//PlayerInputComponent->AxisBindings[2].bExecuteWhenPaused = true;
	//PlayerInputComponent->AxisBindings[3].bExecuteWhenPaused = true;

	//CameraSpringArmComponent->SetTickableWhenPaused(true);
	//CameraSpringArmComponent->SetTickableWhenPaused(true);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacterBaseClass::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacterBaseClass::StopJumping);

	/*PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AThirdPersonCharacter::Sprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AThirdPersonCharacter::StopSprinting);*/
}

void ACharacterBaseClass::MoveForward(float value)
{
	if (!DisableMovement && Controller != nullptr)
	{
		FVector Direction = FRotationMatrix(FRotator(0, Controller->GetControlRotation().Yaw, 0)).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, value);		
	}
}

void ACharacterBaseClass::MoveRight(float value)
{
	if (!DisableMovement && Controller != nullptr)
	{
		FVector Direction = FRotationMatrix(FRotator(0, Controller->GetControlRotation().Yaw, 0)).GetScaledAxis(EAxis::Y);
		AddMovementInput(Direction, value);		
	}
}

