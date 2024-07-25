// Fill out your copyright notice in the Description page of Project Settings.


#include "..\..\Public\Character\JokerCharacterBase.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AJokerCharacterBase::AJokerCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	DefaultFOV = 80.0f;
	CameraBoomComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoomComp"));
	CameraBoomComp->SetupAttachment(GetRootComponent());
	CameraBoomComp->bUsePawnControlRotation = true;	//允许跟随角色旋转
	CameraBoomComp->SetRelativeLocation(FVector(0, 50, 50));
	//CameraBoomComp->bEnableCameraRotationLag = true;
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(CameraBoomComp);
	CameraComp->FieldOfView = DefaultFOV;

	ThrowWeaponScene = CreateDefaultSubobject<USceneComponent>(TEXT("ThrowWeaponScene"));
	ThrowWeaponScene->SetupAttachment(GetRootComponent());
	
	MovementComp = GetCharacterMovement();
	bUseControllerRotationYaw = true;
	SprintSpeed = 600;
	RunSpeed = 450;
	WalkSpeed = 190;
	CrouchSpeed = 190;

	

	// 网络同步开关
	SetReplicates(true);
	SetReplicateMovement(true);
	GetMesh()->SetIsReplicated(true);
}

// Called when the game starts or when spawned
void AJokerCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AJokerCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AJokerCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AJokerCharacterBase::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AJokerCharacterBase::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &AJokerCharacterBase::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &AJokerCharacterBase::LookUp);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AJokerCharacterBase::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AJokerCharacterBase::StopJump);
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AJokerCharacterBase::StartAttack);
	PlayerInputComponent->BindAction("Fire", IE_Released, this, &AJokerCharacterBase::StopAttack);
	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AJokerCharacterBase::SprintPressed);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AJokerCharacterBase::SprintReleased);
	PlayerInputComponent->BindAction("Walk", IE_Pressed, this, &AJokerCharacterBase::WalkPressed);
	PlayerInputComponent->BindAction("Walk", IE_Released, this, &AJokerCharacterBase::WalkReleased);
	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &AJokerCharacterBase::CrouchPressed);
	PlayerInputComponent->BindAction("Crouch", IE_Released, this, &AJokerCharacterBase::CrouchReleased);

}

void AJokerCharacterBase::MoveForward(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value);
}

void AJokerCharacterBase::MoveRight(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}

void AJokerCharacterBase::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void AJokerCharacterBase::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

void AJokerCharacterBase::StartJump()
{
	bPressedJump = true;
	
}

void AJokerCharacterBase::StopJump()
{
	bPressedJump = false;
}

void AJokerCharacterBase::StartAttack()
{
}

void AJokerCharacterBase::StopAttack()
{
}

void AJokerCharacterBase::SprintPressed()
{
	MovementComp->MaxWalkSpeed = SprintSpeed;
}

void AJokerCharacterBase::SprintReleased()
{
	MovementComp->MaxWalkSpeed = RunSpeed;
}

void AJokerCharacterBase::WalkPressed()
{
	MovementComp->MaxWalkSpeed = WalkSpeed;
}

void AJokerCharacterBase::WalkReleased()
{
	MovementComp->MaxWalkSpeed = RunSpeed;
}

void AJokerCharacterBase::CrouchPressed()
{
	Crouch(true);
	MovementComp->MaxWalkSpeed = CrouchSpeed;
}

void AJokerCharacterBase::CrouchReleased()
{
	UnCrouch();
	MovementComp->MaxWalkSpeed = RunSpeed;
}



