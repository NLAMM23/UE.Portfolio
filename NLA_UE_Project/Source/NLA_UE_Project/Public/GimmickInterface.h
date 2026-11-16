// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GimmickInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UGimmickInterface : public UInterface
{
	GENERATED_BODY()
};

class NLA_UE_PROJECT_API IGimmickInterface
{
	GENERATED_BODY()

public:
	// Switch ON ဖြစ်သောအခါ ခေါ်မည်
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Gimmick")
	void ActivateGimmick();

	// Switch OFF ပြန်ဖြစ်သောအခါ ခေါ်မည်
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Gimmick")
	void DeactivateGimmick();
};