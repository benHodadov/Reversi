#define LENGTH 8
/*
 * Board.h
 *
 *  Created on: Nov 1, 2017
 *      Author: barak hodadov
 */

#ifndef BOARD_H_
#define BOARD_H_

class Board {
public:
	/**
	 * Constructor - create a new board class.
	 */
	Board();
	/**
	 * Copy constructor - create a new board class as same as a given one.
	 */
	Board copy() const;
	/**
	 * print method - print the current state of the board.
	 */
	void print() const;
	/**
	 * put method - put the disk 'c' in position [row][col].
	 * @param row int
	 * @param col int
	 * @param s char
	 */
	void put(int row, int col, char s);
	/**
	 * getSide method - returns what value is stored in position [row][col].
	 * @param row int
	 * @param col int
	 * @return char.
	 */
	char getSide(int row, int col) const;

	/**
	 * The method returns the board's size
	 * @return size
	 */
	int getsize();

private:
	char board[LENGTH][LENGTH];
};

#endif /* BOARD_H_ */
