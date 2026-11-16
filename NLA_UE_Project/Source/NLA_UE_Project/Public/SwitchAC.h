// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Materials/MaterialInterface.h"
#include "SwitchAC.generated.h"

UCLASS()
class NLA_UE_PROJECT_API ASwitchAC : public AActor
{
	GENERATED_BODY()

public:
	ASwitchAC();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* SwitchMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UBoxComponent* TriggerBox;

	// ခလုတ် ON ဖြစ်နေခြင်း ရှိမရှိ
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Switch")
	bool bIsOn = false;

	// Switch က အလုပ်လုပ်စေမည့် Gimmick များ - Level ထဲမှာ ရွေးထည့်ပါ
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Switch Settings")
	TArray<AActor*> TargetGimmicks;

	// ON ဖြစ်သွားလျှင် ပြောင်းမည့် Material
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Switch Settings")
	UMaterialInterface* ChangeColorMaterial;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult& SweepResult);

private:
	void TriggerGimmicks();
};