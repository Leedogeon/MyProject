#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

UCLASS()
class MYPROJECT_API AMyPawn : public APawn
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

public:
	// Sets default values for this pawn's properties
	AMyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	void KeyUpDown(float Value);
	void KeyLeftRight(float Value);

};
