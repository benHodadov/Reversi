//
// Created by ben and barak hodadov on 25/11/17.
//

#ifndef EX3_AIPLAYER_H
#define EX3_AIPLAYER_H

#include "Player.h"
#include "Position.h"

class AIPlayer : public Player {
public:

    /**
     * Constructor - create a new Player class.
     * @param _s char
     */
    AIPlayer(char _s);

    /**
     * The method plays one turn for the computer.
     * @param gl GameLogic&
     * @param b Board*
     * @return played
     */
    Position playOneTurn(GameLogic &gl, Board *b);

    /**
     * The method chooses the computer's best move
     * @param gl GameLogic&
     * @param om vector<Position>
     * @param b const Board&
     * @return played
     */
    Position chooseMove(GameLogic &gl, vector<Position> om,  const Board &b);
};


#endif //EX3_AIPLAYER_H
