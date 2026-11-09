#include "DoorActor.h"
#include "GimmickInterface.h"
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
	TargetLocation = ClosedLocation;
}

void ADoorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// TargetLocation သို့ VInterpTo ဖြင့် MoveSpeed အတိုင်း ဖြည်းဖြည်းချင်း ရွှေ့မည်
	FVector CurrentLocation = DoorMesh->GetRelativeLocation();
	if (!CurrentLocation.Equals(TargetLocation, 1.0f))
	{
		FVector NewLocation = FMath::VInterpTo(CurrentLocation, TargetLocation, DeltaTime, MoveSpeed);
		DoorMesh->SetRelativeLocation(NewLocation);
	}
}

void ADoorActor::ActivateGimmick_Implementation()
{
	CurrentActivatedCount++;

	// AND Condition (Switch အားလုံးပြည့်မှ တံခါးပွင့်မည်)
	if (CurrentActivatedCount >= RequiredSwitchCount)
	{
		bIsOpen = true; // တံခါးဖွင့်ရန် True လုပ်သည်
		TargetLocation = ClosedLocation + OpenOffset;
	}
}