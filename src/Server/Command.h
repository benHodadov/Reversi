//
// Created by ben on 12/27/17.
//

#ifndef REVERSITEST_COMMAND_H
#define REVERSITEST_COMMAND_H

#include <vector>
#include <string>
#include "GamesLobby.h"
using namespace std;

// The Command interface.
class Command {
public:
    /**
     * This method executes the command.
     * @param args vector<string>
     * @param games GamesLobby
     * @param socket __socklen_t
     * @return executed
     */
    virtual void* execute(vector<string> args,GamesLobby* games, __socklen_t socket) = 0;

    /**
     * A destructor.
     */
    virtual ~Command() {}
};


#endif //REVERSITEST_COMMAND_H
