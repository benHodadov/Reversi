//
// Created by ben on 12/27/17.
//

#ifndef REVERSITEST_PLAYCOMMAND_H
#define REVERSITEST_PLAYCOMMAND_H

#include "Command.h"
#include <iostream>

class PlayCommand {
public:
    virtual void execute(vector<string> args);
};


#endif //REVERSITEST_PLAYCOMMAND_H
