// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	GetCharacterMovement()->MaxWalkSpeed = 350.0f;
	GetCharacterMovement()->MaxWalkSpeedCrouched = 160;
	GetCharacterMovement()->JumpZVelocity = 365;
	GetCharacterMovement()->AirControl = 0.5f;
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ABaseCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABaseCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &ABaseCharacter::AddControllerYawInput).bExecuteWhenPaused = true;
	PlayerInputComponent->BindAxis("LookUp", this, &ABaseCharacter::AddControllerPitchInput).bExecuteWhenPaused = true;
	PlayerInputComponent->SetTickableWhenPaused(true);

	//PlayerInputComponent->AxisBindings[0].bExecuteWhenPaused = true;
	//PlayerInputComponent->AxisBindings[1].bExecuteWhenPaused = true;
	//PlayerInputComponent->AxisBindings[2].bExecuteWhenPaused = true;
	//PlayerInputComponent->AxisBindings[3].bExecuteWhenPaused = true;

	//CameraSpringArmComponent->SetTickableWhenPaused(true);
	//CameraSpringArmComponent->SetTickableWhenPaused(true);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ABaseCharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ABaseCharacter::StopJumping);

	//PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &ABaseCharacter::Sprint);
	//PlayerInputComponent->BindAction("Sprint", IE_Released, this, &ABaseCharacter::StopSprinting);

}

void ABaseCharacter::MoveForward(float value)
{
	if (!DisableMovement)
	{
		FVector Direction = FRotationMatrix(FRotator(0, Controller->GetControlRotation().Yaw, 0)).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, value);
	}
}

void ABaseCharacter::MoveRight(float value)
{
	if (!DisableMovement)
	{
		FVector Direction = FRotationMatrix(FRotator(0, Controller->GetControlRotation().Yaw, 0)).GetScaledAxis(EAxis::Y);
		AddMovementInput(Direction, value);
	}
}

