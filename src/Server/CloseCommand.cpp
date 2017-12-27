//
// Created by ben on 12/27/17.
//

#include "CloseCommand.h"

void CloseCommand::execute(vector<string> args) {
    cout << "Close command" << endl;
    for (int i = 0; i < args.size(); ++i) {
        cout << args[i] << " ";
    }
    cout << endl;
}
