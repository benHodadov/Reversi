//
// Created by ben on 12/27/17.
//

#ifndef REVERSITEST_COMMANDSMANAGER_H
#define REVERSITEST_COMMANDSMANAGER_H

#include <map>
#include "Command.h"
#include "StartCommand.h"
#include "JoinCommand.h"
#include "ListGamesCommand.h"
#include "PlayCommand.h"
#include "CloseCommand.h"
#include "GamesLobby.h"

// the command manager class. manages all commands.
class CommandsManager {
public:
    /**
     * A constructor.
     */
    CommandsManager();

    /**
     * A destructor.
     */
    ~CommandsManager();

    /**
     * This method executes the selected command. (calls the wanted command type).
     * @param command string
     * @param args vector<string>
     * @param socket __socklen_t
     * @return executed
     */
    void* executeCommand(string command, vector<string> args, __socklen_t socket = 0);
private:
    map<string, Command*> commandsMap; // it holds a map of strings and commands.
    GamesLobby games; // also has a game "lobby"
};


#endif //REVERSITEST_COMMANDSMANAGER_H
