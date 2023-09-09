
# Astro Raylib Framework
Behold Astro Raylib Framework, a header only C/C++ celestial game development framework like non other on our planet to make your games shine. it's a universe of stars at your fingertips for effortlessly enhancing your game's shining as you travel though the cosmic universe of game development and anticipate even more stars on the horizon to make your games shine even more joining the constellation of possibilities, expanding your cosmic playground.

#### Non Dramatic Description
A header C/C++ only framework to make game development with raylib even easier.

### Wait what? You use SDL? 
Don't worry, I've made a SDL version too

[Astro SDL Framework](https://github.com/mastercuber55/Astro-SDL-Framework)

## Why Choose Astro?

~Strikethrough~ ones are upcoming
 
 + C / C++
 + Easy To Use
 + Header Only
 + Customization
 + No Forced Dependendcies Expect Raylib
 + Easier Rectangle Manipulation
 + Sprite Management
 + ~Audio Management~
 + ~Network Management~
 + Physics Integration
## Installation & Configuration

    git clone https://github.com/mastercuber55/Astro-Raylib-Framework.git --recursive

Copy `./Astro-Raylib-Framework/Astro.h` & `./Astro-Raylib-Framework/Physac/src/physac.h` and put them in a include path [ I like raylib/include. ]
In any SINGLE source file `#define ASTRO_IMPLEMENTATION`.
It will copy the implementation of Astro and physac into that source file that you don't edit very much.
[main.c/main.cpp for me. ] and as for other files just regular old `#include <Astro.h>`

If you are going to use [Physac] then pass `-DASTRO_PHY` as a one of CFLAGS/CXXFLAGS

## Documentation

Everything is plain and simple, just look the non - implementation section of the header


## Usage/Examples
- [Physics Example](https://github.com/mastercuber55/Physics-Example)
- [Snake Game](https://github.com/mastercuber55/Snake-Game)

## License

[MIT](https://github.com/mastercuber55/Astro-Raylib-Framework/blob/main/LICENSE.txt)

