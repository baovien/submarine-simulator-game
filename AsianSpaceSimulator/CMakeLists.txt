cmake_minimum_required(VERSION 3.6)
project(AsianSpaceSimulator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp player.cpp player.h menu.cpp menu.h state.h entity.h playerobject.h gamemode1.cpp gamemode1.h)
add_executable(AsianSpaceSimulator ${SOURCE_FILES})

# Link with SFML dependencies
target_link_libraries (AsianSpaceSimulator sfml-graphics sfml-window sfml-system)