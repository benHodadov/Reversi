/*
 * Board.cpp
 *
 *  Created on: Nov 1, 2017
 *      Author: barak and ben
 */

using namespace std;
#include <iostream>
#include "Board.h"

char board[LENGTH][LENGTH];

Board::Board() {
	// fill the board with spaces
	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < LENGTH; j++) {
			 board[i][j] = ' ';
		}
	}

    // puts O, X in the middle
	put(LENGTH/2, LENGTH/2, 'O');
	put(LENGTH/2, LENGTH/2 + 1, 'X');
	put(LENGTH/2 + 1, LENGTH/2, 'X');
	put(LENGTH/2 + 1, LENGTH/2 + 1, 'O');
}
Board Board::copy() const {
	Board copyb;
    for (int i = 1; i <= LENGTH; i++) {
        for (int j = 1; j <= LENGTH; j++) {
             copyb.put(i, j, this->getSide(i, j));
        }
    }
    return copyb;
}

void Board::print() const {
    // we will row by row
	cout << endl;
	cout << " | ";
	for (int i = 1; i <= LENGTH; i++) {
		cout << i << " | " ;
	}
	cout << endl;
	cout << "----------------------------------" << endl;
	for (int  i = 1; i <= LENGTH; i++) {
		cout << i << "| ";
		for (int j = 1; j <= LENGTH; j++) {
			cout << this->getSide(i, j) << " | ";
		}
		cout << endl << "----------------------------------" << endl;
	}
}

void Board::put(int row, int col, char s) {
	board[row - 1][col - 1] = s;
}

char Board::getSide(int row, int col) const {
	return board[row - 1][col - 1];
}

int Board::getsize() {
    return LENGTH;
}
