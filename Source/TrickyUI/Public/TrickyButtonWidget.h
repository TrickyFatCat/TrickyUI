// MIT License Copyright (c) Artyom "Tricky Fat Cat" Volkov

#pragma once

#include "CoreMinimal.h"
#include "TrickyUserWidget.h"
#include "TrickyButtonWidget.generated.h"

class UButton;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnButtonClickedDynamicSignature, UTrickyButtonWidget*, Button);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnButtonPressedDynamicSignature, UTrickyButtonWidget*, Button);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnButtonReleasedDynamicSignature, UTrickyButtonWidget*, Button);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnButtonHoveredDynamicSignature, UTrickyButtonWidget*, Button);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnButtonUnhoveredDynamicSignature, UTrickyButtonWidget*, Button);

/**
 * An abstract user widget class that represents a customizable button with robust interaction event handling and dynamic signals.
 */
UCLASS(Abstract)
class TRICKYUI_API UTrickyButtonWidget : public UTrickyUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeOnInitialized() override;

	/**
	 * Triggered when the button is clicked.
	 */
	UPROPERTY(BlueprintAssignable)
	FOnButtonClickedDynamicSignature OnButtonClicked;

	/**
	 * Triggered when the button is pressed.
	 */
	UPROPERTY(BlueprintAssignable)
	FOnButtonPressedDynamicSignature OnButtonPressed;

	/**
	 * Triggered when the button is released.
	 */
	UPROPERTY(BlueprintAssignable)
	FOnButtonReleasedDynamicSignature OnButtonReleased;

	/**
	 * Triggered when the button is hovered.
	 */
	UPROPERTY(BlueprintAssignable)
	FOnButtonHoveredDynamicSignature OnButtonHovered;

	/**
	 * Triggered when the button is unhovered.
	 */
	UPROPERTY(BlueprintAssignable)
	FOnButtonUnhoveredDynamicSignature OnButtonUnhovered;

protected:
	UPROPERTY(BlueprintReadOnly, Category="ButtonWidget", meta=(BindWidget))
	TObjectPtr<UButton> Button_Main = nullptr;

private:
	UFUNCTION()
	void HandleButtonClicked();

	UFUNCTION()
	void HandleButtonPressed();

	UFUNCTION()
	void HandleButtonReleased();

	UFUNCTION()
	void HandleButtonHovered();

	UFUNCTION()
	void HandleButtonUnhovered();
};
