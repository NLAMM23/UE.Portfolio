#include "SwitchAC.h"
#include "GimmickInterface.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

ASwitchAC::ASwitchAC()
{
	PrimaryActorTick.bCanEverTick = false;

	SwitchMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SwitchMesh"));
	RootComponent = SwitchMesh;

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	TriggerBox->SetupAttachment(RootComponent);
	TriggerBox->SetBoxExtent(FVector(100.f, 100.f, 100.f));
}

// Called when the game starts or when spawned
void ASwitchAC::BeginPlay()
{
	Super::BeginPlay();
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ASwitchAC::OnOverlapBegin);
}

void ASwitchAC::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this && TargetGimmick)
	{
		if (TargetGimmick->GetClass()->ImplementsInterface(UGimmickInterface::StaticClass()))
		{
			IGimmickInterface::Execute_ActivateGimmick(TargetGimmick);
		}
	}
}