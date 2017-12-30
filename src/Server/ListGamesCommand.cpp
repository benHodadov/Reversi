//
// Created by ben on 12/27/17.
//

#include <unistd.h>
#include "ListGamesCommand.h"

void* ListGamesCommand::execute(vector<string> args, GamesLobby* games, __socklen_t socket) {
    cout << "List_Games command" << endl;
    vector<GameRoom*> availableRooms = games->availableRooms();
    //vector<string> availableRoomsNames;

    vector<GameRoom*>::iterator iter;
    string roomsList = "";
    int i = 0;
    for (iter = availableRooms.begin(); iter != availableRooms.end(); iter++) {
        //availableRoomsNames.push_back((*iter)->getName());
        roomsList += (*iter)->getName() + "~";
    }
    if (roomsList.empty()) {
        string msg = "There are no available rooms.";
        int v = write(socket, &msg, 100);
        return (void*) -1;
    }
    int v = write(socket, &roomsList, 100);
    if (v == -1) {
        cout << "Error writing games list\n" << endl;
        return (void*) -1;
    }

    return (void*)0;
}