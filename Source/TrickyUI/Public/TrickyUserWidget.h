// MIT License Copyright (c) Artyom "Tricky Fat Cat" Volkov

#pragma once

#include "CoreMinimal.h"
#include "Animation/WidgetAnimation.h"
#include "Blueprint/UserWidget.h"
#include "TrickyUserWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAnimationStartedDynamicSignature);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAnimationFinishedDynamicSignature);

/**
 * 
 */
UCLASS(Abstract)
class TRICKYUI_API UTrickyUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeOnInitialized() override;

	UPROPERTY(BlueprintAssignable)
	FOnAnimationStartedDynamicSignature OnShowAnimationStarted;

	UPROPERTY(BlueprintAssignable)
	FOnAnimationFinishedDynamicSignature OnShowAnimationFinished;

	UPROPERTY(BlueprintAssignable)
	FOnAnimationStartedDynamicSignature OnHideAnimationStarted;

	UPROPERTY(BlueprintAssignable)
	FOnAnimationFinishedDynamicSignature OnHideAnimationFinished;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "TrickyUserWidget")
	ESlateVisibility OnShowFinishedVisibilityState  = ESlateVisibility::Visible;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "TrickyUserWidget")
	ESlateVisibility OnHideFinishedVisibilityState  = ESlateVisibility::Hidden;

	UFUNCTION(BlueprintCallable, Category = "TrickyUserWidget")
	void Show();

	UFUNCTION(BlueprintCallable, Category = "TrickyUserWidget")
	void Hide();


protected:
	UPROPERTY(Transient, meta=(BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> ShowAnimation = nullptr;
	
	UPROPERTY(Transient, meta=(BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> HideAnimation = nullptr;

	UFUNCTION(BlueprintImplementableEvent, Category = "TrickyUserWidget")
	void HandleShowAnimationStarted();

	UFUNCTION(BlueprintImplementableEvent, Category = "TrickyUserWidget")
	void HandleShowAnimationFinished();

	UFUNCTION(BlueprintImplementableEvent, Category = "TrickyUserWidget")
	void HandleHideAnimationStarted();

	UFUNCTION(BlueprintImplementableEvent, Category = "TrickyUserWidget")
	void HandleHideAnimationFinished();

	virtual void OnAnimationStarted_Implementation(const UWidgetAnimation* Animation) override;

	virtual void OnAnimationFinished_Implementation(const UWidgetAnimation* Animation) override;

	float CalculateAnimationStartTime(const UWidgetAnimation* Animation, const UWidgetAnimation* NewAnimation) const;
};
