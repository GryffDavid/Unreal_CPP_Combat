// Fill out your copyright notice in the Description page of Project Settings.

#include "ThirdPersonCharacter.h"

// Sets default values
AThirdPersonCharacter::AThirdPersonCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCharacterMovement()->MaxWalkSpeed = RunSpeed;
	GetCharacterMovement()->MaxWalkSpeedCrouched = 160;
	GetCharacterMovement()->JumpZVelocity = 365;
	GetCharacterMovement()->AirControl = 0.5f;

	CameraSpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	CameraSpringArmComponent->SetupAttachment(RootComponent);
	CameraSpringArmComponent->TargetArmLength = DefaultCameraDistance;
	CurrentSpringLength = DefaultCameraDistance;
	DesiredSpringLength = DefaultCameraDistance;

	UE_LOG(LogTemp, Warning, TEXT("DefaultCameraDistance %f"), DefaultCameraDistance);

	CameraSpringArmComponent->bUsePawnControlRotation = true;

	ThirdPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ThirdPersonCamera"));
	ThirdPersonCamera->SetupAttachment(CameraSpringArmComponent, USpringArmComponent::SocketName);
	ThirdPersonCamera->bUsePawnControlRotation = false;
	
	//GetMesh()->OnClicked.AddDynamic(&AThirdPersonCharacter::MoveForward);
}

// Called when the game starts or when spawned
void AThirdPersonCharacter::BeginPlay()
{
	Super::BeginPlay();	

	CameraSpringArmComponent->TargetArmLength = DefaultCameraDistance;
	CurrentSpringLength = DefaultCameraDistance;

	GetController<APlayerController>()->SetInputMode(FInputModeGameAndUI());
	GetController<APlayerController>()->bShowMouseCursor = true;
}

// Called every frame
void AThirdPersonCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	//TODO: Should maybe do this camera transition with a timeline in blueprint
	CurrentSpringLength = FMath::Lerp(CurrentSpringLength, DesiredSpringLength, 0.1f);
	CameraSpringArmComponent->TargetArmLength = CurrentSpringLength;

	bUseControllerRotationYaw = (AimPressed && !CharacterActivePaused);
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
		FVector Direction = FRotationMatrix(FRotator(0, Controller->GetControlRotation().Yaw, 0)).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, value);		
	}
}

void AThirdPersonCharacter::MoveRight(float value)
{
	if (!DisableMovement && SprintPressed == false)
	{
		FVector Direction = FRotationMatrix(FRotator(0, Controller->GetControlRotation().Yaw, 0)).GetScaledAxis(EAxis::Y);
		AddMovementInput(Direction, value);
	}
}


void AThirdPersonCharacter::Sprint()
{
	SprintPressed = true;

	if (AimPressed == false)	
		GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;	
}

void AThirdPersonCharacter::StopSprinting()
{
	SprintPressed = false;
	GetCharacterMovement()->MaxWalkSpeed = RunSpeed;
}
