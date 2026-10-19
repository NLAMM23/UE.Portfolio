#include "SmallCircle.h"
#include "Engine/Canvas.h"

void ASmallCircle::DrawHUD()
{
	Super::DrawHUD();

	if (!Canvas)
	{
		return;
	}

	const float CenterX = Canvas->ClipX * 0.5f;
	const float CenterY = Canvas->ClipY * 0.5f;

	const int32 a = FMath::CeilToInt(Radius);


	for (int32 i = -a; i < a; ++i)
	{
		const float b = i + 0.5f;
		const float HalfWdith = FMath::Sqrt(FMath::Max(0.0f, Radius * Radius - b * b));
		DrawRect(Color, CenterX - HalfWdith, CenterY + i, HalfWdith * 2.0f, 1.0f);
	}
}