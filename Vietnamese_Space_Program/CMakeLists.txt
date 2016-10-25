cmake_minimum_required(VERSION 3.6)
project(Vietnamese_Space_Program)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -pedantic")

set(SOURCE_FILES Graphics
        "Source Files/main.cpp"
        "Source Files/Entities/player.cpp" "Header Files/Entities/player.h"
        "Source Files/States/stateMenu.cpp" "Header Files/States/stateMenu.h"
        "Header Files/Core/state.h" "Header Files/Core/entity.h"
        "Header Files/Entities/playerobject.h"
        "Source Files/States/stateGameMode1.cpp" "Header Files/States/stateGameMode1.h"
        "Header Files/States/stateHighscoreState.h" "Source Files/States/stateHighscoreState.cpp"
        "Source Files/Core/score.cpp" "Header Files/Core/score.h"
        "Source Files/States/statePlayConfig.cpp" "Header Files/States/statePlayConfig.h"
        "Source Files/States/stateSettings.cpp" "Header Files/States/stateSettings.h"
        "Header Files/Core/util.h"
        "Source Files/Entities/enemy.cpp" "Header Files/Entities/enemy.h" "Header Files/Entities/enemyEntity.h"
        "Header Files/Entities/bullet.h" "Header Files/Entities/bulletEntity.h" "Source Files/Entities/bullets.cpp" "Source Files/Core/app.cpp" "Header Files/Core/app.h" "Source Files/Core/machine.cpp" "Header Files/Core/machine.h")

add_executable(Vietnamese_Space_Program ${SOURCE_FILES})

# Link with SFML dependencies
target_link_libraries(Vietnamese_Space_Program sfml-graphics sfml-window sfml-system)