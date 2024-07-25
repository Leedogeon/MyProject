#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "EnemyAnimInstance.generated.h"

/**
 *
 */
UCLASS()
class MYPROJECT_API UEnemyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	UPROPERTY(Category = "Animaiton", VisibleAnywhere, BlueprintReadOnly)
	UAnimMontage* AttackMontage;
	UPROPERTY(Category = "Animaiton", VisibleAnywhere, BlueprintReadOnly)
	class UCharacterMovementComponent* CharacterMovement;
	UPROPERTY(Category = "Animaiton", VisibleAnywhere, BlueprintReadOnly)
	bool ShouldMove = false;

public:
	UEnemyAnimInstance();
public:
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
public:
	void PlayAttackMontage();
};

