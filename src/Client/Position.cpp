/*
 * Position.cpp
 *
 *  Created on: Nov 4, 2017
 *      Author: barak
 */

using namespace std;
#include <iostream>
#include "Position.h"

int row;
int col;

Position::Position(int _row, int _col) {
	// TODO Auto-generated constructor stub
	row = _row;
	col = _col;
}

int Position::getCol() const {
	return col;
}

int Position::getRow() const {
	return row;
}

void Position::print() const {
	cout << "(" << row << "," << col << ")";
}

ostream &operator <<(ostream &out, const Position &p) {
	out << "(" << p.getRow() << "," << p.getCol() << ")";
	return out;
}

bool Position::operator ==(const Position &other) const {
	return (this->getRow() == other.getRow()) && (this->getCol() == other.getCol());
}

