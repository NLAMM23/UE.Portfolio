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

	virtual void ActivateGimmick_Implementation() override;

private:
	UPROPERTY(EditAnywhere, Category = "Door Settings")
	bool bIsOpen = false;

	FVector ClosedLocation;
	FVector TargetLocation;

	UPROPERTY(EditAnywhere, Category = "Door Settings")
	FVector OpenOffset = FVector(0.f, 0.f, 150.f);

	UPROPERTY(EditAnywhere, Category = "Door Settings")
	float MoveSpeed = 0.5f;
};