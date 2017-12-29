//
// Created by ben on 12/27/17.
//

#ifndef REVERSITEST_LISTGAMESCOMMAND_H
#define REVERSITEST_LISTGAMESCOMMAND_H

#include "Command.h"
#include <iostream>

class ListGamesCommand: public Command {
public:
    virtual void* execute(vector<string> args, GamesLobby* games, __socklen_t socket);
};


#endif //REVERSITEST_LISTGAMESCOMMAND_H
