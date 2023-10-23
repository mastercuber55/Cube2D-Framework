---
title: Rect
layout: default
nav_order: 1
parent: Classes
grand_parent: Documentation
has_children: true
---

# Rect

## Source Code
Its good to have a source code look at what you use then we will look on them one by one.
```cpp
// Rect, Used for easier rectangle manipulation
// Rect, Used for easier rectangle manipulation
struct Rect {
		
	// Variables
	float x, y, w, h;								
	double Rotation;

	std::string TextureFile;						
	Rectangle Source;								
	Color Tint;										

	// De-Constructers
	Rect(float x, float y, float w, float h);
	Rect(Rectangle Destination, Color Tint);	
	Rect(										
		Rectangle Destination, 
		std::string TextureFile, 
		Rectangle Source = CGE_WHOLE_FILE
	);
	~Rect();

	// Setters
	void SetPosition(Vector2 NewPosition);
	void operator=(Vector2 NewPosition);
	void SetTextureFile(std::string TextureFile); 

	// Getters
	Vector2 GetCenter();	
	Vector2 GetPosition();
	Vector2 GetRectangle();						
	operator Vector2() const;						
	operator Rectangle() const;						

	// Utilities
	bool IsColliding(Rect * Other);
	void Draw();									

};
```

## Example
```cpp

int main() {
	Engine::Init(640, 480, "Example");
	// Nothing sort of drawing is done here btw.
	Engine::Rect Player(0, 0, 32, 32, RED); 
	Engine::Close();
}

```

## Variables

### `float x, y, w, h`
Determines rectangle's position and size

### `double Rotation`
Determines rectangle's rotation

### `std::string TextureFile`
Determines the TextureFile rectangle is using, you should not modify this unless you are sure that, the TextureFile you provide has already been loaded.

### `Rectangle Source`
Determines the part of TextureFile that will be drawn for current rectangle.

### `Color Tint`
Determines the color of the rectangle upon drawing and also tints the rectangle's TextureFile upon drawing.

## Functions

### `Rect(float x, float y, float w, float h)`
Constructs a new instance with given position and size.

{: .note }
For [Cube2D Engine] users, this is the constructer binded into [wren].

### `Rect(Rectangle Destination, Color Tint)`
Constructs a new instance with given position, size and the given color using `Rect(float x, float y, float w, float h)`.

### Textured Constructer 
```cpp
Rect(										
		Rectangle Destination, 
		std::string TextureFile, 
		Rectangle Source = CGE_WHOLE_FILE
	);
```

Constructs a new instance ith given position, size and sets `Source` to given one and sets `Tint` to `WHITE` from [raylib] using `Rect(float x, float y, float w, float h)`.

### `void SetPosition(Vector2 NewPosition)`
Sets position to given one.

### `void operator=(Vector2 NewPosition)`
Calls `SetPosition` with given position.

### `void SetTextureFile(std::string TextureFile)`
Loads the given file if not loaded and sets the TextureFile rectangle is using to this one. This is the recommanded way to set rectangle's texture.

### `Vector2 GetCenter()`
Returns the rectangle's center's position.

### `Vector2 GetPosition()`
Returns the rectangle's top left corner's position.

### `Vector2 GetRectangle()`
Returns the size of the rectangle along with its top left corner's position.

### `operator Vector2() const`
Calls `GetPosition()` and returns returned value.

### `operator Rectangle() const;`
Calls `GetRectangle()` and returns returned value.

### `bool IsColliding(Rect * Other)`
Checks if two rectangles are colliding. Calls `CheckCollisionRecs` and returns returned value.

### `void Draw()`
Draws the rectangle to the screen.

[Cube2D Engine]: https://mastercuber55.github.io/Cube2D-Engine