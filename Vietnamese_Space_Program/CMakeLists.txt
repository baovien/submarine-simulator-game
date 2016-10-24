cmake_minimum_required(VERSION 3.6)
project(Vietnamese_Space_Program)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -pedantic")

set(SOURCE_FILES Graphics
        "Source Files/main.cpp"
        "Source Files/Entities/Player.cpp" "Header Files/Entities/Player.h"
        "Source Files/States/menu.cpp" "Header Files/States/menu.h"
        "Header Files/Core/state.h" "Header Files/Core/entity.h"
        "Header Files/Entities/playerobject.h"
        "Source Files/States/Gamemode1.cpp" "Header Files/States/Gamemode1.h"
        "Header Files/States/highscoreState.h" "Source Files/States/highscoreState.cpp"
        "Source Files/States/Score.cpp" "Header Files/States/Score.h"
        "Source Files/States/playconfig.cpp" "Header Files/States/playconfig.h"
        "Source Files/States/SettingsState.cpp" "Header Files/States/SettingsState.h"
        "Header Files/Core/util.h"
        "Source Files/Entities/enemy.cpp" "Header Files/Entities/enemy.h" "Header Files/Entities/enemy_entity.h"
        "Header Files/Entities/Bullet.h" "Header Files/Entities/BulletEntity.h" "Source Files/Entities/bullets.cpp")

add_executable(Vietnamese_Space_Program ${SOURCE_FILES})

# Link with SFML dependencies
target_link_libraries(Vietnamese_Space_Program sfml-graphics sfml-window sfml-system)