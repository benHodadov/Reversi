//
// Created by ben-hodadov on 28/11/17.
//
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../src/Client/Board.h"

TEST(ClassDeclaration, boardTest1) {
    Board b;
    ASSERT_EQ(b.getsize(), LENGTH);
}

TEST (ClassDeclaration, boardTest2) {
    Board b;
    ASSERT_EQ(b.getSide(LENGTH/2, LENGTH/2), 'O');
    ASSERT_EQ(b.getSide(LENGTH/2, LENGTH/2 + 1), 'X');
    ASSERT_EQ(b.getSide(LENGTH/2 + 1, LENGTH/2), 'X');
    ASSERT_EQ(b.getSide(LENGTH/2 + 1, LENGTH/2 + 1), 'O');
}