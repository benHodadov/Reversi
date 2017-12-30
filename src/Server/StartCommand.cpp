//
// Created by ben on 12/27/17.
//

#include <unistd.h>
#include "StartCommand.h"

void* StartCommand::execute(vector<string> args, GamesLobby* games, __socklen_t socket) {
    cout << "Start command" << endl;
    GameRoom* isExist = games->search(args.at(0));
    if (isExist) {
        int res = -1;
        int n = write(socket, &res, 100);
        return (void*)res;
    }
    // else
    games->addRoom(args.at(0), socket);
    int res = 0;
    int n = write(socket, &res, 100);
    return (void*)res;
}
