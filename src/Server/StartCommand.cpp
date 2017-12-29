//
// Created by ben on 12/27/17.
//

#include "StartCommand.h"

void* StartCommand::execute(vector<string> args, GamesLobby* games, __socklen_t socket) {
    cout << "Start command" << endl;
    GameRoom* isExist = games->search(args.at(0));
    if (isExist) {
        return (void*)-1;
    }
    // else
    games->addRoom(args.at(0), socket);
    cout << endl;
    return (void*)0;
}
