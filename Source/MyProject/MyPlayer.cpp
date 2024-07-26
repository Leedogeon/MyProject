// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"

#include "MyAnimInstance.h"
#include "Arrow.h"
AMyPlayer::AMyPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SprintArm"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	SpringArm->SetupAttachment(GetCapsuleComponent());
	Camera->SetupAttachment(SpringArm);

	SpringArm->TargetArmLength = 400.f;
	SpringArm->SetRelativeRotation(FRotator(-35.f, 0.f, 0.f));
	SpringArm->SocketOffset = FVector(0.f, 120.f, 75.f);
	SpringArm->bUsePawnControlRotation = true;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SkeletalMesh(TEXT("/Script/Engine.SkeletalMesh'/Game/ParagonSparrow/Characters/Heroes/Sparrow/Meshes/Sparrow.Sparrow'"));

	if (SkeletalMesh.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SkeletalMesh.Object);
		GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -90.f), FRotator(0.f, -90.f, 0.f));
	}


	static ConstructorHelpers::FClassFinder<UAnimInstance> AnimInstance(TEXT("/Script/Engine.AnimBlueprint'/Game/Animations/ABP_MyCharacter.ABP_MyCharacter_C'"));
	if (AnimInstance.Succeeded())
	{
		GetMesh()->SetAnimClass(AnimInstance.Class);

	}
}

void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();

	auto AnimInstance = GetMesh()->GetAnimInstance();
	MyAnimInstance = Cast<UMyAnimInstance>(AnimInstance);
}

void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AMyPlayer::KeyUpDown);
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AMyPlayer::KeyLeftRight);

	PlayerInputComponent->BindAxis(TEXT("LookLeftRight"), this, &AMyPlayer::MouseLookLeftRight);
	PlayerInputComponent->BindAxis(TEXT("LookUpDown"), this, &AMyPlayer::MouseLookUpDown);


	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &AMyPlayer::Jump);
	PlayerInputComponent->BindAction(TEXT("Fire"), EInputEvent::IE_Pressed, this, &AMyPlayer::Fire);
}

void AMyPlayer::KeyUpDown(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}

void AMyPlayer::KeyLeftRight(float Value)
{
	AddMovementInput(GetActorRightVector(), Value);
}

void AMyPlayer::MouseLookLeftRight(float Value)
{
	AddControllerYawInput(Value);
}

void AMyPlayer::MouseLookUpDown(float Value)
{
	AddControllerPitchInput(Value);
}

void AMyPlayer::Fire()
{
	if (IsValid(MyAnimInstance))
	{
		MyAnimInstance->PlayFireMontage();
		FTransform SocketTransform = GetMesh()->GetSocketTransform(FName("ArrowSocket"));
		FVector SocketLocation = SocketTransform.GetLocation();
		FRotator SocketRotation = SocketTransform.GetRotation().Rotator();
		FActorSpawnParameters params;
		params.Owner = this;

		auto MyArrow = GetWorld()->SpawnActor<AArrow>(SocketLocation, SocketRotation, params);

	}
}
