//
// Created by ben on 12/27/17.
//

#ifndef REVERSITEST_CLOSECOMMAND_H
#define REVERSITEST_CLOSECOMMAND_H

#include "Command.h"
#include <iostream>

class CloseCommand {
public:
    virtual void execute(vector<string> args);
};


#endif //REVERSITEST_CLOSECOMMAND_H
