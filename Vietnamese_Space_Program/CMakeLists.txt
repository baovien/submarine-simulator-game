cmake_minimum_required(VERSION 3.6)
project(Vietnamese_Space_Program)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -pedantic")

set(SOURCE_FILES
        Graphics Audio

        "Source/main.cpp"

        #Core Headers
        "Include/Core/app.h"                   "Source/Core/app.cpp"
        "Include/Core/entity.h"                "Source/Core/entity.cpp"
        "Include/Core/entityManager.h"         "Source/Core/entityManager.cpp"
        "Include/Core/machine.h"               "Source/Core/machine.cpp"
        "Include/Core/playerLives.h"           "Source/Core/playerLives.cpp"
        "Include/Core/state.h"
        "Include/Core/score.h"                 "Source/Core/score.cpp"
        "Include/Core/util.h"
        "Include/Core/soundLoader.h"           "Source/Core/soundLoader.cpp"

        #Entities Headers
        "Include/Entities/asteroid.h"          "Source/Entities/asteroid.cpp"
        "Include/Entities/boss1.h"             "Source/Entities/boss1.cpp"
        "Include/Entities/bullet.h"            "Source/Entities/bullet.cpp"
        "Include/Entities/player.h"
        "Include/Entities/enemy.h"             "Source/Entities/enemy.cpp"
        "Include/Entities/overheat.h"          "Source/Entities/overheat.cpp"
        "Include/Entities/healthPack.h"        "Source/Entities/healthPack.cpp"

        #State Headers
        "Include/States/stateGameMode1.h"      "Source/States/stateGameMode1.cpp"
        "Include/States/stateGameMode2.h"      "Source/States/stateGameMode2.cpp"
        "Include/States/stateGameOver.h"       "Source/States/stateGameOver.cpp"
        "Include/States/stateHighscore.h"      "Source/States/stateHighscore.cpp"
        "Include/States/stateKeybindings.h"    "Source/States/stateKeybindings.cpp"
        "Include/States/statePlayConfig.h"     "Source/States/statePlayConfig.cpp"
        "Include/States/stateMainMenu.h"       "Source/States/stateMainMenu.cpp"
        "Include/States/stateSettings.h"       "Source/States/stateSettings.cpp")

add_executable(Vietnamese_Space_Program ${SOURCE_FILES})

# Link with SFML dependencies
target_link_libraries(Vietnamese_Space_Program sfml-graphics sfml-window sfml-system)