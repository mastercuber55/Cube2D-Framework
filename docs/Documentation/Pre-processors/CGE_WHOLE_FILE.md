---
title: CGE_WHOLE_FILE
layout: default
nav_order: 2
parent: Pre-processors
grand_parent: Documentation
has_children: true
---

# CGE_WHOLE_FILE
It is defined as `{ 0, 0, -1, -1 }` which is used for using whole texture files. It is used in `Engine::Rect::Source`.

## Example
```cpp 
Engine::Rect Player(0, 0, 32, 32);
Player.Source = CGE_WHOLE_FILE;
```