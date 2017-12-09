//
// Created by ben-hodadov on 07/12/17.
//

#ifndef REVERSITEST_LOCALPLAYER_H
#define REVERSITEST_LOCALPLAYER_H


#include "Player.h"
#include "Client.h"
#include "HumanPlayer.h"

class LocalPlayer : public Player {
public:
    /**
     * Constructor - create a new Player class.
     * @param _s char
     */
    LocalPlayer(char _s, Client* client);

    /**
     * The method plays one turn for the computer.
     * @param gl GameLogic&
     * @param b Board*
     */
    Position playOneTurn(GameLogic &gl, Board *b);

private:
    /**
     * The method chooses the computer's best move
     * @param gl GameLogic&
     * @param om vector<Position>
     * @param b const Board&
     * @return
     */
    Position chooseMove(GameLogic &gl, vector<Position> om,  const Board &b);
    HumanPlayer player;
    Client* client;
};


#endif //REVERSITEST_LOCALPLAYER_H
