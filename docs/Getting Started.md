---
title: Getting Started
layout: default
nav_order: 2
---

# Getting Started

## Installation
Its a single header library so just download [Cube2D.hpp] and `#Include <Cube2D.hpp>` in your C++ file and in just a single file `#define CGE_IMPL` before including and as for any other files just `#Include <Cube2D.hpp>`.

## Configuration

### `CGE_SCENE_DEFAULT_BACKGROUND_COLOR` 
This is a macro defined by the framework if not pre defined, it defaults to `BLACK` from raylib but you can set it to anything you like at compilation time using `#define CGE_SCENE_DEFAULT_BACKGROUND_COLOR COLOR` or at runtime using `this->BackgroundColor = COLOR` in a `Engine::Scene`. 

### `CGE_DEFAULT_FPS`
This is a macro defined by the framework if not pre defined, it defaults to `60` but you can set it to anything you like at compilation time using `#define CGE_DEFAULT_FPS 30` or at runtime using `SetTargetFPS(30)` anywhere.

### `CGE_RAYGUI`
you define this macro, it is not defined by the framework. like `-DCGE_RAYGUI` as one of the `CXXFLAGS`.

[Cube2D.hpp]: https://github.com/mastercuber55/Cube2D-Framework/blob/main/Cube2D.hpp