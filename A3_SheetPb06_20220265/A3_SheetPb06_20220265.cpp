//File Name: A3_SheetPb06_20220265
//Purpose: A program that implements the Game of Life cellular automaton proposed by John Horton Conway.
//Author: Maria Alfons
//ID: 20220265
//Section: S5
//Date: Dec 7, 2023

#include <bits/stdc++.h>
using namespace std;

class Universe{
    vector<vector<bool>>board;

public:
    Universe(): board(30, vector<bool>(30, false)){}

    void initialize(vector<vector<bool>> & input){
        int row_input = input.size();
        int column_input = input[0].size();
        for(int i=0; i<min(30, row_input) ; i++){
            for(int j=0 ; j<min(30, column_input) ; j++){
                board[i][j] = input[i][j];
            }
        }
    }

    void reset(){
        for(int i=0; i<30 ; i++){
            for(int j=0 ; j<30 ; j++){
                board[i][j] = false;
            }
        }
    }

    int count_neighbors(int i, int j){
        int cnt = 0;
        if((i-1) < 30 && (j-1) < 30 && (i-1)>-1 && (j-1)>-1 && board[i-1][j-1] == 1){
            cnt++;
        }
        if(i < 30 && (j-1) < 30 && (j-1)>-1 && board[i][j-1] == 1){
            cnt++;
        }
        if((i+1) < 30 && (j-1) < 30 && (j-1)>-1 && board[i+1][j-1] == 1){
            cnt++;
        }
        if((i-1) < 30 && i < 30 && (i-1)>-1&& board[i-1][j] == 1){
            cnt++;
        }
        if((i+1) < 30 && j < 30 && board[i+1][j] == 1){
            cnt++;
        }
        if((i-1) < 30 && (j+1) < 30  && (i-1)>-1 && board[i-1][j+1] == 1 ){
            cnt++;
        }
        if(i < 30 && (j+1) < 30 && board[i][j+1] == 1){
            cnt++;
        }
        if((i+1) < 30 && (j+1) < 30 && board[i+1][j+1] == 1){
            cnt++;
        }
        return cnt;
    }

    void next_generation(){
        vector<vector<bool>>s (30, vector<bool>(30));
        s = board;
        for(int i=0 ; i<30 ; i++){
            for(int j=0 ; j<30 ; j++){
                if(board[i][j]){
                    if(count_neighbors(i, j) < 2 || count_neighbors(i, j) > 3){
                        s[i][j] = false;
                    }else{
                        s[i][j] = true;
                    }
                }else{
                    if(count_neighbors(i, j) == 3){
                        s[i][j] = true;
                    }
                }
            }
        }
        board = s;
        Display();
    }

    void Display(){
        system("CLS");
        cout<<'\n';

        for(int i=0 ; i<30 ; i++){
            for(int j=0 ; j<30 ; j++){
                cout<<board[i][j]<<' ';
            }
            cout<<'\n';
        }
    }

    void run(int times){
        while(times--){
            next_generation();
        }
        Display();
    }
};
int main() {
    vector<vector<bool>>s = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    Universe game;
    game.initialize(s);
    game.next_generation();
    game.reset();


    int row, col;
    cout<<"number of rows: "; cin>>row;
    cout<<"number of columns: "; cin>>col;
    vector<vector<bool>>s1(row, vector<bool>(col, false));
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            bool c; cin>>c;
            s1[i][j] = c;
        }
    }
    game.initialize(s1);
    game.run(5);
    game.Display();

    return 0;
}
