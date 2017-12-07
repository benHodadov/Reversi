//
// Created by ben-hodadov on 07/12/17.
//

#ifndef REVERSITEST_REMOTEPLAYER_H
#define REVERSITEST_REMOTEPLAYER_H


#include "Player.h"
#include "Client.h"

class RemotePlayer : public Player{
public:

    /**
     * Constructor - create a new Player class.
     * @param _s char
     */
    RemotePlayer(char _s);

    /**
     * The method plays one turn for the computer.
     * @param gl GameLogic&
     * @param b Board*
     */
    void playOneTurn(GameLogic &gl, Board *b);

private:
    /**
     * The method chooses the computer's best move
     * @param gl GameLogic&
     * @param om vector<Position>
     * @param b const Board&
     * @return
     */
    Position chooseMove(GameLogic &gl, vector<Position> om,  const Board &b);
    Client client;
};


#endif //REVERSITEST_REMOTEPLAYER_H
