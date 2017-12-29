//
// Created by ben on 12/27/17.
//

#ifndef REVERSITEST_TESTCOMMAND_H
#define REVERSITEST_TESTCOMMAND_H

#include "Command.h"
#include <iostream>

class TestCommand : public Command {
public:
    virtual void execute(vector<string> args, GamesLobby* games, __socklen_t socket);
};

#endif //REVERSITEST_TESTCOMMAND_H
