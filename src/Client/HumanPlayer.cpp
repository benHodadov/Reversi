/*
 * Player.cpp
 *
 *  Created on: Nov 2, 2017
 *      Author: barak and ben
 */

using namespace std;
#include <iostream>
#include "HumanPlayer.h"


HumanPlayer::HumanPlayer(char _s):Player(_s) {
}

Position HumanPlayer::chooseMove(GameLogic &gl, vector<Position> om, const Board &b) {
    vector<Position>::iterator it;
    int r,c;
    cout << "Please enter your move row,col: " ;
    cin >> r >> c; // row and col input
    Position selectedPosition(r,c);

    bool isValid = false;
    for (it = om.begin(); it != om.end(); ++it) {
        if (selectedPosition == *it) {
            isValid = true;
            return selectedPosition;
        }
    }

    while (!isValid) { // if it isn't valid, get row&col again until it's ok
        cout << endl << "The selected position is not valid." << endl << "Please enter your move row,col: ";
        cin >> r >> c;
        Position selectedPosition(r,c);
        for (it = om.begin(); it != om.end(); ++it) {
            if (selectedPosition == *it) {
                isValid = true;
                return selectedPosition;
            }
        }
    }
}

Position HumanPlayer::playOneTurn(GameLogic &gl, Board *b) {
    cout << "Current board:" << endl;
    b->print();// prints the board

    cout << this->getSign() << ": It's your move." << endl << "Your possible moves: ";
    vector<Position> v = this->optionalMoves(*b, gl);

    // if any of the moves are legal return 0.
    if (v.size() == 0) {
        cout << "No possible moves. Play passes back to the other player. Press any key to continue." << endl;
        char dummy; // a dummy
        cin >> dummy;
        cout << endl;
        return Position(0,0);
    }

    //There is at least one possible move. print the moves.
    vector<Position>::iterator it;
    for (it = v.begin(); it != v.end(); ++it) {
        cout << *it;
        if ((it + 1) != v.end()) {
            cout << ",";
        }
    }
    cout << endl;
    Position selected = this->chooseMove(gl, v, *b); // use choose move

    //put and turn over.
    gl.putAndTurnOver(b, selected.getRow(), selected.getCol(), *this); // use play and turn over

    return selected;
}
