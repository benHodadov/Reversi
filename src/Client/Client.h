//
// Created by ben-hodadov on 07/12/17.
//

#ifndef REVERSITEST_CLIENT_H
#define REVERSITEST_CLIENT_H


#include "Position.h"

class Client {
public:
    /**
     * A constructor.
     * @param serverIP const char*
     * @param serverPort int
     */
    Client(string serverIP, int serverPort);

    /**
     * A default constructor.
     */
    Client();

    /**
     * the method connects the client to the server.
     */
    void connectToServer();

    /**
     * A get method to sign
     * @return sign
     */
    int getSign();

    /**
     * The method sends a position to the server.
     * @param row int
     * @param col int
     */
    void sendToServer(int row, int col);

    /**
     * The method gets a position to the server
     * @return posFromServer
     */
    Position receiveFromServer();

private:
    const char* serverIP;
    int serverPort;
    int clientSocket;
};


#endif //REVERSITEST_CLIENT_H
