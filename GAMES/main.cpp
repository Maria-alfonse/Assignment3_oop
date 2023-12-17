#include <iostream>
#include "BoardGame_Classes.h"

using namespace std;

int main() {
    int Game_Number;

    cout << "=============================================\n";
    cout << "            Welcome to Board Games\n";
    cout << "=============================================\n\n";
    cout << "Please choose a game to play\n";
    cout << "1. Pyramic Tic-Tac-Toe\n";
    cout << "2. Four in a Row\n";
    cout << "3. 5x5 Tic Tac Toe\n";
    cout << "4. Exit\n";
    cout << "Enter a number to start a game: ";

    cin >> Game_Number;
    Player *players[2];
    int choice; // choose to play with who
    switch (Game_Number) {
        case 1:
            players[0] = new Player(1, 'x');

            cout << "Welcome to Pyramic Tic-Tac-Toe Game. :)\n";
            cout << "Press 1 if you want to play with the computer: ";
            cin >> choice;
            if (choice != 1)
                players[1] = new Player(2, 'o');
            else
                players[1] = new RandomPlayer('o', 3, 5);

            {
                GameManager PyramicGame(new Pyramic(), players);
                PyramicGame.run();
            }

            break;

        case 2:
            players[0] = new Player(1, 'x');

            cout << "Welcome to Four in a Row Game. :)\n";
            cout << "Press 1 if you want to play with the computer: ";
            cin >> choice;
            if (choice != 1)
                players[1] = new Player(2, 'o');
            else
                players[1] = new RandomPlayer('o', 6, 7);

            {
                GameManager Four_in_a_row(new Four_in_Row_Board(), players);
                Four_in_a_row.run();
            }

            break;

        case 3:
            players[0] = new Player(1, 'x');

            cout << "Welcome to 5x5 Tic Tac Toe Game. :)\n";
            cout << "Press 1 if you want to play with the computer: ";
            cin >> choice;
            if (choice != 1)
                players[1] = new Player(2, 'o');
            else
                players[1] = new RandomPlayer('o', 6, 7);

            {
                GameManager A5x5Game(new A5x5_Board(), players);
                A5x5Game.run();
            }

            break;

        case 4:
            cout << "Thank you for using our Games,Goodbye!\n";
            break;

        default:
            cout << "Invalid choice, Please enter a valid option.\n";
    }

    // Deallocate memory
    delete players[0];
    delete players[1];

    return 0;
}
