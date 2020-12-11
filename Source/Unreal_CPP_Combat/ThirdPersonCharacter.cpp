// Fill out your copyright notice in the Description page of Project Settings.


#include "ThirdPersonCharacter.h"

// Sets default values
AThirdPersonCharacter::AThirdPersonCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCharacterMovement()->MaxWalkSpeed = 200;
	GetCharacterMovement()->MaxWalkSpeedCrouched = 160;
	GetCharacterMovement()->JumpZVelocity = 365;
	GetCharacterMovement()->AirControl = 0.5f;

	CameraSpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	CameraSpringArmComponent->SetupAttachment(RootComponent);
	CameraSpringArmComponent->TargetArmLength = 300;
	CameraSpringArmComponent->bUsePawnControlRotation = true;

	ThirdPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ThirdPersonCamera"));
	ThirdPersonCamera->SetupAttachment(CameraSpringArmComponent, USpringArmComponent::SocketName);
	ThirdPersonCamera->bUsePawnControlRotation = false;
}

// Called when the game starts or when spawned
void AThirdPersonCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AThirdPersonCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AThirdPersonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AThirdPersonCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AThirdPersonCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &AThirdPersonCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AThirdPersonCharacter::AddControllerPitchInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AThirdPersonCharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AThirdPersonCharacter::StopJumping);

	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AThirdPersonCharacter::Sprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AThirdPersonCharacter::StopSprinting);

	PlayerInputComponent->BindAction("AimDownSights", IE_Pressed, this, &AThirdPersonCharacter::Aim);
	PlayerInputComponent->BindAction("AimDownSights", IE_Released, this, &AThirdPersonCharacter::StopAiming);

}

void AThirdPersonCharacter::MoveForward(float value)
{
	if (!DisableMovement)
	{
		FVector Direction = FRotationMatrix(FRotator(0, Controller->GetControlRotation().Yaw, 0)).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, value);
	}
}

void AThirdPersonCharacter::MoveRight(float value)
{
	if (!DisableMovement)
	{
		FVector Direction = FRotationMatrix(FRotator(0, Controller->GetControlRotation().Yaw, 0)).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, value);
	}
}

void AThirdPersonCharacter::Jump()
{ 
	float Length;
	FVector Direction;
	GetCharacterMovement()->Velocity.ToDirectionAndLength(OUT Direction, OUT Length);

	if (Length > 0.0f)
		GetCharacterMovement()->JumpZVelocity = 365;
	else
		GetCharacterMovement()->JumpZVelocity = 340;

	Super::Jump();
}

void AThirdPersonCharacter::StopJumping()
{
	Super::StopJumping();
}

void AThirdPersonCharacter::Sprint()
{
	//TODO: Clean up IsSprinting and SprintPressed. They're the same thing.
	SprintPressed = true;

	if (AimPressed == false)
		GetCharacterMovement()->MaxWalkSpeed = 375;
}

void AThirdPersonCharacter::StopSprinting()
{
	SprintPressed = false;
	GetCharacterMovement()->MaxWalkSpeed = 200;
}

void AThirdPersonCharacter::Aim()
{
	AimPressed = true;
}

void AThirdPersonCharacter::StopAiming()
{
	AimPressed = false;
}



