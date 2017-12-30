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
    cout << "Play command" << endl;
    int x = atoi(args.at(0).c_str());
    int y = atoi(args.at(0).c_str());
    int n;
    n = write(socket, &x, sizeof(x));
    char comma = ',';
    if (n == -1) {
        cout << "Error writing row to socket" << endl;
        return (void*)true;
    }
    n = write(socket, &comma, sizeof(comma));
    if (n == -1) {
        cout << "Error writing comma to socket" << endl;
        return (void*)true;
    }
    n = write(socket, &y, sizeof(y));
    if (n == -1) {
        cout << "Error writing col to socket" << endl;
        return (void*)true;
    }
    return (void*)false;
}