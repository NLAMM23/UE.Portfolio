// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Camera/CameraActor.h"
#include "SwitchAC.generated.h"

UCLASS()
class NLA_UE_PROJECT_API ASwitchAC : public AActor
{
    GENERATED_BODY()

public:
    ASwitchAC();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

public:
    // Switch ၏ Mesh Component
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UStaticMeshComponent* SwitchMesh;

    // Trigger လုပ်မည့် Box Component
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UBoxComponent* TriggerBox;

    // ခလုတ် On / Off ဖြစ်နေသည်ကို မှတ်သားရန် (AND Logic အတွက် အဓိကသုံးမည်)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Switch")
    bool bIsOn = false;

    // တံခါး (Gimmick) အများအပြားကို ထည့်ရန် Array (Multiple Gimmicks)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Switch Settings")
    TArray<AActor*> TargetGimmicks;

    // သတ်မှတ်ထားသော Camera Actor
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Switch Settings")
    AActor* TargetCamera;

    // ခလုတ် အလုပ်လုပ်သွားသောအခါ ပြောင်းမည့် Material Color
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Switch Settings")
    UMaterialInterface* ChangeColorMaterial;

    // Overlap ဖြစ်ချိန်တွင် ခလုတ်နင်းမိခြင်းကို စစ်ဆေးရန် Function
    UFUNCTION()
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
        bool bFromSweep, const FHitResult& SweepResult);

private:
    // Level ထဲရှိ Switch အားလုံးကို စစ်ဆေးပြီး အကုန် ON လျှင် Gimmick များနှင့် Camera ကို ဖွင့်ပေးမည့် Function
    void CheckAllSwitchesAndTriggerGimmicks();
};