//
// Created by ben on 12/29/17.
//

#ifndef REVERSITEST_GAMEROOM_H
#define REVERSITEST_GAMEROOM_H

#include <string>
#include <sys/socket.h>
using namespace std;

// A game room class.
class GameRoom {
public:
    /**
     * A constructor.
     * @param roomName string
     * @param firstSocket socklen_t
     */
    GameRoom(string roomName, socklen_t firstSocket);

    /**
     * this method joins the player to be the second player in a game.
     * @param second socklen_t
     */
    void join(socklen_t second);

    /**
     * This method returns true if the room is available and false otherwise.
     * @return isAvailable
     */
    bool isAvailable();

private:
    string name;
    socklen_t first;
    socklen_t second;
};


#endif //REVERSITEST_GAMEROOM_H
