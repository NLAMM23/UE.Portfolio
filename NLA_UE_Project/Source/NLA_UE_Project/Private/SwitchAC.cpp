// Copyright Epic Games, Inc. All Rights Reserved.

#include "SwitchAC.h"
#include "GimmickInterface.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"

ASwitchAC::ASwitchAC()
{
    PrimaryActorTick.bCanEverTick = true;

    SwitchMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SwitchMesh"));
    RootComponent = SwitchMesh;

    TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
    TriggerBox->SetupAttachment(RootComponent);
    TriggerBox->SetBoxExtent(FVector(100.f, 100.f, 100.f));

    bIsOn = false; // ပထမအစပိုင်းတွင် ခလုတ်ပိတ်ထားမည် (Red)
}

void ASwitchAC::BeginPlay()
{
    Super::BeginPlay();
    TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ASwitchAC::OnOverlapBegin);
}

void ASwitchAC::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ASwitchAC::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
    bool bFromSweep, const FHitResult& SweepResult)
{
    // ကစားသူ (Player) နင်းမိခြင်း ရှိမရှိ စစ်ဆေးခြင်း
    if (OtherActor && OtherActor != this && OtherActor == UGameplayStatics::GetPlayerPawn(this, 0))
    {
        if (!bIsOn)
        {
            bIsOn = true; // ခလုတ်ပွင့်သွားပြီဟု မှတ်သားမည်

            // ၁။ ခလုတ်အရောင်ကို အစိမ်းရောင်သို့ ပြောင်းလဲခြင်း
            if (SwitchMesh && ChangeColorMaterial)
            {
                SwitchMesh->SetMaterial(0, ChangeColorMaterial);
            }

            // ၂။ Level ထဲရှိ Switch အားလုံး အကုန် On ပြီးပြီလား စစ်ဆေး၍ Gimmick & Camera စတင်ခြင်း
            CheckAllSwitchesAndTriggerGimmicks();
        }
    }
}

void ASwitchAC::CheckAllSwitchesAndTriggerGimmicks()
{
    // Level ထဲမှာရှိတဲ့ ASwitchAC မျိုးစိတ်ဝင် Switch အားလုံးကို ရှာယူခြင်း
    TArray<AActor*> FoundSwitches;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASwitchAC::StaticClass(), FoundSwitches);

    bool bAllSwitchesOn = true;

    for (AActor* Actor : FoundSwitches)
    {
        ASwitchAC* Switch = Cast<ASwitchAC>(Actor);
        if (Switch)
        {
            // တစ်ခုခု မပွင့်သေးဘူး (Red ဖြစ်နေသေး) ရင် bAllSwitchesOn ကို false လုပ်မည်
            if (!Switch->bIsOn)
            {
                bAllSwitchesOn = false;
                break;
            }
        }
    }

    // အကယ်၍ ခလုတ်အားလုံး (All Switches) အကုန် အစိမ်းရောင် (ON) ဖြစ်သွားမှသာ ဤနေရာအလုပ်လုပ်မည်
    if (bAllSwitchesOn)
    {
        // ၃။ Gimmick (Door များနှင့် အခြားပစ္စည်းများ) အားလုံးကို တစ်ပြိုင်နက် ဖွင့်ခြင်း (Multiple Gimmicks)
        for (AActor* Gimmick : TargetGimmicks)
        {
            if (Gimmick && Gimmick->GetClass()->ImplementsInterface(UGimmickInterface::StaticClass()))
            {
                IGimmickInterface::Execute_ActivateGimmick(Gimmick);
            }
        }

        // ၄။ သတ်မှတ်ထားသော Camera Actor ဆီသို့ ကင်မရာ ပြောင်းလဲပြသခြင်း (Camera Transition)
        APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
        if (PC && TargetCamera)
        {
            PC->SetViewTargetWithBlend(TargetCamera, 1.5f);

            FTimerHandle CameraTimerHandle;
            GetWorld()->GetTimerManager().SetTimer(CameraTimerHandle, [PC, this]()
                {
                    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
                    if (PC && PlayerPawn)
                    {
                        PC->SetViewTargetWithBlend(PlayerPawn, 1.0f);
                    }
                }, 3.0f, false);
        }
    }
}