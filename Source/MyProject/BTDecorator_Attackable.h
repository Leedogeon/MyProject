
#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator_Attackable.generated.h"


UCLASS()
class MYPROJECT_API UBTDecorator_Attackable : public UBTDecorator
{
	GENERATED_BODY()
public:
	UBTDecorator_Attackable();
public:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
