// Created by ben-hodadov on 28/11/17.
//
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../src/Game.h"

TEST(ClassDeclaration, gameTest1) {
    HumanPlayer A('X');
    AIPlayer B('O');
    Player *p1 = &A;
    Player *p2 = &B;
    Game g(p1, p2);
    SUCCEED();// if no error been thrown, the game assembly is ok
}