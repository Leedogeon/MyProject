// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyActorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT_API UMyActorComponent : public UActorComponent
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere, Category = "Info", Meta = (AllowPrivateAccess = true))
	int32 Level;
	UPROPERTY(EditAnywhere, Category = "Info", Meta = (AllowPrivateAccess = true))
	int32 MaxHP;
	UPROPERTY(EditAnywhere, Category = "Info", Meta = (AllowPrivateAccess = true))
	int32 HP;
public:
	int32 GetLevel() const { return Level; }
	int32 GetHP() const { return HP; }
public:	
	// Sets default values for this component's properties
	UMyActorComponent();

protected:
	// Called when the game starts
	virtual void InitializeComponent() override;
	virtual void BeginPlay() override;
public:
	void SetLevel(int32 Lv);
	void OnDamaged(float DamageAmount);


		
};
