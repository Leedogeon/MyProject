#include "MyGameModeBase.h"
#include "MyCharacter.h"

AMyGameModeBase::AMyGameModeBase()
{
	static ConstructorHelpers::FClassFinder<AMyCharacter> BP_Character(TEXT("/Script/Engine.Blueprint'/Game/Bluprint/BP_MyCharacter.BP_MyCharacter_C'"));

	if (BP_Character.Succeeded())
	{
		DefaultPawnClass = BP_Character.Class;
	}
}

