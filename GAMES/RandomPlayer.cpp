
#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include"BoardGame_Classes.h"
using namespace std;

// Set player symbol and name as Random Computer Player
RandomPlayer::RandomPlayer (char symbol, int dimension1,int dimension2):Player(symbol)
{
    this->dimension1 = dimension1;
    this->dimension2= dimension2;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}

// Generate a random move
void RandomPlayer::get_move (int& x, int& y) {
    x = (int) (rand()/(RAND_MAX + 1.0) * dimension1);
    y = (int) (rand()/(RAND_MAX + 1.0) * dimension2);
}
