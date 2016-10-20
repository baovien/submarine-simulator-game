cmake_minimum_required(VERSION 3.6)
project(aginc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    AsianSpaceSimulator/entity.h
    AsianSpaceSimulator/gamemode1.cpp
    AsianSpaceSimulator/gamemode1.h
    AsianSpaceSimulator/main.cpp
    AsianSpaceSimulator/menu.cpp
    AsianSpaceSimulator/menu.h
    AsianSpaceSimulator/player.cpp
    AsianSpaceSimulator/player.h
    AsianSpaceSimulator/playerobject.h
    AsianSpaceSimulator/state.h)

add_executable(aginc ${SOURCE_FILES})