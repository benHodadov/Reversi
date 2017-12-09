/*
 * HumanPlayer.h
 *
 *  Created on: Nov 2, 2017
 *      Author: barak and ben
 */

#ifndef HUMANPLAYER_H_
#define HUMANPLAYER_H_

#include "Player.h"
#include "GameLogic.h"

class HumanPlayer : public Player {
public:
	/**
	 * Constructor - create a new Player class.
	 * @param _s  char
	 */
	HumanPlayer(char _s);

	/**
	 * The method playes for the player.
	 * @param gl GameLogic&
	 * @param b Board*
	 */
	Position playOneTurn(GameLogic &gl, Board *b);

	/**
	 * the method chooses move for the player
	 * @param gl GameLogic&
	 * @param om vector<Position>
	 * @param b const Board&
	 * @return position
	 */
	Position chooseMove(GameLogic &gl, vector<Position> om, const Board &b);
};

#endif /* HUMANPLAYER_H_ */
