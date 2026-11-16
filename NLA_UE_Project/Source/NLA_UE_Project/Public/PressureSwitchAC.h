#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PressureSwitchAC.generated.h"

class USceneComponent;
class UStaticMeshComponent;
class UBoxComponent;
class UMaterialInterface;

UCLASS()
class NLA_UE_PROJECT_API APressureSwitchAC : public AActor
{
	GENERATED_BODY()

public:
	APressureSwitchAC();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

public:
	// ---------- Components ----------
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* Root;

	// မလှုပ်သော အောက်ခံပြား
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* PlateBase;

	// နင်းလျှင် နစ်ဝင်သွားသော ခလုတ်ပြား
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* PlateButton;

	// ပစ္စည်း/Player ကို သိရှိရန် Trigger
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UBoxComponent* TriggerBox;

	// ---------- Switch ----------
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pressure Switch")
	bool bIsPressed = false;

	// Plate က အလုပ်လုပ်စေမည့် Gimmick များ
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pressure Switch")
	TArray<AActor*> TargetGimmicks;

	// Player နင်းလျှင် ON ဖြစ်မလား
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pressure Switch")
	bool bAcceptPlayer = true;

	// Physics ပစ္စည်း ချထားလျှင် ON ဖြစ်မလား
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pressure Switch")
	bool bAcceptPhysicsObjects = true;

	// သတ်မှတ်ထားလျှင် Class နှင့် Child ကိုသာ လက်ခံမည်။ ဗလာထားလျှင် Physics ပစ္စည်းအားလုံး လက်ခံမည်။
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pressure Switch")
	TSubclassOf<AActor> AcceptedObjectClass;

	// ---------- Visual ----------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pressure Switch|Visual")
	UMaterialInterface* OffMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pressure Switch|Visual")
	UMaterialInterface* OnMaterial;

	// နင်းလျှင် ခလုတ်ပြား နစ်ဝင်မည့် အနက်
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pressure Switch|Visual")
	float PressDepth = 5.0f;

	// နစ်ဝင်/ပြန်တက် မြန်နှုန်း
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pressure Switch|Visual")
	float PressSpeed = 10.0f;

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

private:
	// Actor သည် Plate ကို ON ဖြစ်စေနိုင်လား စစ်သည်
	bool IsValidActivator(AActor* Actor) const;

	// Trigger ထဲက ခွင့်ပြုထားသော Actor များကို ပြန်ရေ၍ ON/OFF ဆုံးဖြတ်သည်
	void UpdatePressedState(AActor* IgnoredActor = nullptr);

	// Gimmick များကို Activate / Deactivate လုပ်သည်
	void NotifyGimmicks(bool bActivate);

	FVector ReleasedLocation;
	FVector PressedLocation;
};