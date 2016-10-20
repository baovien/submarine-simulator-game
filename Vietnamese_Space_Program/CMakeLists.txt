cmake_minimum_required(VERSION 3.6)
project(Vietnamese_Space_Program)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -pedantic")

set(SOURCE_FILES "Source Files/main.cpp" "Source Files/Entities/player.cpp" "Header Files/Entities/player.h"
        "Source Files/States/menu.cpp" "Header Files/States/menu.h" "Header Files/Core/state.h" "Header Files/Core/entity.h"
        "Header Files/Entities/playerobject.h" "Source Files/States/gamemode1.cpp" "Header Files/States/gamemode1.h" Graphics
        "Source Files/States/playconfig.cpp" "Header Files/States/playconfig.h")
add_executable(Vietnamese_Space_Program ${SOURCE_FILES})

# Link with SFML dependencies
target_link_libraries(Vietnamese_Space_Program sfml-graphics sfml-window sfml-system)