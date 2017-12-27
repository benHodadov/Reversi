//
// Created by ben on 12/27/17.
//

#include "TestCommand.h"

void TestCommand::execute(vector<string> args) {
    cout << "Executing test" << endl;
    for (int i = 0; i < args.size(); ++i) {
        cout << args[i] << " ";
    }
    cout << endl;
}
