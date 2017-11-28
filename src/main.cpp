/*
 * main.cpp
 *
 *  Created on: Nov 1, 2017
 *      Author: barak
 */

#include "Game.h"

int main(int argc, char* argv[]) {
    cout << "Hello,\nselect 1 for human vs. human\nselect 2 for human vs. computer\n";
    int mode;
    cin >> mode;
    if (mode == 1) { // if he selected human vs human
        HumanPlayer human1('X');
        HumanPlayer human2('O'); // creates humans
        Player *p1 = &human1;
        Player *p2 = &human2;
        Game g(p1, p2); // creates game
        g.run(); // run game
        return 0; // return
    } else if (mode == 2) { // if he selected human vs computer
        HumanPlayer human('X');
        AIPlayer computer('O'); // creates players
        Player *p1 = &human;
        Player *p2 = &computer;
        Game g(p1, p2); // creates game
        g.run(); // run game
        return 0; // return
    } else { // none
        cout << "Bye Bye"; // say goodbye
    }
    return 0;
}
