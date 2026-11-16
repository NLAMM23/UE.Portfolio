#include "DoorActor.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"
#include "TimerManager.h"
#include "Math/UnrealMathUtility.h"

ADoorActor::ADoorActor()
{
	PrimaryActorTick.bCanEverTick = true;

	DoorFrameMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorFrameMesh"));
	RootComponent = DoorFrameMesh;

	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	DoorMesh->SetupAttachment(RootComponent);
}

void ADoorActor::BeginPlay()
{
	Super::BeginPlay();
	ClosedLocation = DoorMesh->GetRelativeLocation();

	// Plate က BeginPlay မတိုင်ခင် Door ကို ခေါ်ခဲ့လျှင်လည်း မှန်ကန်စေရန်
	TargetLocation = bIsOpen ? ClosedLocation + OpenOffset : ClosedLocation;
}

void ADoorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const FVector CurrentLocation = DoorMesh->GetRelativeLocation();
	if (!CurrentLocation.Equals(TargetLocation, 0.1f))
	{
		DoorMesh->SetRelativeLocation(
			FMath::VInterpTo(CurrentLocation, TargetLocation, DeltaTime, MoveSpeed));
	}
	else if (!CurrentLocation.Equals(TargetLocation))
	{
		DoorMesh->SetRelativeLocation(TargetLocation);
	}
}

void ADoorActor::ActivateGimmick_Implementation()
{
	CurrentActivatedCount++;
	UpdateDoorState();
}

void ADoorActor::DeactivateGimmick_Implementation()
{
	CurrentActivatedCount = FMath::Max(0, CurrentActivatedCount - 1);
	UpdateDoorState();
}

void ADoorActor::UpdateDoorState()
{
	const bool bShouldOpen = (CurrentActivatedCount >= RequiredSwitchCount);

	// အခြေအနေ မပြောင်းလျှင် ဘာမှမလုပ်ပါ
	if (bShouldOpen == bIsOpen)
	{
		return;
	}

	bIsOpen = bShouldOpen;
	TargetLocation = bIsOpen ? (ClosedLocation + OpenOffset) : ClosedLocation;

	if (bIsOpen)
	{
		ShowCamera();
	}
}

void ADoorActor::ShowCamera()
{
	APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
	if (!PC || !TargetCamera)
	{
		return;
	}

	PC->SetViewTargetWithBlend(TargetCamera, 1.5f);

	TWeakObjectPtr<APlayerController> WeakPC(PC);
	FTimerHandle CameraTimerHandle;
	GetWorldTimerManager().SetTimer(CameraTimerHandle, [WeakPC]()
		{
			if (WeakPC.IsValid())
			{
				if (APawn* Pawn = WeakPC->GetPawn())
				{
					WeakPC->SetViewTargetWithBlend(Pawn, 1.0f);
				}
			}
		}, CameraHoldTime, false);
}