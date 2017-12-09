//
// Created by ben-hodadov on 06/12/17.
//

#ifndef REVERSITEST_SERVER_H
#define REVERSITEST_SERVER_H


class Server {
public:
    /**
     * Constructor method - create a new Server.
     * @param port int
     */
    Server(int port);
    /**
     * The method starts the connection to the server.
     */
    void start();

    /**
     * The method ends the connection with the server.
     */
    void stop();

private:
    int port;
    int serverSocket;

    /**
     * The function passes the move from srcSocket to destSocket.
     * Returns true if the game is over or and false otherwise.
     *
     * The protocol:
     * (0,0) if the player had no moves to play.
     * (-1,-1) if the game is over.
     *
     * @param srcSocket int
     * @param destSocket int
     * @return endGame
     */
    bool handleClient(int srcSocket, int destSocket);
};


#endif //REVERSITEST_SERVER_H
