# About

**TrickyUI** is a UI utility plugin for Unreal Engine 5 that provides enhanced widgets with built-in animation support.

## Features

- **Animation-Ready Widgets** - Easily implement show/hide animations with automatic visibility state management
- **Enhanced Button Widget** - Streamlined button implementation with comprehensive event handling
- **Blueprint Support** - Full Blueprint integration with intuitive BlueprintCallable functions and events

## Installation

1. Copy the plugin folder into your project's `Plugins` directory.
2. Open your Unreal Engine project.
3. Enable the **TrickyUI** in the plugins menu.
4. Restart the editor.

## Functionality Overview

### TrickyUserWidget

1. **Animation Management**
    - Automatically binds `ShowAnimation` and `HideAnimation` widget animations
    - Handles proper visibility states during and after animations
    - Provides animation transition smoothing when switching between show/hide states

2. **Key Functions**
    - **`Show()`**: Starts the show animation with transition handling
    - **`Hide()`**: Starts the hide animation with transition handling

3. **Events & Delegates**
    - **`OnShowAnimationStarted`**: Triggered when show animation begins
    - **`OnShowAnimationFinished`**: Triggered when show animation completes
    - **`OnHideAnimationStarted`**: Triggered when hide animation begins
    - **`OnHideAnimationFinished`**: Triggered when hide animation completes

4. **Customization**
    - **`OnShowFinishedVisibilityState`**: Configure widget visibility after show completes
    - **`OnHideFinishedVisibilityState`**: Configure widget visibility after hide completes
    - Blueprint implementable events for animation state changes

### TrickyButtonWidget

1. **Delegates**
    - **`OnButtonClicked`**: Triggered when button is clicked
    - **`OnButtonPressed`**: Triggered when button is pressed
    - **`OnButtonReleased`**: Triggered when button is released
    - **`OnButtonHovered`**: Triggered when button is hovered
    - **`OnButtonUnhovered`**: Triggered when cursor leaves the button

2. **Integration**
    - Inherits all animation capabilities from `TrickyUserWidget`
    - Automatic binding to the required `Button_Main` widget
