//
// Created by ben on 12/27/17.
//

#include "CommandsManager.h"

CommandsManager::CommandsManager() {
    map<string, Command*> commandsMap;
    commandsMap["start"] = new StartCommand();
    commandsMap["list_games"] = new ListGamesCommand();
    commandsMap["join"] = new JoinCommand();
    commandsMap["play"] = new PlayCommand();
    commandsMap["close"] = new CloseCommand();
    games = GamesLobby();
}

void* CommandsManager::executeCommand(string command, vector<string> args, __socklen_t socket /*=0*/) {
    Command *commandObj = commandsMap[command];
    return commandObj->execute(args, &games, socket);
}

CommandsManager::~CommandsManager() {
    map<string, Command*>::iterator it;
    for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
        delete it->second;
    }
}
