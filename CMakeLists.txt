cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(DoodleJump)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} src)

add_executable(SnakeGame src/main.cpp src/Game.cpp src/Camera.cpp src/CollisionHandler/cpp src/Doodle.cpp src/Inputs.cpp src/MapParser.cpp src/Menu.cpp src/TextureManager.cpp src/TileLayer.cpp src/Timer.cpp)
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(DoodleJump ${SDL2_LIBRARIES})
