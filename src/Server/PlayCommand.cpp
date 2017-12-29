//
// Created by ben on 12/27/17.
//

#include "PlayCommand.h"

void* PlayCommand::execute(vector<string> args, GamesLobby* games, __socklen_t socket) {
    cout << "Play command" << endl;
    for (int i = 0; i < args.size(); ++i) {
        cout << args[i] << " ";
    }
    cout << endl;
}