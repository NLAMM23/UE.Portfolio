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
    if (OtherActor && OtherActor != this && OtherActor == UGameplayStatics::GetPlayerPawn(this, 0))
    {
        if (!bIsActivated)
        {
            bIsActivated = true;

            // ၁။ ခလုတ်အရောင်ပြောင်းလဲခြင်း
            if (SwitchMesh && ChangeColorMaterial)
            {
                SwitchMesh->SetMaterial(0, ChangeColorMaterial);
            }

            // ၂။ Gimmick (Door) များကို ဖွင့်ရန် အလုပ်လုပ်ခိုင်းခြင်း
            for (AActor* Gimmick : TargetGimmicks)
            {
                if (Gimmick && Gimmick->GetClass()->ImplementsInterface(UGimmickInterface::StaticClass()))
                {
                    IGimmickInterface::Execute_ActivateGimmick(Gimmick);
                }
            }

            // ၃။ သတ်မှတ်ထားသော Camera Actor ဆီသို့ ကင်မရာ ပြောင်းလဲပြသခြင်း 
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
}