// MIT License Copyright (c) Artyom "Tricky Fat Cat" Volkov


#include "TrickyUserWidget.h"

void UTrickyUserWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UTrickyUserWidget::Show()
{
	const float StartTime = CalculateAnimationStartTime(HideAnimation, ShowAnimation);
	PlayAnimation(ShowAnimation, StartTime);
}

void UTrickyUserWidget::Hide()
{
	const float StartTime = CalculateAnimationStartTime(ShowAnimation, HideAnimation);
	PlayAnimation(HideAnimation, StartTime);
}

void UTrickyUserWidget::OnAnimationStarted_Implementation(const UWidgetAnimation* Animation)
{
	SetVisibility(ESlateVisibility::HitTestInvisible);
	
	if (Animation == ShowAnimation)
	{
		OnShowAnimationStarted.Broadcast();
		HandleShowAnimationStarted();
	}
	else if (Animation == HideAnimation)
	{
		OnHideAnimationStarted.Broadcast();
		HandleHideAnimationStarted();
	}
}

void UTrickyUserWidget::OnAnimationFinished_Implementation(const UWidgetAnimation* Animation)
{
	if (Animation == ShowAnimation)
	{
		SetVisibility(OnShowFinishedVisibilityState);
		OnShowAnimationFinished.Broadcast();
		HandleShowAnimationFinished();
	}
	else if (Animation == HideAnimation)
	{
		SetVisibility(OnHideFinishedVisibilityState);
		OnHideAnimationFinished.Broadcast();
		HandleHideAnimationFinished();
	}
}

float UTrickyUserWidget::CalculateAnimationStartTime(const UWidgetAnimation* Animation,
	const UWidgetAnimation* NewAnimation) const
{
	if (!Animation || !NewAnimation)
	{
		return -1.f;
	}

	const float AnimationEndTime = Animation->GetEndTime();
	const float NewAnimationEndTime = NewAnimation->GetEndTime();
	const float TargetTime = ((AnimationEndTime - GetAnimationCurrentTime(Animation)) / AnimationEndTime) * NewAnimationEndTime;
	return TargetTime * static_cast<float>(IsAnimationPlaying(Animation));	
}
