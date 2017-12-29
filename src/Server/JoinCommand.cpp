//
// Created by ben on 12/27/17.
//

#include "JoinCommand.h"

void* JoinCommand::execute(vector<string> args, GamesLobby* games, __socklen_t socket) {
    cout << "Join command" << endl;
    bool x = games->join(args.at(0), socket);
    return (void*) x;
}