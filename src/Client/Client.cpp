//
// Created by ben-hodadov on 07/12/17.
//


#include "Client.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <cstdlib>

using namespace std;

Client::Client(string serverIP, int serverPort):
        serverIP(serverIP.c_str()), serverPort(serverPort),clientSocket(0) {
}
Client::Client() {
}

void Client::connectToServer() {
    // Create a socket point
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        throw "Error opening socket";
    }
    // Convert the ip string to a network address
    struct in_addr address;
    if (!inet_aton(serverIP, &address)) {
        throw "Can't parse IP address";
    }

    // Get a hostent structure for the given host address
    struct hostent *server;
    server = gethostbyaddr((const void*)&address, sizeof address, AF_INET);
    if (server == NULL) {
        throw "Host is unreachable";
    }
    // Create a structure for the server address
    struct sockaddr_in serverAddress;
    bzero((char*)&address, sizeof(address));
    serverAddress.sin_family = AF_INET;
    memcpy((char*)&serverAddress.sin_addr.s_addr, (char*)server -> h_addr, server->h_length);
    // htons converts values between host and network byte orders
    serverAddress.sin_port = htons(serverPort);
    // Establish a connection with the TCP server
    if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error connecting to server";
    }
    cout << "Connected to server" << endl;
}

int Client::getSign() {
    int sign;
    read(clientSocket, &sign, sizeof(sign));
    return sign;
}

Position Client::receiveFromServer() {
    // Read the result from the server
    int r, c, n;
    char comma = ',';
    n = read(clientSocket, &r, sizeof(int));
    if (n == -1) {
        throw "Error reading row from socket";
    }
    n = read(clientSocket, &comma, sizeof(comma));
    if (n == -1) {
        throw "Error reading comma from socket";
    }
    n = read(clientSocket, &c, sizeof(int));
    if (n == -1) {
        throw "Error reading col from socket";
    }
    return Position(r, c);
}

void Client::sendToServer(int row, int col) {
    char comma = ',';
    // Write the position to the socket
    int n = write(clientSocket, &row, sizeof(row));
    if  (n == -1) {
        throw "Error writing row to socket";
    }
    n = write(clientSocket, &comma, sizeof(comma));
    if (n == -1) {
        throw "Error writing comma to socket";
    }
    n = write(clientSocket, &col, sizeof(col));
    if (n == -1) {
        throw "Error writing col to socket";
    }
}
