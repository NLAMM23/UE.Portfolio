// Copyright Epic Games, Inc. All Rights Reserved.

#include "SwitchAC.h"
#include "GimmickInterface.h"
#include "Kismet/GameplayStatics.h"

ASwitchAC::ASwitchAC()
{
	PrimaryActorTick.bCanEverTick = false;

	SwitchMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SwitchMesh"));
	RootComponent = SwitchMesh;

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	TriggerBox->SetupAttachment(RootComponent);
	TriggerBox->SetBoxExtent(FVector(100.f, 100.f, 100.f));

	// Pawn နှင့် Overlap ဖြစ်စေရန် သေချာသတ်မှတ်ခြင်း
	TriggerBox->SetCollisionProfileName(TEXT("OverlapOnlyPawn"));
	TriggerBox->SetGenerateOverlapEvents(true);
}

void ASwitchAC::BeginPlay()
{
	Super::BeginPlay();
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ASwitchAC::OnOverlapBegin);
}

void ASwitchAC::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	// ကစားသူ မဟုတ်လျှင် သို့မဟုတ် ON ဖြစ်ပြီးသားဆိုလျှင် ဘာမှမလုပ်ပါ
	if (bIsOn || !OtherActor || OtherActor != UGameplayStatics::GetPlayerPawn(this, 0))
	{
		return;
	}

	bIsOn = true;

	if (SwitchMesh && ChangeColorMaterial)
	{
		SwitchMesh->SetMaterial(0, ChangeColorMaterial);
	}

	TriggerGimmicks();
}

void ASwitchAC::TriggerGimmicks()
{
	// Switch တစ်ခုဖြင့် Gimmick အများကို လုပ်ဆောင်ခြင်း
	for (AActor* Gimmick : TargetGimmicks)
	{
		if (Gimmick && Gimmick->GetClass()->ImplementsInterface(UGimmickInterface::StaticClass()))
		{
			IGimmickInterface::Execute_ActivateGimmick(Gimmick);
		}
	}
}