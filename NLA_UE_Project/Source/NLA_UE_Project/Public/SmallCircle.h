// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SmallCircle.generated.h"

/**
 * 
 */
UCLASS()
class NLA_UE_PROJECT_API ASmallCircle : public AHUD
{
	GENERATED_BODY()

public:
	virtual void DrawHUD() override;
	
};
