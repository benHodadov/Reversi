//
// Created by ben on 12/27/17.
//

#include <unistd.h>
#include "CloseCommand.h"


void* CloseCommand::execute(vector<string> args,GamesLobby* games, __socklen_t socket) {
    cout << "Close command" << endl;
    GameRoom* game = games->search(args.at(0));
    // if there is no room with this name - return -1.
    if (game == NULL) {
        return (void*) -1;
    }
    // else - there is room with this name
    // check if the player plays the current game.
    if (game->getFirst() == socket || game->getSecond() == socket) {
        // if he playing the current game - close the game and return 0.
        close(game->getFirst());
        close(game->getSecond());
        return (void*) 0;
    }
    // else - he is trying to close a game which he doesn't belong to. return -1.
    return (void*) -1;
}
