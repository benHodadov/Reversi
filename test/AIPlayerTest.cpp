//
// Created by ben-hodadov on 28/11/17.
//
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../src/Client/AIPlayer.h"

TEST(ClassDeclaration, AiTest1) {
    AIPlayer p1('X');
    AIPlayer p2('O');
    ASSERT_EQ(p1.getSign(), 'X');
    ASSERT_EQ(p2.getSign(), 'O');
}

TEST(ClassDeclaration, AiTest2) {
    AIPlayer p1('X');
    AIPlayer p2('O');
    Board b;
    GameLogic gl;
    ASSERT_EQ(p1.optionalMoves(b, gl).size(), 4);
    ASSERT_EQ(p2.optionalMoves(b, gl).size(), 4);
}