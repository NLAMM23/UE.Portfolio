#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractInterface.h"
#include "InteractSwitchAC.generated.h"

class UStaticMeshComponent;
class UMaterialInterface;

UCLASS()
class NLA_UE_PROJECT_API AInteractSwitchAC : public AActor, public IInteractInterface
{
	GENERATED_BODY()

public:
	AInteractSwitchAC();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* Mesh;

	// လက်ရှိ ON ဖြစ်နေသလား
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Interact")
	bool bIsOn = false;

	// ON ဖြစ်ပြီးနောက် ထပ်နှိပ်၍ OFF ပြန်လုပ်နိုင်မလား (false ဆိုလျှင် တစ်ကြိမ်သာ)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interact")
	bool bCanToggleOff = true;

	// OFF ဖြစ်နေစဉ် ပြမည့်စာသား
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interact")
	FText PromptWhenOff = INVTEXT("Activate");

	// ON ဖြစ်နေစဉ် ပြမည့်စာသား
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interact")
	FText PromptWhenOn = INVTEXT("Deactivate");

	// ဤ Switch က အလုပ်လုပ်စေမည့် Gimmick များ (Door စသည်)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interact")
	TArray<AActor*> TargetGimmicks;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interact|Visual")
	UMaterialInterface* OffMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interact|Visual")
	UMaterialInterface* OnMaterial;

	// IInteractInterface
	virtual void Interact_Implementation(AActor* Interactor) override;
	virtual FText GetInteractText_Implementation() const override;
	virtual bool CanInteract_Implementation() const override;

protected:
	virtual void BeginPlay() override;

private:
	void ApplyVisual();
	void NotifyGimmicks(bool bActivate);
};