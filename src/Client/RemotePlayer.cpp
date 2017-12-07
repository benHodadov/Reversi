//
// Created by ben-hodadov on 07/12/17.
//

#include "RemotePlayer.h"

RemotePlayer::RemotePlayer(char _s):Player(_s), client("127.0.0.1", 44444) {
    client.connectToServer();
}

Position RemotePlayer::chooseMove(GameLogic &gl, vector<Position> om,  const Board &b) {
    vector<Position>::iterator it;
    int r,c;
    cout << "Please enter your move row,col: " ;
    cin >> r >> c; // row and col input
    Position selectedPosition(r,c);

    bool isValid = false;
    for (it = om.begin(); it != om.end(); ++it) {
        if (selectedPosition == *it) {
            isValid = true;
            return client.sendMessage(selectedPosition.getRow(), selectedPosition.getCol());
            return selectedPosition;
        }
    }

    while (!isValid) { // if it isn't valid, get row&col again until it's ok
        cout << endl << "The selected position is not valid." << endl << "Please enter your move row,col: ";
        cin >> r >> c;
        Position selectedPosition(r,c);
        for (it = om.begin(); it != om.end(); ++it) {
            if (selectedPosition == *it) {
                isValid = true;
                return client.sendMessage(selectedPosition.getRow(), selectedPosition.getCol());
                //return selectedPosition;
            }
        }
    }
}

void RemotePlayer::playOneTurn(GameLogic &gl, Board *b) {
    cout << "Current board:" << endl;
    b->print();// prints the board

    cout << "Waiting for " << this->getSign() << "move." << endl;
    vector<Position> v = this->optionalMoves(*b, gl);

    // if any of the moves are legal return 0.
    if (v.size() == 0) {
        cout << "No possible moves. Play passes back to the other player. Press any key to continue.";
        char dummy; // a dummy
        cin >> dummy;
        cout << endl;
        return;
    }

    //There is at least one possible move. print the moves.
    vector<Position>::iterator it;
    for (it = v.begin(); it != v.end(); ++it) {
        cout << *it;
        if ((it + 1) != v.end()) {
            cout << ",";
        }
    }
    cout << endl;
    Position selected = this->chooseMove(gl, v, *b); // use choose move

    //put and turn over.
    gl.putAndTurnOver(b, selected.getRow(), selected.getCol(), *this); // use play and turn over
}
