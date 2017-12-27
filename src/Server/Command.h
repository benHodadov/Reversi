//
// Created by ben on 12/27/17.
//

#ifndef REVERSITEST_COMMAND_H
#define REVERSITEST_COMMAND_H

#include <vector>
#include <string>

using namespace std;

class Command {
public:
    virtual void execute(vector<string> args) = 0;
    virtual ~Command() {}
};


#endif //REVERSITEST_COMMAND_H
