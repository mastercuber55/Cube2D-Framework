---
title: Home
layout: home
nav_order: 1
---

# Home

Cube2D Framework, A minimal 2D simple and easy to use game development framework written in C++11 that makes [raylib] even easier to use.

## Features

- Minimal
- Simple And Easy To Use
- Highly Customizable
- Automatic asset management
- Scene Management

## Upcoming
They maybe canceled later on.
- Networking with [nbnet]
- Audio Management
- Shapes other than Rect.
- Whatever [Issues On Github] says.

## Example

Whats a programming project without example on its home page?

```cpp

// File: SceneGame.cpp
// Scene Management
// Creating A Simple Player

#include <Cube2D.hpp>

class SceneGame : Engine::Scene {
		
	Engine::Rect Player;

	SceneGame() : Player(0, 0, 32, 32) {
		Player.Tint = RED;
	}
	Update() {
		var Speed = 10;
		Engine::WASDMovement(Player, Speed);
	}
	Draw() {
		Player.Draw();
	}
}
```
If you notice, its same to same as [Cube2D Engine]'s home page example.

[raylib]: https://raylib.com
[nbnet]: https://nathhb.github.io/nbnet
[Cube2D Engine]: https://mastercuber55.github.io/Cube2D-Engine
[Issues On Github]: https://github.com/mastercuber55/Cube2D-Framework/issues