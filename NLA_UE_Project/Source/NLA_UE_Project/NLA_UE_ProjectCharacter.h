// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "NLA_UE_ProjectCharacter.generated.h"

class UInputComponent;
class USkeletalMeshComponent;
class UCameraComponent;
class UInputAction;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

/** A basic first person character */
UCLASS(abstract)
class NLA_UE_PROJECT_API ANLA_UE_ProjectCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Pawn mesh: first person view (arms; seen only by self) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* FirstPersonMesh;

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FirstPersonCameraComponent;

protected:

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* LookAction;

	/** Mouse Look Input Action */
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* MouseLookAction;

	/** Grab Input Action (ပစ္စည်းကိုင်ရန်) */
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* GrabAction;

	/** Physics Handle Component(ပစ္စည်းကိုင်ဆောင်ရန်) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Physics")
	UPhysicsHandleComponent* PhysicsHandleComp;

public:
	ANLA_UE_ProjectCharacter();

	// Tick function (ပစ္စည်းကိုင်ထားစဉ် နေရာရွှေ့ရန်)
	virtual void Tick(float DeltaTime) override;

	// လက်ရှိ ကြည့်နေသော Interact object ရှိမရှိ (HUD)
	bool HasFocusedInteractable() const { return FocusedActor.IsValid(); }

	// မျက်နှာပြင်ပေါ် ပြမည့် စာသား (HUD) 
	FText GetFocusedInteractText() const { return FocusedText; }

protected:

	/** Called from Input Actions for movement input */
	void MoveInput(const FInputActionValue& Value);

	/** Called from Input Actions for looking input */
	void LookInput(const FInputActionValue& Value);

	// Grab နှင့် Release လုပ်ဆောင်ချက်များ
	void GrabObject();
	void ReleaseObject();

	virtual void BeginPlay() override;

	// E ခလုတ် နှိပ်လျှင် ခေါ်မည်
	void Interact();

	// Camera ရှေ့သို့ Trace ပစ်၍ Interact လုပ်လို့ရသော object ရှာမည်
	void UpdateInteractFocus();

	// Interact လုပ်နိုင်သော အကွာအဝေး
	UPROPERTY(EditAnywhere, Category = "Interact")
	float InteractDistance = 250.0f;

	/** Handles aim inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category = "Input")
	virtual void DoAim(float Yaw, float Pitch);

	/** Handles move inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category = "Input")
	virtual void DoMove(float Right, float Forward);

	/** Handles jump start inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category = "Input")
	virtual void DoJumpStart();

	/** Handles jump end inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category = "Input")
	virtual void DoJumpEnd();

protected:

	/** Set up input action bindings */
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

public:

	/** Returns the first person mesh **/
	USkeletalMeshComponent* GetFirstPersonMesh() const { return FirstPersonMesh; }

	/** Returns first person camera component **/
	UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

	// Physics Handle ကို ခေါ်သုံးရန်
	UPhysicsHandleComponent* GetPhysicsHandleComp() const { return PhysicsHandleComp; }

private:
		// လက်ရှိ ကြည့်နေသော Interact object
		TWeakObjectPtr<AActor> FocusedActor;

		// ထို object ပြမည့်စာသား
		FText FocusedText;
};