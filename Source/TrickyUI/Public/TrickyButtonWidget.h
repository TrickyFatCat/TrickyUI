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
 * 
 */
UCLASS(Abstract)
class TRICKYUI_API UTrickyButtonWidget : public UTrickyUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeOnInitialized() override;

	UPROPERTY(BlueprintAssignable)
	FOnButtonClickedDynamicSignature OnButtonClicked;

	UPROPERTY(BlueprintAssignable)
	FOnButtonPressedDynamicSignature OnButtonPressed;

	UPROPERTY(BlueprintAssignable)
	FOnButtonReleasedDynamicSignature OnButtonReleased;

	UPROPERTY(BlueprintAssignable)
	FOnButtonHoveredDynamicSignature OnButtonHovered;

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
