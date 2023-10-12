
# Cube2D Game Framework

Cube2D, a header only 2D easy-to-use game framework for making video games with raylib even easier written in C++11. 


## Features

- Easy To Use
- Header Only
- Customization
- Only [raylib](https://raylib.com) required
- Easier Rectangle Manipulation
- Sprite Management

### Upcoming Features

- Network Management
- Audio Management


## Installation & Configuration

```bash
git clone https://github.com/mastercuber55/Cube2D-Game-Framework.git
```

### Default

In just a SINGLE file `#define CGE_IMPL` before `#include <Cube2D.hpp>`

### Static Linking

Create a file named `Cube2D.cpp` with contents of `Cube2D.hpp` in it and run the following.

```bash
g++ -o Cube2D.o -c Cube2D.cpp -D CGE_IMPL -I"C:/raylib/include" && ar rcs libCube2D.a -o Cube2D.o
```

and link to it using `-lCube2D`




## Documentation
Everything is plain and simple so just look into the header's top part and you'll understand everything.


## License

[MIT](https://choosealicense.com/licenses/mit/)


## Usage/Examples

- [Physics Example](https://github.com/mastercuber55/Physics-Example)
- [Snake Game](https://github.com/mastercuber55/Snake-Game)

