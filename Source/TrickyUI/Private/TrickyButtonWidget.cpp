// MIT License Copyright (c) Artyom "Tricky Fat Cat" Volkov


#include "TrickyButtonWidget.h"

#include "Components/Button.h"

void UTrickyButtonWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (IsValid(Button_Main))
	{
		Button_Main->OnClicked.AddUniqueDynamic(this, &UTrickyButtonWidget::HandleButtonClicked);
		Button_Main->OnPressed.AddUniqueDynamic(this, &UTrickyButtonWidget::HandleButtonPressed);
		Button_Main->OnReleased.AddUniqueDynamic(this, &UTrickyButtonWidget::HandleButtonReleased);
		Button_Main->OnHovered.AddUniqueDynamic(this, &UTrickyButtonWidget::HandleButtonHovered);
		Button_Main->OnUnhovered.AddUniqueDynamic(this, &UTrickyButtonWidget::HandleButtonUnhovered);
	}
}

void UTrickyButtonWidget::HandleButtonClicked()
{
	OnButtonClicked.Broadcast(this);

#if WITH_EDITOR || !UE_BUILD_SHIPPING
	PrintLog("Button Clicked");
#endif
}

void UTrickyButtonWidget::HandleButtonPressed()
{
	OnButtonPressed.Broadcast(this);
	
#if WITH_EDITOR || !UE_BUILD_SHIPPING
	PrintLog("Button Pressed");
#endif
}

void UTrickyButtonWidget::HandleButtonReleased()
{
	OnButtonReleased.Broadcast(this);
	
#if WITH_EDITOR || !UE_BUILD_SHIPPING
	PrintLog("Button Released");
#endif
}

void UTrickyButtonWidget::HandleButtonHovered()
{
	OnButtonHovered.Broadcast(this);
	
#if WITH_EDITOR || !UE_BUILD_SHIPPING
	PrintLog("Button Hovered");
#endif
}

void UTrickyButtonWidget::HandleButtonUnhovered()
{
	OnButtonUnhovered.Broadcast(this);
	
#if WITH_EDITOR || !UE_BUILD_SHIPPING
	PrintLog("Button Unhovered");
#endif
}
