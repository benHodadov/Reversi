//
// Created by ben on 12/27/17.
//

#ifndef REVERSITEST_COMMANDSMANAGER_H
#define REVERSITEST_COMMANDSMANAGER_H

#include <map>
#include "Command.h"
#include "TestCommand.h"
#include "StartCommand.h"
#include "JoinCommand.h"
#include "ListGamesCommand.h"
#include "PlayCommand.h"
#include "CloseCommand.h"
#include "GamesLobby.h"


class CommandsManager {
public:
    CommandsManager();
    ~CommandsManager();
    void* executeCommand(string command, vector<string> args, __socklen_t socket = 0);
private:
    map<string, Command*> commandsMap;
    GamesLobby games;
};


#endif //REVERSITEST_COMMANDSMANAGER_H
