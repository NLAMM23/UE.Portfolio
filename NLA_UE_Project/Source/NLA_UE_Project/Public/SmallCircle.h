#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SmallCircle.generated.h"

UCLASS()
class NLA_UE_PROJECT_API ASmallCircle : public AHUD
{
	GENERATED_BODY()

public:
	virtual void DrawHUD() override;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "SmallCircle")
	float Radius = 4.0f;

	UPROPERTY(EditDefaultsOnly, Category = "SmallCircle")
	FColor Color = FColor::Green;
};