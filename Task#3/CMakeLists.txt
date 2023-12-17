cmake_minimum_required(VERSION 3.26)
project(total)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(total
        A5x5_Board.cpp
        BoardGame_Classes.h
        Four-in-a-row_Board.cpp
        Pyramic.cpp
        X_O_App.cpp
        A5x5_Board.cpp
        GameManager.cpp
        Player.cpp
        RandomPlayer.cpp
        X_O_App.cpp)
