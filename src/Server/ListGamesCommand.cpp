//
// Created by ben on 12/27/17.
//

#include "ListGamesCommand.h"

void* ListGamesCommand::execute(vector<string> args, GamesLobby* games, __socklen_t socket) {
    cout << "List_Games command" << endl;
    vector<GameRoom*> availableRooms = games->availableRooms();
    return (void*) &availableRooms;
}