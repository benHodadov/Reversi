//
// Created by ben-hodadov on 06/12/17.
//

#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
using namespace std;
#define MAX_CONNECTED_CLIENTS 2


Server:: Server(int port): port(port), serverSocket(0) {
    cout << "Server" << endl;
}

void Server:: start() {
    // Create a socket point
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        throw "Error opening socket";
    }
    // Assign a local address to the socket
    struct sockaddr_in serverAddress;
    bzero((void*)&serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);
    if(bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error on binding";
    }
    // Start listening to incoming connections
    listen(serverSocket, MAX_CONNECTED_CLIENTS);
    // Define the client socket's structures
    struct sockaddr_in clientAddress1;
    socklen_t clientAddressLen1 = sizeof((struct sockaddr*) &clientAddress1);

    struct sockaddr_in clientAddress2;
    socklen_t clientAddressLen2 = sizeof((struct sockaddr*) &clientAddress2);
    while (true) {
        cout << "Waiting for connections..." << endl;
        // Accept a new client connection
        int clientSocket1 = accept(serverSocket, (struct sockaddr*)&clientAddress1, &clientAddressLen1);
        if (clientSocket1 == -1) {
            throw "Error on first accept";
        }
        cout << "first client connected" << endl;


        int FirstOrSecond = 1;
        int v = write(clientSocket1, &FirstOrSecond, sizeof(FirstOrSecond));
        if (v == -1) {
            cout << "Error writing message to player 1" << endl;
            return;
        }

        // Accept a new client connection
        int clientSocket2 = accept(serverSocket, (struct sockaddr*)&clientAddress2, &clientAddressLen2);
        if (clientSocket2 == -1) {
            throw "Error on second accept";
        }
        cout << "second client connected" << endl;

        FirstOrSecond = 2;
        v = write(clientSocket2, &FirstOrSecond, sizeof(FirstOrSecond));
        if (v == -1) {
            cout << "Error writing message to player 2" << endl;
            return;
        }

        //send sign to the players.
        int x = 1;
        int o = 2;
        int n = write(clientSocket1, &x, sizeof(x));
        if (n == -1) {
            cout << "Error writing x to player 1" << endl;
            return;
        }
        n = write(clientSocket2, &o, sizeof(o));
        if (n == -1) {
            cout << "Error writing o to player 2" << endl;
            return;
        }

        bool endGame = false;
        while (!endGame) {
            endGame = handleClient(clientSocket1, clientSocket2);
            if (endGame) {
                break;
            }
            endGame = handleClient(clientSocket2, clientSocket1);
        }

        // Close communication with the client
        close(clientSocket1);
        close(clientSocket2);
        stop();
        return;
    }
}

void Server::stop() {
    close(serverSocket);
}

bool Server::handleClient(int srcSocket, int destSocket) {
    int row, col;
    char comma;

    while (true) {
        // read row.
        int n = read(srcSocket, &row, sizeof(row));
        if (n == -1) {
            cout << "Error reading row" << endl;
            return true;
        } else if (n == 0) {
            cout << "Client disconnected" << endl;
            return true;
        }

        //read ','
        n = read(srcSocket, &comma, sizeof(comma));
        if (n == -1) {
            cout << "Error reading comma" << endl;
            return true;
        }

        //read col
        n = read(srcSocket, &col, sizeof(col));
        if (n == -1) {
            cout << "Error reading comma" << endl;
            return true;
        }

        //print the received position.
        cout << "Received " << row << comma << col << endl;

        //check if the game is over.
        if (row == -1 && col == -1) {
            return true;
        }

        //write result back to the client
        n = write(destSocket, &row, sizeof(row));
        if (n == -1) {
            cout << "Error writing row to socket" << endl;
            return true;
        }
        n = write(destSocket, &comma, sizeof(comma));
        if (n == -1) {
            cout << "Error writing comma to socket" << endl;
            return true;
        }
        n = write(destSocket, &col, sizeof(col));
        if (n == -1) {
            cout << "Error writing col to socket" << endl;
            return true;
        }
        return false;
    }
}