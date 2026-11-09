// Copyright Epic Games, Inc. All Rights Reserved.

#include "NLA_UE_ProjectCharacter.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "NLA_UE_Project.h"

ANLA_UE_ProjectCharacter::ANLA_UE_ProjectCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	// Create the first person mesh that will be viewed only by this character's owner
	FirstPersonMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("First Person Mesh"));

	FirstPersonMesh->SetupAttachment(GetMesh());
	FirstPersonMesh->SetOnlyOwnerSee(true);
	FirstPersonMesh->FirstPersonPrimitiveType = EFirstPersonPrimitiveType::FirstPerson;
	FirstPersonMesh->SetCollisionProfileName(FName("NoCollision"));

	// Create the Camera Component	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("First Person Camera"));
	FirstPersonCameraComponent->SetupAttachment(FirstPersonMesh, FName("head"));
	FirstPersonCameraComponent->SetRelativeLocationAndRotation(FVector(-2.8f, 5.89f, 0.0f), FRotator(0.0f, 90.0f, -90.0f));
	FirstPersonCameraComponent->bUsePawnControlRotation = true;
	FirstPersonCameraComponent->bEnableFirstPersonFieldOfView = true;
	FirstPersonCameraComponent->bEnableFirstPersonScale = true;
	FirstPersonCameraComponent->FirstPersonFieldOfView = 70.0f;
	FirstPersonCameraComponent->FirstPersonScale = 0.6f;

	// configure the character comps
	GetMesh()->SetOwnerNoSee(true);
	GetMesh()->FirstPersonPrimitiveType = EFirstPersonPrimitiveType::WorldSpaceRepresentation;

	GetCapsuleComponent()->SetCapsuleSize(34.0f, 96.0f);

	// Configure character movement
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;
	GetCharacterMovement()->AirControl = 0.5f;

	// Physics Handle Component ဖန်တီးခြင်း
	PhysicsHandleComp = CreateDefaultSubobject<UPhysicsHandleComponent>(TEXT("PhysicsHandleComp"));
}

void ANLA_UE_ProjectCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ANLA_UE_ProjectCharacter::DoJumpStart);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ANLA_UE_ProjectCharacter::DoJumpEnd);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ANLA_UE_ProjectCharacter::MoveInput);

		// Looking/Aiming
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ANLA_UE_ProjectCharacter::LookInput);
		EnhancedInputComponent->BindAction(MouseLookAction, ETriggerEvent::Triggered, this, &ANLA_UE_ProjectCharacter::LookInput);

		// Grab Action (ပစ္စည်းကိုင်ရန်/ချရန်)
		EnhancedInputComponent->BindAction(GrabAction, ETriggerEvent::Started, this, &ANLA_UE_ProjectCharacter::GrabObject);
	}
	else
	{
		UE_LOG(LogNLA_UE_Project, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void ANLA_UE_ProjectCharacter::MoveInput(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();
	DoMove(MovementVector.X, MovementVector.Y);
}

void ANLA_UE_ProjectCharacter::LookInput(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();
	DoAim(LookAxisVector.X, LookAxisVector.Y);
}

void ANLA_UE_ProjectCharacter::DoAim(float Yaw, float Pitch)
{
	if (GetController())
	{
		AddControllerYawInput(Yaw);
		AddControllerPitchInput(Pitch);
	}
}

void ANLA_UE_ProjectCharacter::DoMove(float Right, float Forward)
{
	if (GetController())
	{
		AddMovementInput(GetActorRightVector(), Right);
		AddMovementInput(GetActorForwardVector(), Forward);
	}
}

void ANLA_UE_ProjectCharacter::DoJumpStart()
{
	Jump();
}

void ANLA_UE_ProjectCharacter::DoJumpEnd()
{
	StopJumping();
}

void ANLA_UE_ProjectCharacter::GrabObject()
{
	if (!PhysicsHandleComp) return;

	// လက်ရှိ ကိုင်ထားပြီးသား ရှိမရှိ စစ်ဆေးခြင်း
	if (PhysicsHandleComp->GetGrabbedComponent())
	{
		ReleaseObject();
		return;
	}

	// ကင်မရာမှ ရှေ့သို့ Raycast ပစ်ရန် နေရာသတ်မှတ်ခြင်း
	FVector Start = GetFirstPersonCameraComponent()->GetComponentLocation();
	FVector ForwardVector = GetFirstPersonCameraComponent()->GetForwardVector();
	FVector End = Start + (ForwardVector * 300.0f); // အကွာအဝေး unit

	FHitResult HitResult;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);

	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_PhysicsBody, Params);

	if (bHit)
	{
		UPrimitiveComponent* HitComponent = HitResult.GetComponent();

		// ထိမိသော ပစ္စည်းတွင် Simulate Physics စစ်ဆေးခြင်း
		if (HitComponent && HitComponent->IsSimulatingPhysics())
		{
			PhysicsHandleComp->GrabComponentAtLocationWithRotation(
				HitComponent,
				NAME_None,
				HitResult.ImpactPoint,
				HitComponent->GetComponentRotation()
			);
		}
	}
}

void ANLA_UE_ProjectCharacter::ReleaseObject()
{
	if (PhysicsHandleComp && PhysicsHandleComp->GetGrabbedComponent())
	{
		PhysicsHandleComp->ReleaseComponent();
	}
}

void ANLA_UE_ProjectCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// ပစ္စည်းကိုင်ထားဆဲ ဖြစ်ပါက တည်နေရာကို ကစားသူရှေ့သို့ ရွှေ့ပေးနေမည်
	if (PhysicsHandleComp && PhysicsHandleComp->GetGrabbedComponent())
	{
		FVector Start = GetFirstPersonCameraComponent()->GetComponentLocation();
		FVector ForwardVector = GetFirstPersonCameraComponent()->GetForwardVector();
		FVector TargetLocation = Start + (ForwardVector * 200.0f); // ကစားသူရှေ့ အကွာအဝေး unit

		PhysicsHandleComp->SetTargetLocationAndRotation(TargetLocation, GetFirstPersonCameraComponent()->GetComponentRotation());
	}
}