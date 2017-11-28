/*
 * Position.h
 *
 *  Created on: Nov 4, 2017
 *      Author: barak
 */

#ifndef POSITION_H_
#define POSITION_H_

class Position {
public:
	/**
	 * Constructor method - create a new "position" with row and column.
	 * This class is for returning list of optional places calculated in the GameLogic.
	 */
	Position(int _row, int _col);
	/**
	 * getCol method - return the column of the position.
	 */
	int getCol() const;
	/**
	 * getRow method - return the row of the position.
	 */
	int getRow() const;
	/**
	 * print method - print the position.
	 */
	void print() const;

	/**
	 * operator << overloading.
	 */
	friend ostream &operator <<(ostream &out, const Position &p);

	/**
	 * operator == overloading.
	 */
	bool operator ==(const Position &other) const;
private:
	int row;
	int col;
};

#endif /* POSITION_H_ */
