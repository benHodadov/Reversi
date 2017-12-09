/*
 * Game.cpp
 *
 *  Created on: Nov 5, 2017
 *      Author: barak and ben
 */

#include "Game.h"
#include "RemotePlayer.h"
#include "LocalPlayer.h"


Game::Game(Player* _p1, Player* _p2):b(), gl() {
	// TODO Auto-generated constructor stubs
    p1 = _p1;
    p2 = _p2;
}

void Game::run() {
    // a message to the player when he/she starts th game
    cout << "Start game:" << endl;
    cout << "player1: " << p1->getSign() << ", player2: " << p2->getSign() << endl << "***********************" << endl;
    Player *playing = p1;

    while (!gl.endGame(b, *p1, *p2)) { // while the game isn't done
        playing->playOneTurn(gl, &b); // play
        playing = otherPlayer(playing); // change turn
    }
    p1->endGame(); // end the game
    p2->endGame();
    b.print(); // print the final board
    gl.findWinner(b, *p1, *p2); //finds the winner and prints a message
}

Player* Game::otherPlayer(Player* p) {
    //gets a player and returns the other one
	if (p->getSign() == p1->getSign()) {
		return p2;
	} else if (p->getSign() == p2->getSign()) {
        return p1;
    } else {
        cout << "error";
        return NULL;
    }
}
