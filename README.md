# Capstone Project: Doodle Jump

This is the capstone project for the Udacity C++ Nanodegree Program (Option 1: build the project of your choice).

This project is an imitation of the Doodle Jump game. The player can use left and right arrow keys to move on the screen, and the space bar to jump. Several features (such as scoring and looping tile map) are still under development.

## Class Structure
The structure of the implementation of this game is listed below. Note that although the current version contains relatively few features, the structure of the program is designed in such a way that additional features can be added in a straightforward manner without the need to rewrite the whole program.
- Helper classes
  - TextureManager: manages displays of background, tile maps, and font
  - MapParser: parses and manages all tile maps
  - Timer: manages game time
- Player actions
  - Doodle: manages all rendering and updating behaviors of the player
  - Camera: allows for camera view centered at the player
  - Collider and CollisionHandler: handles collisions between the player and the tile map
  - Inputs: handles user inputs
  - RigidBody: handles game physics (gravity, force, velocity, etc)
- Game: main logic of the game (render, update, clean)

## Rubric Items

- The project demonstrates an understanding of C++ functions and control structures.
- The project reads data from a file and process the data, or the program writes data to a file. (e.g. TextureManager.cpp, TileLayer.cpp, MapParser.cpp)
- The project accepts user input and processes the input. (e.g. Inputs.cpp)
- The project uses Object Oriented Programming techniques.
- Classes use appropriate access specifiers for class members.
- Class constructors utilize member initialization lists. (e.g. TileLayer.cpp)
- Classes abstract implementation details from their interfaces. (e.g. Layer.hpp)
- Classes encapsulate behavior.
- Classes follow an appropriate inheritance hierarchy. (e.g. TileLayer inherits from Layer; Doodle inherits from GameObject)
- Derived class functions override virtual base class functions. (e.g. TileLayer.cpp)
- The project makes use of references in function declarations. (e.g. SDL_Rect)

## Dependencies for Running Locally
* cmake >= 3.11.3
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 7.4.0
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same instructions as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* SDL dependencies
  * Linux: 
    ```
    sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev
    ```
  * Windows and Mac:
    * SDL2 >= 2.0 : All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
    * SDL2_image : All installation instructions can be found [here](https://www.libsdl.org/projects/SDL_image/)
    * SDL2_ttf : All installation instructions can be found [here](https://www.libsdl.org/projects/SDL_ttf/)

## Basic Build Instructions
1. Clone this repo.
2. Make a build directory in the top level directory: mkdir build && cd build
3. Compile: cmake .. && make
4. Run it: ./DoodleJump.
