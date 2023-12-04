//
// Created by Ahmed on 12/4/2023.
//
#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include "BoardGame_Classes.h"


RandomPlayer::RandomPlayer (char symbol, int dimension):Player(symbol)
{
    this->dimension = dimension;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}

// Generate a random move
void RandomPlayer::get_move (int& x, int& y) {
    x = (int) (rand()/(RAND_MAX + 1.0) * dimension);
    y = (int) (rand()/(RAND_MAX + 1.0) * (dimension+2));
}