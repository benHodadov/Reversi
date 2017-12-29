//
// Created by ben on 12/27/17.
//

#ifndef REVERSITEST_PLAYCOMMAND_H
#define REVERSITEST_PLAYCOMMAND_H

#include "Command.h"
#include <iostream>

class PlayCommand: public Command {
public:
    virtual void execute(vector<string> args, GamesLobby* games, __socklen_t socket);
};


#endif //REVERSITEST_PLAYCOMMAND_H
