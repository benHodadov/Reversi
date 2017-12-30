//
// Created by ben on 12/27/17.
//

#ifndef REVERSITEST_PLAYCOMMAND_H
#define REVERSITEST_PLAYCOMMAND_H

#include "Command.h"
#include <iostream>

// the PlayCommand derived from the command interface
class PlayCommand: public Command {
public:
/**
     * This method will execute the play command.
     * @param args vector<string>
     * @param games GamesLobby*
     * @param socket __socklen_t
     * @return executed
     */
    virtual void* execute(vector<string> args, GamesLobby* games, __socklen_t socket);
};


#endif //REVERSITEST_PLAYCOMMAND_H