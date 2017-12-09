//
// Created by ben-hodadov on 06/12/17.
//
#include <iostream>
#include <fstream>
#include "Server.h"

using namespace std;

int main() {
    ifstream settingsFile;
    settingsFile.open("ServerSettings.txt");
    if (settingsFile.is_open()) {
        int port;
        settingsFile >> port;
        cout << port << endl;
        Server server(port);

        try {
            server.start();
        } catch (const char *msg) {
            cout << "Error because " << msg << endl;
            return 1;
        }
        settingsFile.close();
        return 0;
    } else {
        cout << "error opening settings file" << endl;
    }
    return 1;
}