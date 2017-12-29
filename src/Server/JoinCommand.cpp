//
// Created by ben on 12/27/17.
//

#include "JoinCommand.h"

void JoinCommand::execute(vector<string> args, GamesLobby* games, __socklen_t socket) {
    cout << "Join command" << endl;
    for (int i = 0; i < args.size(); ++i) {
        cout << args[i] << " ";
    }
    cout << endl;
}