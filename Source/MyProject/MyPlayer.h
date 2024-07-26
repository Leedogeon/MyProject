// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Creature.h"
#include "MyPlayer.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AMyPlayer : public ACreature
{
	GENERATED_BODY()
private:
	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* Camera;
	UPROPERTY(VisibleAnywhere)
	class UMyAnimInstance* MyAnimInstance;
public:
	AMyPlayer();
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
public:
	void KeyUpDown(float Value);
	void KeyLeftRight(float Value);
	void MouseLookLeftRight(float Value);
	void MouseLookUpDown(float Value);
	void Fire();
};
