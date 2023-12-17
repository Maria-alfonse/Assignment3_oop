//
// Created by Ahmed on 12/4/2023.
//
#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include "BoardGame_Classes.h"


// Set the board
Pyramic::Pyramic() {
    n_cols = 5;
    n_rows = 3;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++){
            if(i == 0 && j == 0 || i == 0 && j == 1 || i == 0 && j == 3 || i == 0 && j == 4 || i == 1 && j == 0 || i == 1 && j == 4)continue;
            board[i][j] = 0;
        }
    }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool Pyramic::update_board (int x, int y, char mark){
    // Only update if move is valid
    if (x < 0 || x > 2 || y < 0 || y > 4){
        return false;
    }
    else if (x == 0 && y == 0 || x == 0 && y == 1 || x == 0 && y == 3 || x == 0 && y == 4 || x == 1 && y == 0 || x == 1 && y == 4 || board[x][y] != 0) {
        return false;
    }
    else
        board[x][y] = toupper(mark);
    n_moves++;
    return true;
}

// Display the board and the pieces on it
void Pyramic::display_board() {
    cout << "\nPlease enter your move x and y separated by spaces CORRECTLY: ";
    for (int i: {0,1,2}) {
        cout<<"\n"<<setw(20-i*10)<<"| ";
        for (int j: {0,1,2,3,4}) {
            if(i == 0 && j == 0 || i == 0 && j == 1 || i == 0 && j == 3 || i == 0 && j == 4 || i == 1 && j == 0 || i == 1 && j == 4)continue;
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board[i][j] << " |";
        }
        cout << "\n--------------------------------------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool Pyramic::is_winner() {
    char row_win[4], col_win[1], diag_win[2];

    for (int i = 1; i <=2 ; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == 1 && j == 4)
                break;
            if (i == 1) {
                if (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] != 0)return true;
            }
            else {
                if (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] != 0)return true;
            }
        }
    }
    col_win[0] = board[0][2] & board[1][2] & board[2][2];


    diag_win[0] = board[0][2] & board[1][1] & board[2][0];
    diag_win[1] = board[0][2] & board[1][3] & board[2][4];

    /*  for (int i:{1,2}) {
          for(int j : {0,1,2,3})
          if ( (row_win[j] && (row_win[j] == board[i][1])) ||
               (col_win[j] && (col_win[j] == board[0][i])) )
          {return true;}
      }*/
    if(row_win[0] && (row_win[0] == board[1][1]) || row_win[1] && (row_win[1] == board[2][2]) || row_win[2] && (row_win[2] == board[2][2]) || row_win[3] && (row_win[3] == board[2][2]  )){
        return true;
    }
    if(col_win[0] && (col_win[0] == board[1][2])){
        return true;
    }
    if ((diag_win[0] && diag_win[0] == board[1][1]) ||
        (diag_win[1] && diag_win[1] == board[1][1]))
    {return true;}
    return false;
}

// Return true if 9 moves are done and no winner
bool Pyramic::is_draw() {
    return (n_moves == 9 && !is_winner());
}

bool Pyramic::game_is_over () {
    return n_moves >= 9;
}
