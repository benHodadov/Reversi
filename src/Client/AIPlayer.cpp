//
// Created by ben and barak hodadov on 25/11/17.
//

#include "AIPlayer.h"
using namespace std;


AIPlayer::AIPlayer(char _s):Player(_s) {
}

Position AIPlayer::chooseMove(GameLogic &gl, vector<Position> om,  const Board &b) {
    vector<Position>::iterator it;

    Position bestMove = om.front();
    Board fake; // a fake board. a copy of the present board
    int r, c;
    int maxOpponentScore = 0, miniMax = 64; // variables which would tell us about the minimax

    for (it = om.begin(); it != om.end(); ++it) { // goes throw all available moves
        r = it->getRow();
        c = it->getCol();
        fake = b.copy(); // resets the copy board from the changes
        fake.put(r, c, this->getSign()); // puts the sign in the cell

        vector<Position> opponentMoves;
        vector<Position>::iterator oppIt;
        int currentScore;
        for (oppIt = opponentMoves.begin(); oppIt != opponentMoves.end(); ++oppIt) {
            //calculate score
            currentScore = gl.calculateScore(b);
            maxOpponentScore = std::max(maxOpponentScore, currentScore); // calculates the max score in this option
        }

        if (miniMax > maxOpponentScore) { // if the max score is smaller than the present one
            miniMax = maxOpponentScore; // update minimax (lowest high score)
            bestMove = *it; // save the computer's best move
        }
    }

    return bestMove; // returns the best move
}

Position AIPlayer::playOneTurn(GameLogic &gl, Board *b) {
    cout << "Current board:" << endl;
    b->print();

    cout << this->getSign() << ": It's computer move." << endl;
    vector<Position> v = this->optionalMoves(*b, gl);

    // if any of the moves are legal return 0.
    if (v.empty()) {
        cout << "Computer has no possible moves. it's your turn." << endl;
        return Position(0,0);
    }
    //there is at least one possible move.
    Position selected = this->chooseMove(gl, v, *b);
    cout << "Position " << selected << " selected" << endl;

    //put and turn over.
    gl.putAndTurnOver(b, selected.getRow(), selected.getCol(), *this);

    return selected;
}