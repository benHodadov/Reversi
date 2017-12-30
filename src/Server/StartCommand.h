//
// Created by ben on 12/27/17.
//

#ifndef REVERSITEST_STARTCOMMAND_H
#define REVERSITEST_STARTCOMMAND_H

#include "Command.h"
#include <iostream>

// the StartCommand derived from the command interface
class StartCommand: public Command {
public:
/**
     * This method will execute the start command.
     * @param args vector<string>
     * @param games GamesLobby*
     * @param socket __socklen_t
     * @return executed
     */
    virtual void* execute(vector<string> args, GamesLobby* games, __socklen_t socket);
};


#endif //REVERSITEST_STARTCOMMAND_H