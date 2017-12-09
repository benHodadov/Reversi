//
// Created by ben-hodadov on 07/12/17.
//

#include "LocalPlayer.h"

LocalPlayer::LocalPlayer(char _s, Client* c):Player(_s), player(_s) {
    client = c;
}

Position LocalPlayer::chooseMove(GameLogic &gl, vector<Position> om,  const Board &b) {
    return player.chooseMove(gl, om, b); // uses player's chooseMove function (same implementation)
}

Position LocalPlayer::playOneTurn(GameLogic &gl, Board *b) {
    Position played = player.playOneTurn(gl, b); // uses player's playOneTurn function (same implementation)
    client->sendToServer(played.getRow(), played.getCol()); // send the selected move to the server
    return played; // returns the move
}

void LocalPlayer::endGame() {
    client->sendToServer(-1, -1);
}
