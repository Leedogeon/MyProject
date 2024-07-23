#include "MyAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"

AMyAIController::AMyAIController()
{
	static ConstructorHelpers::FObjectFinder<UBehaviorTree> BT(TEXT("/Script/AIModule.BehaviorTree'/Game/AI/BT_Enemy.BT_Enemy'"));
	if (BT.Succeeded())
	{
		UE_LOG(LogTemp, Log, TEXT("BehaviorTree Succeeded"));
		BehaviorTree = BT.Object;
	}


	static ConstructorHelpers::FObjectFinder<UBlackboardData> BB(TEXT("/Script/AIModule.BlackboardData'/Game/AI/BB_Enemy.BB_Enemy'"));
	if (BB.Succeeded())
	{
		UE_LOG(LogTemp, Log, TEXT("BlackboardData Succeeded"));
		BlackboardData = BB.Object;
	}
}

void AMyAIController::OnPossess(APawn* InPawn)
{
	UE_LOG(LogTemp, Log, TEXT("OnPossess"));
	Super::OnPossess(InPawn);
	if (RunBehaviorTree(BehaviorTree))
	{
		UE_LOG(LogTemp, Log, TEXT("Run Hehavior Tree"));
	}

}

void AMyAIController::OnUnPossess()
{
	Super::OnUnPossess();
}

