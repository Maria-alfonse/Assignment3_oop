// Class definition for XO_App class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1

#include <iostream>
#include"BoardGame_Classes.h"
using namespace std;

int main() {
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << "Welcome to FCAI X-O Game. :)\n";

    int choice1;
    cout<<"Menu";
    cin>>choice1;
    if(choice1 == 1 ){
        cout << "Press 1 if you want to play with computer else press 2: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player (2, 'o');
        else
            //Player pointer points to child
            players[1] = new RandomPlayer ('o', 3,3);

        GameManager x_o_game (new Pyramic(), players, choice1);
        x_o_game.run();
        system ("pause");
    }else if(choice1 == 2){
        cout << "Press 1 if you want to play with computer else press 2: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player (2, 'o');
        else
            //Player pointer points to child
            players[1] = new RandomPlayer ('o', 6,7);

        GameManager x_o_game (new Four_in_Row_Board(), players, choice1);
        x_o_game.run();
        system ("pause");
    }else{
        cout << "Press 1 if you want to play with computer else press 2: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player (2, 'o');
        else
            //Player pointer points to child
            players[1] = new RandomPlayer ('o', 5,5);

        GameManager x_o_game (new A5x5_Board(), players, choice1);
        x_o_game.run();
        system ("pause");
    }
}
