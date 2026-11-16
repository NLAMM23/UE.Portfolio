#include "PressureSwitchAC.h"
#include "GimmickInterface.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Engine/StaticMesh.h"
#include "GameFramework/Pawn.h"
#include "Materials/MaterialInterface.h"
#include "UObject/ConstructorHelpers.h"
#include "Math/UnrealMathUtility.h"

APressureSwitchAC::APressureSwitchAC()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	PlateBase = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlateBase"));
	PlateBase->SetupAttachment(Root);

	PlateButton = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlateButton"));
	PlateButton->SetupAttachment(Root);

	// Cube Mesh ကို default အဖြစ် သုံးသည်
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (CubeMesh.Succeeded())
	{
		PlateBase->SetStaticMesh(CubeMesh.Object);
		PlateButton->SetStaticMesh(CubeMesh.Object);
	}

	// Cube Scale
	PlateBase->SetRelativeScale3D(FVector(1.2f, 1.2f, 0.1f));   
	PlateBase->SetRelativeLocation(FVector(0.f, 0.f, 5.f));      

	PlateButton->SetRelativeScale3D(FVector(1.0f, 1.0f, 0.1f)); 
	PlateButton->SetRelativeLocation(FVector(0.f, 0.f, 10.f));   

	// Trigger Box - Plate အပေါ်ပိုင်းကို ဖုံးထားသည်
	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	TriggerBox->SetupAttachment(Root);
	TriggerBox->SetRelativeLocation(FVector(0.f, 0.f, 30.f));
	TriggerBox->SetBoxExtent(FVector(45.f, 45.f, 25.f));

	// Collision: Pawn နှင့် PhysicsBody ကိုသာ Overlap၊ ကျန်အားလုံး Ignore
	TriggerBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	TriggerBox->SetCollisionObjectType(ECC_WorldDynamic);
	TriggerBox->SetCollisionResponseToAllChannels(ECR_Ignore);
	TriggerBox->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	TriggerBox->SetCollisionResponseToChannel(ECC_PhysicsBody, ECR_Overlap);
	TriggerBox->SetGenerateOverlapEvents(true);
}

void APressureSwitchAC::BeginPlay()
{
	Super::BeginPlay();

	ReleasedLocation = PlateButton->GetRelativeLocation();
	PressedLocation = ReleasedLocation - FVector(0.f, 0.f, PressDepth);

	if (OffMaterial)
	{
		PlateButton->SetMaterial(0, OffMaterial);
	}

	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &APressureSwitchAC::OnBeginOverlap);
	TriggerBox->OnComponentEndOverlap.AddDynamic(this, &APressureSwitchAC::OnEndOverlap);

	// ဂိမ်းစချိန်မှာ ပစ္စည်း Plate ပေါ်ရှိနှင့်ပြီးသားဖြစ်လျှင် ထည့်စစ်ရန်
	UpdatePressedState();
}

void APressureSwitchAC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const FVector Target = bIsPressed ? PressedLocation : ReleasedLocation;
	const FVector Current = PlateButton->GetRelativeLocation();

	if (!Current.Equals(Target, 0.1f))
	{
		PlateButton->SetRelativeLocation(FMath::VInterpTo(Current, Target, DeltaTime, PressSpeed));
	}
	else if (!Current.Equals(Target))
	{
		PlateButton->SetRelativeLocation(Target);
	}
}

void APressureSwitchAC::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	UpdatePressedState();
}

void APressureSwitchAC::OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	// ထွက်သွားသော Actor ကို သေချာစေရန် ဖယ်ထုတ်၍ ရေသည်
	UpdatePressedState(OtherActor);
}

bool APressureSwitchAC::IsValidActivator(AActor* Actor) const
{
	if (!Actor || Actor == this)
	{
		return false;
	}

	// Player စစ်ဆေးခြင်း
	if (const APawn* Pawn = Cast<APawn>(Actor))
	{
		return bAcceptPlayer && Pawn->IsPlayerControlled();
	}

	// Physics ပစ္စည်း စစ်ဆေးခြင်း
	if (!bAcceptPhysicsObjects)
	{
		return false;
	}

	if (AcceptedObjectClass && !Actor->IsA(AcceptedObjectClass))
	{
		return false;
	}

	const UPrimitiveComponent* Prim = Cast<UPrimitiveComponent>(Actor->GetRootComponent());
	return Prim && Prim->IsSimulatingPhysics();
}

void APressureSwitchAC::UpdatePressedState(AActor* IgnoredActor)
{
	TArray<AActor*> OverlappingActors;
	TriggerBox->GetOverlappingActors(OverlappingActors);

	int32 ValidCount = 0;
	for (AActor* Actor : OverlappingActors)
	{
		if (Actor != IgnoredActor && IsValidActivator(Actor))
		{
			++ValidCount;
		}
	}

	const bool bShouldBePressed = (ValidCount > 0);

	// အခြေအနေ မပြောင်းလျှင် ဘာမှမလုပ်ပါ
	if (bShouldBePressed == bIsPressed)
	{
		return;
	}

	bIsPressed = bShouldBePressed;

	if (UMaterialInterface* Mat = bIsPressed ? OnMaterial : OffMaterial)
	{
		PlateButton->SetMaterial(0, Mat);
	}

	NotifyGimmicks(bIsPressed);
}

void APressureSwitchAC::NotifyGimmicks(bool bActivate)
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