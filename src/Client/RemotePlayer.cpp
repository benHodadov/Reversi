//
// Created by ben-hodadov on 07/12/17.
//

#include "RemotePlayer.h"

RemotePlayer::RemotePlayer(char _s, Client* c):Player(_s) {
    client = c;
}

Position RemotePlayer::chooseMove(GameLogic &gl, vector<Position> om,  const Board &b) {
}

Position RemotePlayer::playOneTurn(GameLogic &gl, Board *b) {
    cout << "Current board:" << endl;
    b->print();// prints the board

    cout << "Waiting for " << this->getSign() << " move." << endl;

    Position selected = client->receiveFromServer();

    //if opponent didn't have any possible moves.
    if (selected.getRow() == 0 && selected.getCol() == 0) {
        cout << "Opponent does not have any valid moves.\n It's your turn." << endl;
        return selected;
    }

    cout << this->getSign() << " played " << selected << endl;
    //put and turn over.
    gl.putAndTurnOver(b, selected.getRow(), selected.getCol(), *this); // use play and turn over
    //client->sendToServer(selected.getRow(), selected.getCol());
    return selected;
}
