# Capstone Project: Doodle Jump

This is the capstone project for the Udacity C++ Nanodegree Program.
This project is an imitation of the Doodle Jump game. The player can use left and right arrow keys to move on the screen, and the space bar to jump. Several features (such as scoring and looping tile map) are still under development.

## Class structure
The structure of the implementation of this game is listed below. Note that although the current version contains relatively few features, the structure of the program is designed in such a way that additional features can be added in a straightforward manner without the need to rewrite the whole program.
- Camera: 

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
