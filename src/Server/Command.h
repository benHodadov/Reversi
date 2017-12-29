//
// Created by ben on 12/27/17.
//

#ifndef REVERSITEST_COMMAND_H
#define REVERSITEST_COMMAND_H

#include <vector>
#include <string>
#include "GamesLobby.h"

using namespace std;

class Command {
public:
    virtual void execute(vector<string> args,GamesLobby* games, __socklen_t socket) = 0;
    virtual ~Command() {}
};


#endif //REVERSITEST_COMMAND_H
