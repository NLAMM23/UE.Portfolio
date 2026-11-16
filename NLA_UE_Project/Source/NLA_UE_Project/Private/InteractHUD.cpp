#include "InteractHUD.h"
#include "NLA_UE_ProjectCharacter.h"
#include "Engine/Canvas.h"
#include "Engine/Engine.h"
#include "Engine/Font.h"

void AInteractHUD::DrawHUD()
{
	Super::DrawHUD();

	if (!Canvas)
	{
		return;
	}

	const float CenterX = Canvas->SizeX * 0.5f;
	const float CenterY = Canvas->SizeY * 0.5f;

	// မျက်နှာပြင် အလယ်တွင် Crosshair ရေးဆွဲသည်
	DrawRect(FLinearColor::White, CenterX - 2.f, CenterY - 2.f, 4.f, 4.f);

	const ANLA_UE_ProjectCharacter* PlayerChar = Cast<ANLA_UE_ProjectCharacter>(GetOwningPawn());
	if (!PlayerChar || !PlayerChar->HasFocusedInteractable())
	{
		return; // Interact လုပ်လို့ရသော object မကြည့်နေလျှင် မပြပါ
	}

	const FString PromptText = FString::Printf(TEXT("[E]  %s"), *PlayerChar->GetFocusedInteractText().ToString());

	UFont* Font = GEngine->GetMediumFont();
	const float TextScale = 1.5f;

	float TextW = 0.f;
	float TextH = 0.f;
	GetTextSize(PromptText, TextW, TextH, Font, TextScale);

	const float PadX = 20.f;
	const float PadY = 10.f;
	const float BoxW = TextW + PadX * 2.f;
	const float BoxH = TextH + PadY * 2.f;
	const float BoxX = CenterX - BoxW * 0.5f;
	const float BoxY = CenterY + 80.f; // Crosshair အောက်သို့ ၈၀ px

	DrawRect(FLinearColor(0.f, 0.f, 0.f, 0.6f), BoxX, BoxY, BoxW, BoxH); // နောက်ခံရောင်
	DrawText(PromptText, FLinearColor::White, BoxX + PadX, BoxY + PadY, Font, TextScale);
}