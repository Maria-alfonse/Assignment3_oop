cmake_minimum_required(VERSION 3.24)
project(Pyramic_Tic_Tac_Toe_V3_)

set(CMAKE_CXX_STANDARD 23)

add_executable(Pyramic_Tic_Tac_Toe_V3_ main.cpp BoardGame_Classes.cpp BoardGame_Classes.h GameManager.cpp Player.cpp RandomPlayer.cpp X_O_Board.cpp)
