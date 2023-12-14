cmake_minimum_required(VERSION 3.26)
project(X_O_5x5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(X_O_5x5
        BoardGame_Classes.hpp
        GameManager.cpp
        Player.cpp
        RandomPlayer.cpp
        X_O_App.cpp
        X_O_Board.cpp)
