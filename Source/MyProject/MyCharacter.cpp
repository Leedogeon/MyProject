#include "MyCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"

#include "MyAnimInstance.h"



// Sets default values
AMyCharacter::AMyCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SprintArm"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	SpringArm->SetupAttachment(GetCapsuleComponent());
	Camera->SetupAttachment(SpringArm);

	SpringArm->TargetArmLength = 400.f;
	SpringArm->SetRelativeRotation(FRotator(-35.f, 0.f, 0.f));
	SpringArm->bUsePawnControlRotation = true;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SkeletalMesh(TEXT("/Script/Engine.SkeletalMesh'/Game/ParagonSparrow/Characters/Heroes/Sparrow/Meshes/Sparrow.Sparrow'"));

	if (SkeletalMesh.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SkeletalMesh.Object);
		GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -90.f), FRotator(0.f, -90.f, 0.f));
	}



}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

	auto AnimInstance = GetMesh()->GetAnimInstance();
	MyAnimInstance = Cast<UMyAnimInstance>(AnimInstance);

}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AMyCharacter::KeyUpDown);
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AMyCharacter::KeyLeftRight);

	PlayerInputComponent->BindAxis(TEXT("LookLeftRight"), this, &AMyCharacter::MouseLookLeftRight);
	PlayerInputComponent->BindAxis(TEXT("LookUpDown"), this, &AMyCharacter::MouseLookUpDown);


	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &AMyCharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Fire"), EInputEvent::IE_Pressed, this, &AMyCharacter::Fire);

}

void AMyCharacter::KeyUpDown(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}

void AMyCharacter::KeyLeftRight(float Value)
{
	AddMovementInput(GetActorRightVector(), Value);
}

void AMyCharacter::MouseLookLeftRight(float Value)
{
	AddControllerYawInput(Value);
}

void AMyCharacter::MouseLookUpDown(float Value)
{
	AddControllerPitchInput(Value);
}

void AMyCharacter::Fire()
{
	if (IsValid(MyAnimInstance))
	{
		MyAnimInstance->PlayFireMontage();
		
	}

}

