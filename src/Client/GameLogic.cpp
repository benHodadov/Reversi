/*
 * GameLogic.cpp
 *
 *  Created on: Nov 4, 2017
 *      Author: barak and ben
 */

#include "GameLogic.h"

GameLogic::GameLogic() {
}
// the following methods checking if the cell is acceptable
bool GameLogic::isValidMove(const Board& b, int row, int col, const Player& p) const {
	return this->checkLeft(b, row, col, p) || this->checkRight(b, row, col, p) ||
			this->checkUp(b, row, col, p) || this->checkDown(b, row, col, p) ||
			this->checkUpLeft(b, row, col, p) || this->checkUpRight(b, row, col, p) ||
			this->checkDownLeft(b, row, col, p) || this->checkDownRight(b, row, col, p);
}

bool GameLogic::checkLeft(const Board& b, int row, int col, const Player& p) const {
	if (col != 1) {
		// if (col == 1) then return false.
		// if (b.getSide(row, col - 1) == b.getSide(row, col)) return false.
		if (b.getSide(row, col -1) != ' ') {

			if (b.getSide(row, col - 1) != p.getSign()) {
				for (int i = col - 2; i > 0; i--) {
					if (b.getSide(row, i) != b.getSide(row, i + 1)) {
						if (b.getSide(row, i) != ' ') {
							//cout << "left" << endl;
							return true;
						}
						//else - exit for loop and return false.
						break;
					}
				}
			}
		}
	}
	return false;
}

bool GameLogic::checkRight(const Board& b, int row, int col, const Player& p) const {
	if (col != LENGTH) {
		// if (col == LENGTH) then return false.
		// if (b.getSide(row, col + 1) == b.getSide(row, col)) return false.
		if (b.getSide(row, col + 1) != ' ') {
			if (b.getSide(row, col + 1) != p.getSign()) {
				for (int i = col + 2; i <= LENGTH; i++) {
					if (b.getSide(row, i) != b.getSide(row, i - 1)) {
						if (b.getSide(row, i) != ' ') {
							//cout << "right" << endl;
							return true;
						}
						//else - exit for loop and return false.
						break;
					}
				}
			}
		}
	}
	return false;
}

bool GameLogic::checkUp(const Board& b, int row, int col,const Player& p) const {
	if (row != 1) {
		// if (row == 1) then return false.
		// if (b.getSide(row - 1, col) == b.getSide(row, col)) return false.
		if (b.getSide(row - 1, col) != ' ') {
			if (b.getSide(row - 1, col) != p.getSign()) {
				for (int i = row - 2; i > 0; i--) {
					if (b.getSide(i, col) != b.getSide(i + 1, col)) {
						if (b.getSide(i, col) != ' ') {
							return true;
						}
						//else - exit for loop and return false.
						break;
					}
				}
			}
		}
	}
	return false;
}

bool GameLogic::checkDown(const Board& b, int row, int col, const Player& p) const {
	if (row != LENGTH) {
		// if (row == LENGTH) then return false.
		// if (b.getSide(row + 1, col) == b.getSide(row, col)) return false.
		if (b.getSide(row + 1, col) != ' ') {
			if (b.getSide(row + 1, col) != p.getSign()) {
				for (int i = row + 2; i <= LENGTH; i++) {
					if (b.getSide(i, col) != b.getSide(i - 1, col)) {
						if (b.getSide(i, col) != ' ') {
							//cout << "down" << endl;
							return true;
						}
						//else - exit for loop and return false.
						break;
					}
				}
			}
		}
	}
	return false;
}

bool GameLogic::checkUpLeft(const Board& b, int row, int col, const Player& p) const {
	if ((row != 1) && (col != 1)) {
		// if ((row == 1) && (col == 1)) then return false.
		// if (b.getSide(row, col - 1) == b.getSide(row, col)) return false.
		if (b.getSide(row - 1, col - 1) != ' ') {
			if (b.getSide(row - 1, col - 1) != p.getSign()) {
				for (int i = row -2, j = col - 2; i > 0 && j > 0; i--, j--) {
					if (b.getSide(i, j) != b.getSide(i + 1, j + 1)) {
						if (b.getSide(i, j) != ' ') {
							return true;
						}
						//else - exit for loop and return false.
						break;
					}
				}
			}
		}
	}
	return false;
}

bool GameLogic::checkUpRight(const Board& b, int row, int col, const Player& p) const {
	if ((row != 1) && (col != LENGTH)) {
		// if (row != 1) && (col != LENGTH) then return false.
		// if (b.getSide(row - 1, col + 1) == b.getSide(row, col)) return false.
		if (b.getSide(row - 1, col + 1) != ' ') {
			if (b.getSide(row - 1, col + 1) != p.getSign()) {
				for (int i = row - 2, j = col + 2; i > 0 && j <= LENGTH; i--, j++) {
					if (b.getSide(i, j) != b.getSide(i + 1, j -1)) {
						if (b.getSide(i, j) != ' ') {
							//cout << "up-right" << endl;
							return true;
						}
						//else - exit for loop and return false.
						break;
					}
				}
			}
		}
	}
	return false;
}

bool GameLogic::checkDownLeft(const Board& b, int row, int col, const Player& p) const {
	if ((row != LENGTH) && (col != 1)) {
		// if (row != LENGTH) && (col != 1) then return false.
		// if (b.getSide(row + 1, col - 1) == b.getSide(row, col)) return false.
		if (b.getSide(row + 1, col -1) != ' ') {
			if (b.getSide(row + 1, col - 1) != p.getSign()) {
				for (int i = row + 2, j = col - 2; i <= LENGTH && j > 0; i++, j--) {
					if (b.getSide(i, j) != b.getSide(i - 1, j + 1)) {
						if (b.getSide(i, j) != ' ') {
							//cout << "down-left" << endl;
							return true;
						}
						//else - exit for loop and return false.
						break;
					}
				}
			}
		}
	}
	return false;
}

bool GameLogic::checkDownRight(const Board& b, int row, int col, const Player& p) const {
	if ((row != LENGTH) && (col != LENGTH)) {
		// if ((row == LENGTH) && (col == LENGTH)) then return false.
		// if (b.getSide(row + 1, col + 1) == b.getSide(row, col)) return false.
		if (b.getSide(row + 1, col + 1) != ' ') {
			if (b.getSide(row + 1, col + 1) != p.getSign()) {
				for (int i = row + 2, j = col + 2 ; i <= LENGTH && j <= LENGTH; i++, j++) {
					if (b.getSide(i, j) != b.getSide(i - 1, j - 1)) {
						if (b.getSide(i, j) != ' ') {
							//cout << "down-right" << endl;
							return true;
						}
						//else - exit for loop and return false.
						break;
					}
				}
			}
		}
	}
	return false;
}



void GameLogic::putAndTurnOver(Board *b, int r, int c, Player &p) {
	b->put(r, c, p.getSign());

	this->turnDiscsFromLeft(b, r, c, p);
	this->turnDiscsFromRight(b, r, c, p);
	this->turnDiscsFromUp(b, r, c, p);
	this->turnDiscsFromDown(b, r, c, p);
	this->turnDiscsFromUpLeft(b, r, c, p);
	this->turnDiscsFromUpRight(b, r, c, p);
	this->turnDiscsFromDownLeft(b, r, c, p);
	this->turnDiscsFromDownRight(b, r, c, p);
}


void GameLogic::turnDiscsFromLeft(Board* b, int r, int c, Player& p) {
	if (this->checkLeft(*b, r, c, p)) {
		for (int i = c - 1; i > 0; i--) {
			if ((b->getSide(r, i) != ' ') &&(b->getSide(r, i) != b->getSide(r, c))) {
                b->put(r, i, p.getSign());
            } else {
				return;
			}
		}
	}
}

void GameLogic::turnDiscsFromRight(Board* b, int r, int c, Player& p) {
	if (this->checkRight(*b, r, c, p)) {
		for (int i = c + 1; i <= LENGTH; i++) {
			if ((b->getSide(r, i) != ' ') &&(b->getSide(r, i) != b->getSide(r, c))) {
					b->put(r, i, p.getSign());
			} else {
				return;
			}
		}
	}
}

void GameLogic::turnDiscsFromUp(Board* b, int r, int c, Player& p) {
	if (this->checkUp(*b, r, c, p)) {
		for (int i = r - 1; i > 0; i--) {
			if ((b->getSide(i, c) != ' ') && (b->getSide(i, c) != b->getSide(r, c))) {
					b->put(i, c, p.getSign());
			} else {
				return;
			}
		}
	}
}

void GameLogic::turnDiscsFromDown(Board* b, int r, int c, Player& p) {
	if (this->checkDown(*b, r, c, p)) {
		for (int i = r + 1; i <= LENGTH; i++) {
			if ((b->getSide(i, c) != ' ') && (b->getSide(i, c) != b->getSide(r, c))) {
					b->put(i, c, p.getSign());
			} else {
				return;
			}
		}
	}
}

void GameLogic::turnDiscsFromUpLeft(Board* b, int r, int c, Player& p) {
	if (this->checkUpLeft(*b, r, c, p)) {
		for (int i = r - 1, j = c - 1; i > 0 && j > 0; i--, j--) {
			if ((b->getSide(i, j) != ' ') && (b->getSide(i, j) != b->getSide(r, c))) {
					b->put(i, j, p.getSign());
			} else {
				return;
			}
		}
	}
}

void GameLogic::turnDiscsFromUpRight(Board* b, int r, int c, Player& p) {
	if (this->checkUpRight(*b, r, c, p)) {
		for (int i = r - 1, j = c + 1; i > 0 && j <= LENGTH; i--, j++) {
			if ((b->getSide(i, j) != ' ') && (b->getSide(i, j) != b->getSide(r, c))) {
					b->put(i, j, p.getSign());
			} else {
				return;
			}
		}
	}
}

void GameLogic::turnDiscsFromDownLeft(Board* b, int r, int c, Player& p) {
	if (this->checkDownLeft(*b, r, c, p)) {
		for (int i = r + 1, j = c - 1; i <= LENGTH && j > 0; i++, j--) {
			if ((b->getSide(i, j) != ' ') && (b->getSide(i, j) != b->getSide(r, c))) {
					b->put(i, j, p.getSign());
			} else {
				return;
			}
		}
	}
}

void GameLogic::turnDiscsFromDownRight(Board* b, int r, int c, Player& p) {
	if (this->checkDownRight(*b, r, c, p)) {
		for (int i = r + 1, j = c + 1; i <= LENGTH && j <= LENGTH; i++, j++) {
			if ((b->getSide(i, j) != ' ') && (b->getSide(i, j) != b->getSide(r, c))) {
					b->put(i, j, p.getSign());
			} else {
				return;
			}
		}
	}
}



int GameLogic::calculateScore(const Board &b) const {
	int aiScore = 0, humanScore = 0;
	for(int i = 1; i <= LENGTH; i ++) {
		for (int j = 1; j <= LENGTH; j++) {
			if (b.getSide(i, j) == 'O') {
				aiScore++;
			} else if (b.getSide(i, j) == 'X') {
				humanScore++;
			}
		}
	}
    return humanScore - aiScore;
}

bool GameLogic::endGame(const Board &b, const Player &p1, const Player &p2) const {
	return  ((p1.optionalMoves(b, *this).empty())
			 && (p2.optionalMoves(b, *this).empty()));
}

void GameLogic::findWinner(const Board &b, const Player &p1, const Player &p2) const {
	int countP1 = 0, countP2 = 0;
	for(int i = 1; i <= LENGTH; i ++) {
		for (int j = 1; j <= LENGTH; j++) {
			if (b.getSide(i, j) == p1.getSign()) {
				countP1++;
			} else if (b.getSide(i, j) == p2.getSign()) {
				countP2++;
			}
		}
	}

    cout << "The game is finished!" << endl;
    cout << "Total score : " << endl;
    cout << "Player 1: " << countP1 << endl;
    cout << "Player 2: " << countP2 << endl << endl;
	if (countP1 > countP2) {
		cout << "XXXXXXXXXXXXXXXXXXXXXXXXX" << endl << "Player 1 is the winner !!"
			 << endl << "XXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
	} else if (countP1 < countP2) {
		cout << "OOOOOOOOOOOOOOOOOOOOOOOOO" << endl << "Player 2 is the winner !!"
			 << endl << "OOOOOOOOOOOOOOOOOOOOOOOOO" << endl;
	} else {
		cout << "XOXOXOXOXOXOXOXOXOXOXOXOX" << endl << "It's a tie !!"
			 << endl << "OXOXOXOXOXOXOXOXOXOXOXOXO" << endl;
	}
}