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
}

void UTrickyButtonWidget::HandleButtonPressed()
{
	OnButtonPressed.Broadcast(this);
}

void UTrickyButtonWidget::HandleButtonReleased()
{
	OnButtonReleased.Broadcast(this);
}

void UTrickyButtonWidget::HandleButtonHovered()
{
	OnButtonHovered.Broadcast(this);
}

void UTrickyButtonWidget::HandleButtonUnhovered()
{
	OnButtonUnhovered.Broadcast(this);
}
