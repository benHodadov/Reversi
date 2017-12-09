//
// Created by ben-hodadov on 07/12/17.
//

#include "LocalPlayer.h"

LocalPlayer::LocalPlayer(char _s, Client* c):Player(_s), player(_s) {
    client = c;
}

Position LocalPlayer::chooseMove(GameLogic &gl, vector<Position> om,  const Board &b) {
    return player.chooseMove(gl, om, b);
}

Position LocalPlayer::playOneTurn(GameLogic &gl, Board *b) {
    Position played = player.playOneTurn(gl, b);
    client->sendToServer(played.getRow(), played.getCol());
    return played;
}
