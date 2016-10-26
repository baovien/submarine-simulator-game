cmake_minimum_required(VERSION 3.6)
project(Vietnamese_Space_Program)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -pedantic")

set(SOURCE_FILES Graphics
        "Source Files/main.cpp"
        "Source Files/Entities/player.cpp" "Header Files/Entities/player.h"
        "Source Files/States/stateMainMenu.cpp" "Header Files/States/stateMainMenu.h"
        "Header Files/Core/state.h" "Header Files/Core/entity.h"
        "Source Files/States/stateGameMode1.cpp" "Header Files/States/stateGameMode1.h"
        "Header Files/States/stateHighscoreState.h" "Source Files/States/stateHighscoreState.cpp"
        "Source Files/Core/score.cpp" "Header Files/Core/score.h"
        "Source Files/States/statePlayConfig.cpp" "Header Files/States/statePlayConfig.h"
        "Source Files/States/stateSettings.cpp" "Header Files/States/stateSettings.h"
        "Header Files/Core/util.h"
        "Source Files/Entities/enemy.cpp" "Header Files/Entities/enemy.h" "Header Files/Entities/enemyEntity.h"
        "Source Files/Core/app.cpp" "Header Files/Core/app.h" "Source Files/Core/machine.cpp" "Header Files/Core/machine.h" "Header Files/Core/entityManager.h" "Source Files/Core/entityManager.cpp" "Header Files/Entities/bullet.h" "Source Files/Entities/bullet.cpp" "Source Files/Core/entity.cpp")

add_executable(Vietnamese_Space_Program ${SOURCE_FILES})

# Link with SFML dependencies
target_link_libraries(Vietnamese_Space_Program sfml-graphics sfml-window sfml-system)