// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NLA_UE_ProjectGameMode.generated.h"

/**
 *  Simple GameMode for a first person game
 */
UCLASS(abstract)
class ANLA_UE_ProjectGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ANLA_UE_ProjectGameMode();
};



