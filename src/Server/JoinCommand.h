//
// Created by ben on 12/27/17.
//

#ifndef REVERSITEST_JOINCOMMAND_H
#define REVERSITEST_JOINCOMMAND_H

#include "Command.h"
#include <iostream>

class JoinCommand: public Command {
public:
    virtual void* execute(vector<string> args, GamesLobby* games, __socklen_t socket);
};


#endif //REVERSITEST_JOINCOMMAND_H
