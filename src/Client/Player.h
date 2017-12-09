//
// Created by ben-hodadov on 25/11/17.
//

#ifndef EX3_PLAYER_H
#define EX3_PLAYER_H


using namespace std;
#include <ostream>
#include <vector>
#include "Position.h"
#include "Board.h"
#include "GameLogic.h"

class GameLogic;
class Player {
public:
    /**
     * Constructor - create a new Player class.
     * @param _s char
     */
    Player(char _s);

    /**
     * optionalMoves method - returns all possible moves for player p.
     * @param board Board&
     * @param gl GameLogic&
     * @return moves
     */
    vector<Position> optionalMoves(const Board &board, const GameLogic &gl) const;

    /**
     * The method plays one turn.
     * Return the chosen position.
     * @param gl GameLogic
     * @param b Board
     */
    virtual Position playOneTurn(GameLogic &gl, Board *b) = 0;

    /**
     * chooseMove method - return the selected move for the player.
     * @return Position.
     */
    virtual Position chooseMove(GameLogic &gl, vector<Position> om, const Board &b) = 0;

    /**
     * getSign method - returns the player's sign.
     * @return sign
     */
    char getSign() const;

    /**
     * end game method - end the game.
     * only local and remote player have an implementation for this functions.
     */
    virtual void endGame();

private:
    char s;
};

#endif //EX3_PLAYER_H