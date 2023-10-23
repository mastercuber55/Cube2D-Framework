---
title: GuiWindow
layout: default
nav_order: 3
parent: Classes
grand_parent: Documentation
has_children: true
---

# GuiWindow
{: .warning }
This class is not enabled by default and must be enabled in order to use by passing `-D CGE_RAYGUI` as one of CXXFLAGS.

## Source Code
Its good to have a source code look at what you use then we will look on them one by one.
```cpp
struct GuiWindow {

	bool Hidden;

	float x, y, w, h;
	std::string Title;

	GuiWindow(Rectangle Destination, std::string Title);

	void Update();
	void Draw(std::function<void(Vector2 Offset)> Function);
	
	private: bool Drag;
};
```

## Usage
Create a instance in your scene class and call its `Update` function in your scene's `Update` function and same goes for `Draw` function but a little different, pass a lamda function to the `Draw` function where you should add offset to your gui items.

## Variables

## `bool Hidden`
Determines if the window is hidden.

## `float x, y, w, h`
Determines the position and the size of the window.

## `std::string Title`
Determines the title of the window.

## `GuiWindow(Rectangle Destination, std::string Title)`
Constructs a new instance with given position, size and title.

## `void Update()`
Updates the window.

## `void Draw(std::function<void(Vector2 Offset)> Function)`
Draws the window to the screen along with the gui items inside `Function`.