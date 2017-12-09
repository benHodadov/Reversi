//
// Created by ben-hodadov on 07/12/17.
//

#ifndef REVERSITEST_CLIENT_H
#define REVERSITEST_CLIENT_H


#include "Position.h"

class Client {
public:
    Client(const char *serverIP, int serverPort);
    Client();
    void connectToServer();
    int getSign();
    void sendToServer(int row, int col);
    Position receiveFromServer();

private:
    const char* serverIP;
    int serverPort;
    int clientSocket;
};


#endif //REVERSITEST_CLIENT_H
