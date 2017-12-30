//
// Created by ben on 12/29/17.
//

#include "GameRoom.h"

GameRoom::GameRoom(string roomName, socklen_t firstSocket) {
    this->name = roomName;
    this->first = firstSocket;
    this->second == NULL;
}

bool GameRoom::isAvailable() {
    return second == NULL;
}

void GameRoom::join(socklen_t second) {
    this->second = second;
}

socklen_t GameRoom::getFirst() const {
    return first;
}

socklen_t GameRoom::getSecond() const {
    return second;
}

const string &GameRoom::getName() const {
    return name;
}
