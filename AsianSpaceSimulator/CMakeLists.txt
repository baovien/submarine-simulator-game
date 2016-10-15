cmake_minimum_required(VERSION 3.6)
project(Vietnamese_Space_Program)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp player.cpp player.h menu.cpp menu.h state.h entity.h playerobject.h gamemode1.cpp gamemode1.h)
add_executable(Vietnamese_Space_Program ${SOURCE_FILES})

# Link with SFML dependencies
target_link_libraries (Vietnamese_Space_Program sfml-graphics sfml-window sfml-system)