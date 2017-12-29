//
// Created by ben on 12/27/17.
//

#ifndef REVERSITEST_STARTCOMMAND_H
#define REVERSITEST_STARTCOMMAND_H

#include "Command.h"
#include <iostream>

class StartCommand: public Command {
public:
    virtual void execute(vector<string> args, GamesLobby* games, __socklen_t socket);
};


#endif //REVERSITEST_STARTCOMMAND_H
