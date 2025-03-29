// MIT License Copyright (c) Artyom "Tricky Fat Cat" Volkov


#include "TrickyUserWidget.h"

DEFINE_LOG_CATEGORY(LogTrickyUserWidget);

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
		
#if WITH_EDITOR || !UE_BUILD_SHIPPING
		PrintLog("Show Animation Started");
#endif
		
	}
	else if (Animation == HideAnimation)
	{
		OnHideAnimationStarted.Broadcast();
		HandleHideAnimationStarted();
		
#if WITH_EDITOR || !UE_BUILD_SHIPPING
		PrintLog("Hide Animation Started");
#endif
		
	}
}

void UTrickyUserWidget::OnAnimationFinished_Implementation(const UWidgetAnimation* Animation)
{
	if (Animation == ShowAnimation)
	{
		SetVisibility(OnShowFinishedVisibilityState);
		OnShowAnimationFinished.Broadcast();
		HandleShowAnimationFinished();
		
#if WITH_EDITOR || !UE_BUILD_SHIPPING
		PrintLog("Show Animation Finished");
#endif
		
	}
	else if (Animation == HideAnimation)
	{
		SetVisibility(OnHideFinishedVisibilityState);
		OnHideAnimationFinished.Broadcast();
		HandleHideAnimationFinished();
		
#if WITH_EDITOR || !UE_BUILD_SHIPPING
		PrintLog("Hide Animation Finished");
#endif
		
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
	const float CurrentTime = GetAnimationCurrentTime(Animation);
	const float TargetTime = ((AnimationEndTime - CurrentTime) / AnimationEndTime) * NewAnimationEndTime;
	return TargetTime * static_cast<float>(IsAnimationPlaying(Animation));
}

#if WITH_EDITOR || !UE_BUILD_SHIPPING

void UTrickyUserWidget::PrintLog(const FString& Message) const
{
	const FString WidgetName = GetName();
	const FString LogMessage = FString::Printf(TEXT("Widget: %s | %s"), *WidgetName, *Message);
	UE_LOG(LogTrickyUserWidget, Display, TEXT("%s"), *LogMessage);
}

#endif
