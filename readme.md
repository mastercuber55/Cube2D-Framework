
# Astro Raylib Framework
Behold Astro SDL Framework, a header only celestial game development framework like non other on our planet to make your games shine. it's a universe of stars at your fingertips for effortlessly enhancing your game's shining as you travel though the cosmic universe of game development and anticipate even more stars on the horizon to make your games shine even more joining the constellation of possibilities, expanding your cosmic playground.

#### Non Dramatic Description
A header only framework to make game development with raylib even easier, There is also a end of life framework named [Astro SDL Framework](https://github.com/mastercuber55/Astro-SDL-Framework)

## Why Choose Astro?

~Strikethrough~ ones are upcoming
 
 + C / C++
 + Easy To Use
 + Header Only
 + Customization
 + Fastest Installation
 + No Forced Dependendcies Expect Raylib
 + Easier Rectangle Manipulation
 + ~Sprite Management~
 + ~Audio Management~
 + ~Network Management~
 + Physics Integration
## Installation

Drop `Astro.h` in `raylib/include/` folder then instead of `#inlude <raylib.h>` in your `main` file do 
```c
#define _ASTRO_IMPLEMENTATION
#include <Astro.h>
```

To use physics engine, drop [`physac.h`](https://github.com/victorfisac/Physac/blob/master/src/physac.h) in `raylib/include/` folder then pass `-D_ASTRO_PHY` as one of `CFLAGS`/`CXXFLAGS`

You don't need to call `InitPhysics()` or `ClosePhysics()`
## License

[MIT](https://github.com/mastercuber55/Astro-Raylib-Framework/blob/main/LICENSE.txt)

