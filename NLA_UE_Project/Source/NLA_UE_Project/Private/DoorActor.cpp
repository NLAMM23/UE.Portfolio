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

	FVector CurrentLocation = DoorMesh->GetRelativeLocation();
	if (!CurrentLocation.Equals(TargetLocation, 1.0f))
	{
		FVector NewLocation = FMath::VInterpTo(CurrentLocation, TargetLocation, DeltaTime, MoveSpeed);
		DoorMesh->SetRelativeLocation(NewLocation);
	}
}

void ADoorActor::ActivateGimmick_Implementation()
{
	bIsOpen = !bIsOpen;
	TargetLocation = bIsOpen ? (ClosedLocation + OpenOffset) : ClosedLocation;
}