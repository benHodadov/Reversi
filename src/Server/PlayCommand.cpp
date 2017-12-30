//
// Created by ben on 12/27/17.
//

#include "PlayCommand.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>

using namespace std;

void* PlayCommand::execute(vector<string> args, GamesLobby* games, __socklen_t socket) {
    // socket is the source socket. we will find the destination socket.
    GameRoom* game = games->search(socket);
    if (game == NULL) {
        // there is no room matching. return -1.
        return (void*) -1;
    }
    // else - there is a room. find the dst socket
    // if the socket = the first socket - return the second one. else return the first one.
    __socklen_t destsocket = (socket == game->getFirst())? game->getSecond(): game->getFirst();

    cout << "Play command" << endl;
    int x = atoi(args.at(0).c_str());
    int y = atoi(args.at(0).c_str());
    int n;
    n = write(destsocket, &x, sizeof(x));
    char comma = ',';
    if (n == -1) {
        cout << "Error writing row to socket" << endl;
        return (void*)true;
    }
    n = write(destsocket, &comma, sizeof(comma));
    if (n == -1) {
        cout << "Error writing comma to socket" << endl;
        return (void*)true;
    }
    n = write(destsocket, &y, sizeof(y));
    if (n == -1) {
        cout << "Error writing col to socket" << endl;
        return (void*)true;
    }
    return (void*)false;
}