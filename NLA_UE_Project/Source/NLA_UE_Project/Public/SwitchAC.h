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
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UStaticMeshComponent* SwitchMesh;

    // Camera Actor သို့မဟုတ် AActor သတ်မှတ်ချက်
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Switch Settings")
    AActor* TargetCamera;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UBoxComponent* TriggerBox;

    // Gimmick Array (Door များစွာကို ချိတ်ဆက်ရန်)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Switch Settings")
    TArray<AActor*> TargetGimmicks;

    bool bIsActivated = false;

    UFUNCTION()
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
        bool bFromSweep, const FHitResult& SweepResult);
};