/*
 * GameLogic.h
 *
 *  Created on: Nov 4, 2017
 *      Author: barak
 */

#ifndef GAMELOGIC_H_
#define GAMELOGIC_H_

using namespace std;

#include <vector>
#include <iostream>
#include "Position.h"
#include "Board.h"
#include "Player.h"

class Player;
class GameLogic {
public:
	/**
	 * Constructor method - creates a new GameLogic.
	 */
	GameLogic();


	/**
	 * isValidMove method - returns true if player p can place a disc in place (row,col).
	 */
	bool isValidMove(const Board &b, int row, int col, const Player &p) const;

	/**
	 * checkLeft method - check if player p placing a disc in (row,col) cause a change from left.
	 */
	bool checkLeft(const Board &b, int row, int col, const Player &p) const;
	/**
	 * checkRight method - check if player p placing a disc in (row,col) cause a change from right.
	 */
	bool checkRight(const Board &b, int row, int col, const Player &p) const;
	/**
	 * checkUp method - check if player p placing a disc in (row,col) cause a change from up.
	 */
	bool checkUp(const Board &b, int row, int col, const Player &p) const;
	/**
	 * checkDown method - check if player p placing a disc in (row,col) cause a change from down.
	 */
	bool checkDown(const Board &b, int row, int col, const Player &p) const;
	/**
	 * checkUpLeft method - check if player p placing a disc in (row,col) cause a change from up left.
	 */
	bool checkUpLeft(const Board &b, int row, int col, const Player &p) const;
	/**
	 * checkUpRight method - check if player p placing a disc in (row,col) cause a change from up right.
	 */
	bool checkUpRight(const Board &b, int row, int col, const Player &p) const;
	/**
	 * checkDownLeft method - check if player p placing a disc in (row,col) cause a change down left.
	 */
	bool checkDownLeft(const Board &b, int row, int col, const Player &p) const;
	/**
	 * checkDownRight method - check if player p placing a disc in (row,col) cause a change from down right.
	 */
	bool checkDownRight(const Board &b, int row, int col, const Player &p) const;


    /**
	 * putAndTurnOver method - player p puts a disc in (row,col) and flips the discs required.
	 */
    void putAndTurnOver(Board* b, int r, int c, Player &p);

    /**
	 * All these are sub-methods of putAndTurnOver.
	 * Each has a direction a checks if any discs have to be flip over.
	 */

    void turnDiscsFromLeft(Board* b, int r, int c, Player &p);
    void turnDiscsFromRight(Board* b, int r, int c, Player &p);
    void turnDiscsFromUp(Board* b, int r, int c, Player &p);
    void turnDiscsFromDown(Board* b, int r, int c, Player &p);
    void turnDiscsFromUpLeft(Board* b, int r, int c, Player &p);
    void turnDiscsFromUpRight(Board* b, int r, int c, Player &p);
    void turnDiscsFromDownLeft(Board* b, int r, int c, Player &p);
    void turnDiscsFromDownRight(Board* b, int r, int c, Player &p);


	/**
	 * calculateScore method - calculate the score for opponent move.
	 */
	int calculateScore(const Board &b) const;
    /**
     * endGame method - check if the game is ended.
     */
    bool endGame(const Board &b, const Player &p1, const Player &p2) const;
    /**
     * findWinner method - finds he winner at the end of the game and print a message.
     */
    void findWinner(const Board &b, const Player &p1, const Player &p2) const;
};

#endif /* GAMELOGIC_H_ */
