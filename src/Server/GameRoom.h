//
// Created by ben on 12/29/17.
//

#ifndef REVERSITEST_GAMEROOM_H
#define REVERSITEST_GAMEROOM_H

#include <string>
#include <sys/socket.h>
using namespace std;

class GameRoom {
public:
    GameRoom(string roomName, socklen_t firstSocket);
    void join(socklen_t second);
    bool isAvailable();

private:
    string name;
    socklen_t first;
    socklen_t second;
};


#endif //REVERSITEST_GAMEROOM_H
