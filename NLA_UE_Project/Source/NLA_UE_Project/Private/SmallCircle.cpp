// Fill out your copyright notice in the Description page of Project Settings.


#include "SmallCircle.h"
#include "Engine/Canvas.h"
#include "CanvasItem.h"

void ASmallCircle::DrawHUD()
{
	Super::DrawHUD();

	if (Canvas == nullptr) return;

	FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

	float CrosshairWidth = 10.0f;
	float CrosshairHeight = 10.0f;

	FVector2D CrosshairPosition(Center.X - (CrosshairWidth * 0.5f), Center.Y - (CrosshairHeight * 0.5f));

	FLinearColor PurpleColor = FLinearColor(0.5f, 0.0f, 1.0f, 1.0f);

	FCanvasTileItem TileItem(CrosshairPosition, FVector2D(CrosshairWidth, CrosshairHeight), PurpleColor);
	TileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(TileItem);
}