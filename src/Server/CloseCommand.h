//
// Created by ben on 12/27/17.
//

#ifndef REVERSITEST_CLOSECOMMAND_H
#define REVERSITEST_CLOSECOMMAND_H

#include "Command.h"
#include <iostream>

// the CloseCommand derived from the command interface
class CloseCommand: public Command {
public:
    /**
     * This method will execute the close command.
     * @param args vector<string>
     * @param games GamesLobby*
     * @param socket __socklen_t
     * @return executed
     */
    virtual void* execute(vector<string> args, GamesLobby* games, __socklen_t socket);
};


#endif //REVERSITEST_CLOSECOMMAND_H
