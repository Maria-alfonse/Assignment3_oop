cmake_minimum_required(VERSION 3.26)
project(untitled9)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled9 main.cpp
        BoardGame_Classes.h
        GameManager.cpp
        RandomPlayer.cpp
        Player.cpp
        Four-in-a-row_Board.cpp)
