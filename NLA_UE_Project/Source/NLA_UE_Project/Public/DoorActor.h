#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "GimmickInterface.h"
#include "DoorActor.generated.h"

UCLASS()
class NLA_UE_PROJECT_API ADoorActor : public AActor, public IGimmickInterface
{
	GENERATED_BODY()

public:
	ADoorActor();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* DoorFrameMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* DoorMesh;

	// တံခါးဖွင့်ရန် လိုအပ်သော Switch အရေအတွက်
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door Settings")
	int32 RequiredSwitchCount = 1;

	// လက်ရှိ ON ဖြစ်နေသော Switch အရေအတွက်
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door Settings")
	int32 CurrentActivatedCount = 0;

	// တံခါးပွင့်ချိန် ပြသမည့် Camera
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door Settings")
	AActor* TargetCamera = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door Settings")
	float CameraHoldTime = 3.0f;

	virtual void ActivateGimmick_Implementation() override;
	virtual void DeactivateGimmick_Implementation() override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Door Settings")
	bool bIsOpen = false;

	FVector ClosedLocation;
	FVector TargetLocation;

	UPROPERTY(EditAnywhere, Category = "Door Settings")
	FVector OpenOffset = FVector(0.f, 0.f, 150.f);

	UPROPERTY(EditAnywhere, Category = "Door Settings")
	float MoveSpeed = 3.0f;

	// Count ကို ကြည့်ပြီး ဖွင့်/ပိတ် ဆုံးဖြတ်ပေးသော function
	void UpdateDoorState();
	void ShowCamera();
};