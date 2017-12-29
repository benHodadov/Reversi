//
// Created by ben on 12/29/17.
//

#ifndef REVERSITEST_GAMESLOBBY_H
#define REVERSITEST_GAMESLOBBY_H

#include <map>
#include <string>
#include "GameRoom.h"

using  namespace std;

class GamesLobby {
public:
    GamesLobby();
    bool join(string roomName, socklen_t secondPlayer);
    bool addRoom(string roomName, socklen_t firstPlayer);
private:
    map<string, GameRoom*> gamesMap;
};


#endif //REVERSITEST_GAMESLOBBY_H