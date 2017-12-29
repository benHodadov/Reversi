//
// Created by ben on 12/27/17.
//

#ifndef REVERSITEST_CLOSECOMMAND_H
#define REVERSITEST_CLOSECOMMAND_H

#include "Command.h"
#include <iostream>

class CloseCommand: public Command {
public:
    virtual void execute(vector<string> args, GamesLobby* games, __socklen_t socket);
};


#endif //REVERSITEST_CLOSECOMMAND_H
