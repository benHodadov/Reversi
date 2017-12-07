//
// Created by ben-hodadov on 06/12/17.
//
#include <iostream>
#include "Server.h" msg

using namespace std;

int main() {
    Server server(55555);
    try {
        server.start();
    } catch (const char *msg) {
        cout << "Error because " << msg << endl;
        return 1;
    }
    return 0;
}