//
// Created by Ahmed on 12/4/2023.
//
#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include "BoardGame_Classes.h"


GameManager::GameManager(Board* bPtr, Player* playerPtr[2] , int a) {
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
    game = a;
}

void GameManager::run() {
    int x, y;

    boardPtr->display_board();
    if(game == 1 || game == 2) {
        while (!boardPtr->game_is_over()) {
            for (int i: {0, 1}) {
                cout << players[i]->to_string();
                if(game == 1){
                    cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
                }
                else{
                    cout << "\nPlease enter your move x (0 to 5) and y (0 to 6) separated by spaces: ";
                }
                players[i]->get_move(x, y);
                while (!boardPtr->update_board(x, y, players[i]->get_symbol())) {
                    if(game == 1){
                        cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
                    }
                    else{
                        cout << "\nPlease enter your move x (0 to 5) and y (0 to 6) separated by spaces: ";
                    }
                    players[i]->get_move(x, y);
                }
                boardPtr->display_board();
                if (boardPtr->is_winner()) {
                    cout << players[i]->to_string() << " wins\n";
                    return;
                }
                if (boardPtr->is_draw()) {
                    cout << "Draw!\n";
                    return;
                }
            }
        }
    }else{
        while (!boardPtr->game_is_over()) {
            for (int i: {0, 1}) {
                cout<<players[i]->to_string();
                cout << "\nPlease enter your move x and y (0 to 4) separated by spaces: ";
                players[i]->get_move(x, y);
                while (!boardPtr->update_board(x, y, players[i]->get_symbol())) {
                    cout << "\nPlease enter your move x and y (0 to 4) separated by spaces: ";
                    players[i]->get_move(x, y);
                }
                boardPtr->display_board();
            }
        }
        boardPtr->is_winner();
    }
}