#include "MyActorComponent.h"
#include "MyGameInstance.h"	//UMyGameInstance 사용하기 위해
#include "Kismet/GameplayStatics.h"	 // UGameplayStatics 사용하기 위해

// Sets default values for this component's properties
UMyActorComponent::UMyActorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bWantsInitializeComponent = true; //InitializeComponent 호출가능
	Level = 1;
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
	//auto MyGameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
	auto MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (MyGameInstance)
	{
		auto CharacterData = MyGameInstance->GetCharacterData(Lv);
		if (CharacterData)
		{
			Level = CharacterData->Level;
			MaxHp = CharacterData->MaxHp;
			Hp = MaxHp;

			UE_LOG(LogTemp, Log, TEXT("Lv : %d"), Level);
			UE_LOG(LogTemp, Log, TEXT("HP : %d"), Hp);
		}
	}

}

void UMyActorComponent::OnDamaged(float DamageAmount)
{
	Hp -= DamageAmount;
	if (Hp < 0)
	{
		Hp = 0;
	}

	UE_LOG(LogTemp, Warning, TEXT("HP : %d"), Hp);
}

