//
// Created by ben-hodadov on 06/12/17.
//

#ifndef REVERSITEST_SERVER_H
#define REVERSITEST_SERVER_H


class Server {
public:
    Server(int port);
    void start();
    void stop();

private:
    int port;
    int serverSocket;

    void handleClient(int clientSocket);
    int calc(int arg1, const char op, int arg2) const ;
};


#endif //REVERSITEST_SERVER_H
