---
title: Scene
layout: default
nav_order: 1
parent: Documentation
grand_parent: Classes
has_children: true
---

# Scene

## Source Code
Its good to have a source code look at what you use then we will look on them one by one.
```cxx
// Scene, Used for scene management.
struct Scene {

	Color BackgroundColor;
	bool KeepRunning;
	int CodeToReturn;

	Scene(Color BackgroundColor = CGE_SCENE_DEFAULT_BACKGROUND_COLOR);
	virtual bool ShouldClose();
	virtual int Run();
	virtual void Close(int CodeToReturn = 0);
	virtual void Update();
	virtual void Draw();

	~Scene();
};
```

## Example
```cxx
struct SceneExample : Engine::Scene {
	// Variables

	SceneExample() {}
	void Update() override {}
	void Draw() override {}
	~SceneExample() {}
}

int main() {
	Engine::Init(640, 480, "Example")
	SceneExample().Run();
	Engine::Close();
}

```

## Variables

### `Color BackgroundColor`
Determines what color the background is or should be.

### `bool KeepRunning`
Determines if the current scene should keep running.

### `int CodeToReturn`
Determines code to return when `Run`ning the current scene has finished.

## Functions

### `Scene(Color BackgroundColor = CGE_SCENE_DEFAULT_BACKGROUND_COLOR);`
Constructs a new instance with given background color.

### `virtual bool ShouldClose()`
Determines if the current scene should close. To Be Overriden.

### `virtual int Run()`
Runs the current scene recommanded to not override.

### `virtual void Close(int CodeToReturn = 0)`
Sets `KeepRunning` to `false` and sets `CodeToReturn` to given one.

### `virtual void Update()`
For updating your scene's game logic and stuff. To Be Overriden.

### `virtual void Draw()`
For drawing your scene's game and stuff. You don't need to call `BeginDrawing`, `ClearBackground`, `EndDrawing` as you would've done in [raylib]. To Be Overriden. 

### `~Scene()`
Destructs current instance.