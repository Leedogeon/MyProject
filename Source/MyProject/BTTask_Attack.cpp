#include "BTTask_Attack.h"
#include "MyAIController.h"	  //or #include "AIController.h"
#include "MyEnemy.h"

UBTTask_Attack::UBTTask_Attack()
{
	NodeName = TEXT("Attack");
	bNotifyTick = true;
}

EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto MyEnemy = Cast<AMyEnemy>(OwnerComp.GetAIOwner()->GetPawn());
	if (MyEnemy == nullptr)
		return EBTNodeResult::Failed;

	if (IsAttacking == false)
	{

		MyEnemy->Attack();
		IsAttacking = true;

		UE_LOG(LogTemp, Log, TEXT("Attack"));
		return EBTNodeResult::InProgress;
	}


	return Result;
}

void UBTTask_Attack::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

	if (IsAttacking == false)
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	}

	//UE_LOG(LogTemp, Log, TEXT("AttackTick"));
}

