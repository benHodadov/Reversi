//
// Created by ben on 12/29/17.
//

#include "GamesLobby.h"

GamesLobby::GamesLobby() {
    this->gamesMap = map<string, GameRoom *>();
}


bool GamesLobby::join(string roomName, socklen_t secondPlayer) {
    //GameRoom* search = gamesMap[roomName];
    GameRoom* search = this->gamesMap.find(roomName)->second;
    if (search == NULL) {
        return false;
    }
    if (search->isAvailable()) {
        // we should add the join the second player to the game
        search->join(secondPlayer);
        return true;
    }
    return false;
}

bool GamesLobby::addRoom(string roomName, socklen_t firstPlayer) {
    GameRoom* search = this->gamesMap.find(roomName)->second;
    if (search == NULL) {
        GameRoom g(roomName, firstPlayer);
        //this->gamesMap.insert(pair<string, GameRoom*>(roomName, &g));

        gamesMap[roomName] = &g;
        return true;
    }
    return false;
}
