// MIT License Copyright (c) Artyom "Tricky Fat Cat" Volkov

#pragma once

#include "CoreMinimal.h"
#include "Animation/WidgetAnimation.h"
#include "Blueprint/UserWidget.h"
#include "TrickyUserWidget.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTrickyUserWidget, Display, All);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAnimationStartedDynamicSignature);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAnimationFinishedDynamicSignature);

/**
 * An abstract widget class that extends UUserWidget to provide advanced animation functionality for show and hide animations.
 */
UCLASS(Abstract)
class TRICKYUI_API UTrickyUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeOnInitialized() override;

	/**
	 * Called when show animation started.
	 */
	UPROPERTY(BlueprintAssignable)
	FOnAnimationStartedDynamicSignature OnShowAnimationStarted;

	/**
	 * Called when show animation finished.
	 */
	UPROPERTY(BlueprintAssignable)
	FOnAnimationFinishedDynamicSignature OnShowAnimationFinished;

	/**
	 * Called when hide animation started.
	 */
	UPROPERTY(BlueprintAssignable)
	FOnAnimationStartedDynamicSignature OnHideAnimationStarted;

	/**
	 * Called when hide animation finished.
	 */
	UPROPERTY(BlueprintAssignable)
	FOnAnimationFinishedDynamicSignature OnHideAnimationFinished;

	/**
	 * Determines the visibility state of the widget when show animation finished.
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "TrickyUserWidget")
	ESlateVisibility OnShowFinishedVisibilityState  = ESlateVisibility::Visible;

	/**
	 * Determines the visibility state of the widget when show animation finished.
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "TrickyUserWidget")
	ESlateVisibility OnHideFinishedVisibilityState  = ESlateVisibility::Hidden;

	/**
	 * Initiates show animation for the widget.
	 */
	UFUNCTION(BlueprintCallable, Category = "TrickyUserWidget")
	void Show();

	/**
	 * Initiates hide animation for the widget.
	 */
	UFUNCTION(BlueprintCallable, Category = "TrickyUserWidget")
	void Hide();


protected:
	UPROPERTY(Transient, meta=(BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> ShowAnimation = nullptr;
	
	UPROPERTY(Transient, meta=(BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> HideAnimation = nullptr;

	/**
	 * Called when show animation starts playing.
	 */
	UFUNCTION(BlueprintImplementableEvent, Category = "TrickyUserWidget")
	void HandleShowAnimationStarted();

	/**
	 * Called when show animation ends playing.
	 */
	UFUNCTION(BlueprintImplementableEvent, Category = "TrickyUserWidget")
	void HandleShowAnimationFinished();

	/**
	 * Called when hide animation starts playing.
	 */
	UFUNCTION(BlueprintImplementableEvent, Category = "TrickyUserWidget")
	void HandleHideAnimationStarted();

	/**
	 * Called when hide animation ends playing.
	 */
	UFUNCTION(BlueprintImplementableEvent, Category = "TrickyUserWidget")
	void HandleHideAnimationFinished();

	virtual void OnAnimationStarted_Implementation(const UWidgetAnimation* Animation) override;

	virtual void OnAnimationFinished_Implementation(const UWidgetAnimation* Animation) override;

	float CalculateAnimationStartTime(const UWidgetAnimation* Animation, const UWidgetAnimation* NewAnimation) const;

#if WITH_EDITOR || !UE_BUILD_SHIPPING
	void PrintLog(const FString& Message) const;
#endif
};
