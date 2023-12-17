// Class definition for X_O_Board class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include <map>
#include "BoardGame_Classes.h"
using namespace std;

// Set the board
A5x5_Board::A5x5_Board () {
   n_rows = n_cols = 5;
   board = new char*[n_rows];
   for (int i = 0; i < n_rows; i++) {
      board [i] = new char[n_cols];
      for (int j = 0; j < n_cols; j++)
         board[i][j] = 0;
   }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool A5x5_Board::update_board (int x, int y, char mark){
   // Only update if move is valid
   if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0)) {
      board[x][y] = toupper(mark);
      n_moves++;
      return true;
   }
   else
      return false;
}

// Display the board and the pieces on it
void A5x5_Board::display_board() {
    cout << "\nPlease enter your move x and y (0 to 4) separated by spaces: ";
    for (int i: {0,1,2,3,4}) {
      cout << "\n| ";
      for (int j: {0,1,2,3,4}) {
         cout << "(" << i << "," << j << ")";
         cout << setw(2) << board [i][j] << " |";
      }
      cout << "\n-----------------------------------------------";
   }
   cout << endl;
}

// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool A5x5_Board::is_winner() {
    map<char, int>who_is_winner;
    for (int i:{0,1,2,3,4}) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            who_is_winner[board[i][0]]++;
        }
        if(board[i][1] == board[i][2] && board[i][2] == board[i][3]){
            who_is_winner[board[i][1]]++;
        }
        if(board[i][2] == board[i][3] && board[i][3] == board[i][4]){
            who_is_winner[board[i][2]]++;
        }
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]){
            who_is_winner[board[0][i]]++;
        }
        if(board[1][i] == board[2][i] && board[2][i] == board[3][i]){
            who_is_winner[board[1][i]]++;
        }
        if(board[2][i] == board[3][i] && board[3][i] == board[4][i]){
            who_is_winner[board[2][i]]++;
        }
    }
    for(int i:{0,1,2}){
        for(int j:{0,1,2}){
            if(board[i][j] == board[i+1][j+1] && board[i+1][j+1] == board[i+2][j+2]){
                who_is_winner[board[i][j]]++;
            }
        }
    }
    for(int i:{0,1,2}){
        for(int j:{2,3,4}){
            if(board[i][j] == board[i+1][j-1] && board[i+1][j-1] == board[i+2][j-2]){
                who_is_winner[board[i][j]]++;
            }
        }
    }
    cout<<"Player X: "<<who_is_winner['X']<<'\n';
    cout<<"Player O: "<<who_is_winner['O']<<'\n';

    if(who_is_winner['X']>who_is_winner['O']){
        cout<<"X is the winner!\n";
    }else if(who_is_winner['X'] == who_is_winner['O']){
        cout<<"Draw!\n";
    }else{
        cout<<"O is the winner!\n";
    }
    return 0;
}
bool A5x5_Board::is_draw() {
    return (0);
}
bool A5x5_Board::game_is_over () {
    return n_moves >= 24;
}
