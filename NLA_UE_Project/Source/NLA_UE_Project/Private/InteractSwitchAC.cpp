#include "InteractSwitchAC.h"
#include "GimmickInterface.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Materials/MaterialInterface.h"
#include "UObject/ConstructorHelpers.h"

AInteractSwitchAC::AInteractSwitchAC()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	// Engine Cube ကို Default (Editor တွင် ပြောင်းနိုင်သည်)
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (CubeMesh.Succeeded())
	{
		Mesh->SetStaticMesh(CubeMesh.Object);
	}
	Mesh->SetRelativeScale3D(FVector(0.5f, 0.5f, 1.0f));

	// Visibility Trace ကို Block လုပ်ရမည် (Line Trace ထိမိရန်)
	Mesh->SetCollisionProfileName(TEXT("BlockAll"));
}

void AInteractSwitchAC::BeginPlay()
{
	Super::BeginPlay();
	ApplyVisual();
}

void AInteractSwitchAC::Interact_Implementation(AActor* Interactor)
{
	if (!CanInteract_Implementation())
	{
		return;
	}

	bIsOn = !bIsOn;
	ApplyVisual();
	NotifyGimmicks(bIsOn);
}

FText AInteractSwitchAC::GetInteractText_Implementation() const
{
	return bIsOn ? PromptWhenOn : PromptWhenOff;
}

bool AInteractSwitchAC::CanInteract_Implementation() const
{
	// OFF ဖြစ်နေလျှင် အမြဲရ၊ ON ဖြစ်နေလျှင် bCanToggleOff ဖွင့်ထားမှ ရ
	return !bIsOn || bCanToggleOff;
}

void AInteractSwitchAC::ApplyVisual()
{
	UMaterialInterface* Mat = bIsOn ? OnMaterial : OffMaterial;
	if (Mesh && Mat)
	{
		Mesh->SetMaterial(0, Mat);
	}
}

void AInteractSwitchAC::NotifyGimmicks(bool bActivate)
{
	for (AActor* Gimmick : TargetGimmicks)
	{
		if (Gimmick && Gimmick->GetClass()->ImplementsInterface(UGimmickInterface::StaticClass()))
		{
			if (bActivate)
			{
				IGimmickInterface::Execute_ActivateGimmick(Gimmick);
			}
			else
			{
				IGimmickInterface::Execute_DeactivateGimmick(Gimmick);
			}
		}
	}
}