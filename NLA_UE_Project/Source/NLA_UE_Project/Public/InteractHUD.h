#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "InteractHUD.generated.h"

UCLASS()
class NLA_UE_PROJECT_API AInteractHUD : public AHUD
{
	GENERATED_BODY()

public:
	virtual void DrawHUD() override;
};