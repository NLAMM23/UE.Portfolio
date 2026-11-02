#include "SwitchAC.h"
#include "GimmickInterface.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "NiagaraComponent.h"

ASwitchAC::ASwitchAC()
{
	PrimaryActorTick.bCanEverTick = true;

	SwitchMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SwitchMesh"));
	RootComponent = SwitchMesh;

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	TriggerBox->SetupAttachment(RootComponent);
	TriggerBox->SetBoxExtent(FVector(100.f, 100.f, 100.f));

	// Niagara Component
	LaserNiagaraComp = CreateDefaultSubobject<UNiagaraComponent>(TEXT("LaserNiagaraComp"));
	LaserNiagaraComp->SetupAttachment(RootComponent);

	LaserNiagaraComp->SetAutoActivate(false);
}

void ASwitchAC::BeginPlay()
{
	Super::BeginPlay();
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ASwitchAC::OnOverlapBegin);
}

void ASwitchAC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (TargetGimmick && bIsActivated)
	{
		FVector StartPos = GetActorLocation();
		FVector EndPos = TargetGimmick->GetActorLocation();

		if (LaserNiagaraComp)
		{
			LaserNiagaraComp->SetVariableVec3(TEXT("User.BeamEnd"), EndPos);
		}
	}
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

			bIsActivated = true;
			if (LaserNiagaraComp)
			{
				LaserNiagaraComp->Activate(true); // Niagara Effect
				LaserNiagaraComp->SetVisibility(true);
			}
		}
	}
}