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
    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen = sizeof((struct sockaddr*) &clientAddress);
    while (true) {
        cout << "Waiting for client connections..." << endl;
        // Accept a new client connection
        int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientAddressLen);
        cout << "Client connected" << endl;
        if (clientSocket == -1)
            throw "Error on accept";
        handleClient(clientSocket);
        // Close communication with the client
        close(clientSocket);
    }
}

void Server::stop() {
    close(serverSocket);
}

void Server::handleClient(int clientSocket) {
    int row, col;
    char comma;

    while (true) {
        //read new cell.
        // read row.
        int n = read(clientSocket, &row, sizeof(row));
        if (n == -1) {
            cout << "Error reading row" << endl;
            return;
        } else if (n == 0) {
            cout << "Client disconnected" << endl;
            return;
        }

        //read ','
        n = read(clientSocket, &comma, sizeof(comma));
        if (n == -1) {
            cout << "Error reading comma" << endl;
            return;
        }

        //read col
        n = read(clientSocket, &col, sizeof(col));
        if (n == -1) {
            cout << "Error reading comma" << endl;
            return;
        }

        cout << "Received " << row << comma << col << endl;

        //write result back to the client
        n = write(clientSocket, &row, sizeof(row));
        if (n == -1) {
            cout << "Error writing row to socket" << endl;
            return;
        }
        n = write(clientSocket, &comma, sizeof(comma));
        if (n == -1) {
            cout << "Error writing comma to socket" << endl;
            return;
        }
        n = write(clientSocket, &col, sizeof(col));
        if (n == -1) {
            cout << "Error writing col to socket" << endl;
            return;
        }
    }
}