/*
 * Game.h
 *
 *  Created on: Nov 5, 2017
 *      Author: barak and ben
 */
#ifndef GAME_H_
#define GAME_H_

using namespace std;
#include <vector>
#include <iostream>
#include "GameLogic.h"
#include "Board.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include "Player.h"
#include "Position.h"

class Game {
public:
	/**
	 * Constructor method - create a new game class.
	 * @param _p1 Player*
	 * @param _p2 Player*
	 */
	Game(Player* _p1, Player* _p2);
	/**
	 * run method - run the game.
	 */
	void run();
private:
	Player *p1;
	Player *p2;
	Board b;
	GameLogic gl;

	/**
	 * otherPlayer method - returns a pointer to the other player.
	 * @param p Player*
	 * @return otherPlayer
	 */
	Player* otherPlayer(Player* p);

	/**
	 * isRemoted - returns true if the game is in remote mode, false otherwise.
	 * @return
	 */
	bool isRemoted();
};

#endif /* GAME_H_ */
