#include "BTTask_FindDestination.h"
#include "MyAIController.h"         //OwnerComp.GetAIOwner()->GetPawn(); 
#include "NavigationSystem.h"       // UNavigationSystemV1::GetNavigationSystem(GetWorld());
#include "BehaviorTree/BlackboardComponent.h" //OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName(TEXT("Destination")), RandomLocation);


UBTTask_FindDestination::UBTTask_FindDestination()
{
    NodeName = TEXT("FindPatrolDestination");
}

EBTNodeResult::Type UBTTask_FindDestination::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    auto CurrentPawn = OwnerComp.GetAIOwner()->GetPawn();
    if (CurrentPawn != nullptr)
    {
        auto NaveSystem = UNavigationSystemV1::GetNavigationSystem(GetWorld());
        if (NaveSystem != nullptr)
        {
            FNavLocation RandomLocation;
            if (NaveSystem->GetRandomReachablePointInRadius(CurrentPawn->GetActorLocation(), 500.f, RandomLocation))
            {
                OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName(TEXT("Destination")), RandomLocation);

                return EBTNodeResult::Succeeded;
            }

        }
    }


    return EBTNodeResult::Failed;
}

