//
// Created by ben on 12/27/17.
//

#include "StartCommand.h"

void StartCommand::execute(vector<string> args) {
    cout << "Start command" << endl;
    for (int i = 0; i < args.size(); ++i) {
        cout << args[i] << " ";
    }
    cout << endl;
}
