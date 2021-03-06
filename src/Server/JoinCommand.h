//
// Created by ben on 12/27/17.
//

#ifndef REVERSITEST_JOINCOMMAND_H
#define REVERSITEST_JOINCOMMAND_H

#include "Command.h"
#include <iostream>

class JoinCommand: public Command {
public:
    /**
     * This method will execute the join command.
     * @param args vector<string>
     * @param games GamesLobby*
     * @param socket __socklen_t
     * @return executed
     */
    virtual void* execute(vector<string> args, GamesLobby* games, __socklen_t socket);
};


#endif //REVERSITEST_JOINCOMMAND_H
