//
// Created by ben on 12/27/17.
//

#ifndef REVERSITEST_COMMANDSMANAGER_H
#define REVERSITEST_COMMANDSMANAGER_H

#include <map>
#include "Command.h"
#include "TestCommand.h"

class CommandsManager {
public:
    CommandsManager();
    ~CommandsManager();
    void executeCommand(string command, vector<string> args);

private:
    map<string, Command*> commandsMap;
};


#endif //REVERSITEST_COMMANDSMANAGER_H
