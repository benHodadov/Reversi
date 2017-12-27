//
// Created by ben on 12/27/17.
//

#ifndef REVERSITEST_LISTGAMESCOMMAND_H
#define REVERSITEST_LISTGAMESCOMMAND_H

#include "Command.h"
#include <iostream>

class ListGamesCommand {
public:
    virtual void execute(vector<string> args);
};


#endif //REVERSITEST_LISTGAMESCOMMAND_H
