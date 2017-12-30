//
// Created by ben on 12/27/17.
//

#include "CloseCommand.h"


void* CloseCommand::execute(vector<string> args,GamesLobby* games, __socklen_t socket) {
    cout << "Close command" << endl;
    GameRoom* game = games->search(args.at(0));
    if (game == NULL) {
        return (void*) -1;
    }
    // else

}
