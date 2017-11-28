//
// Created by ben-hodadov on 25/11/17.
//

/*
 * Player.cpp
 *
 *  Created on: Nov 2, 2017
 *      Author: barak and ben
 */

using namespace std;
#include <iostream>
#include "Player.h"

Player::Player(char _s) {
    s = _s;
}

char Player::getSign() const {
    return s;
}

vector<Position> Player::optionalMoves(const Board &b, const GameLogic &gl) const {
    vector<Position> om;
    for (int i = 1; i <= LENGTH; i++) {
        for(int j =1; j <= LENGTH; j++) { // goes through akk cells
            if (b.getSide(i, j) != ' ') { // if the spot is taken
                continue; // go to next spot
            }
            if (gl.isValidMove(b, i, j, *this)) { // if the spot is valid
                Position p(i, j);
                om.push_back(p); // push the cell to the vector
            }
        }
    }
    return om;
}
