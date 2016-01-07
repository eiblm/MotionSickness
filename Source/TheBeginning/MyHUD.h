// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

/**
 * 
 */
struct Icon
{
	FString name;
	UTexture2D* tex;
	Icon(){ name = "UNKNOWN ICON"; tex = 0; }
	Icon(FString& iName, UTexture2D* iTex)
	{
		name = iName;
		tex = iTex;
	}
};
struct Widget
{
	Icon icon;
	FVector2D pos, size;
	Widget(Icon iicon)
	{
		icon = iicon;
	}
	float left(){ return pos.X; }
	float right(){ return pos.X + size.X; }
	float top(){ return pos.Y; }
	float bottom(){ return pos.Y + size.Y; }
	bool hit(FVector2D p)
	{
		// +---+ top (0)
		// | |
		// +---+ bottom (2) (bottom > top)
		// L R
		return p.X > left() && p.X < right() && p.Y > top() && p.Y < bottom();
	}
};
struct Message
{
	FString message;
	float time;
	FColor color;
	FColor color2;
	UTexture2D* icon;
	Message()
	{
		// Set the default time.
		time = 5.f;
		color = FColor::White;
	}
	Message(FString iMessage, float iTime, FColor iColor)
	{
		message = iMessage;
		time = iTime;
		color = iColor;
	}
	Message(UTexture2D* iicon, FString iMessage, float iTime, FColor iColor1, FColor iColor2)
	{
		icon = iicon;
		message = iMessage;
		time = iTime;
		color = iColor1;
		color2 = iColor2;

	}
};

UCLASS()
class THEBEGINNING_API AMyHUD : public AHUD
{
	

	GENERATED_BODY()

public:
		// The font used to render the text in the HUD.
		//UPROPERTY()
		//UFont* hudFont;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUDFont)
	UFont* hudFont;
	TArray<Message>messages;
	// Add this function to be able to draw to the HUD!
	virtual void DrawHUD() override;
	//virtual void ShowHUD() override;
	void addMessage(Message msg);
	void DrawHealthbar();
	void DrawWidgets();
	void addWidget(Widget widget);
	void clearWidgets();
	TArray<Widget>widgets;
	Widget* heldWidget;
	void MouseClicked();
	void MouseMoved();
};
