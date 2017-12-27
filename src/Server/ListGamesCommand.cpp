//
// Created by ben on 12/27/17.
//

#include "ListGamesCommand.h"

void ListGamesCommand::execute(vector<string> args) {
    cout << "Close command" << endl;
    for (int i = 0; i < args.size(); ++i) {
        cout << args[i] << " ";
    }
    cout << endl;
}