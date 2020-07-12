cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(DoodleJump)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)

include_directories(src)
include_directories(assets)

add_executable(DoodleJump src/main.cpp src/Game.cpp src/Camera.cpp src/CollisionHandler.cpp src/Doodle.cpp src/Inputs.cpp src/MapParser.cpp src/Menu.cpp src/TextureManager.cpp src/TileLayer.cpp src/Timer.cpp)

INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
PKG_SEARCH_MODULE(SDL2TTF REQUIRED SDL2_ttf>=2.0.0)
PKG_SEARCH_MODULE(TinyXML REQUIRED tinyxml)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${SDL2TTF_INCLUDE_DIRS} ${TinyXML_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(DoodleJump ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2TTF_LIBRARIES} ${TinyXML_LIBRARIES})

