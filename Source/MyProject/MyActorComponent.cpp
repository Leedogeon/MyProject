// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActorComponent.h"

// Sets default values for this component's properties
UMyActorComponent::UMyActorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bWantsInitializeComponent = true; // InitializeComponent 호출가능
}


void UMyActorComponent::InitializeComponent()
{
	Super::InitializeComponent();
	SetLevel(Level);
}

// Called when the game starts
void UMyActorComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UMyActorComponent::SetLevel(int32 Lv)
{
}

void UMyActorComponent::OnDamaged(float DamageAmount)
{
	HP -= DamageAmount;
	if (HP < 0)
	{
		HP = 0;
	}

	UE_LOG(LogTemp, Log, TEXT("HP : %d"), HP);
}



