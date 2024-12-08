#ifndef TASK2_GAMESTATETESTS_H
#define TASK2_GAMESTATETESTS_H

#include <gtest/gtest.h>
#include "GameState.h"

TEST(GameStateTests, ConstructorDestructorBasicTest) {
    auto* field = new GameState(100, 100, "B3/S23");
    EXPECT_EQ(field->getMatrix()[0][0], false);
    delete field;
    SUCCEED();
}

void printMatrix(GameState &field) {
    for (int i = field.getHeight() - 1; i >= 0; --i) {
        for (int j = 0; j < field.getWidth(); ++j) { // To make it regular xOy.
            std::cout << field.getMatrix()[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

TEST(GameStateTests, SetDefaultAndGettersTest) {
    GameState field1(10, 10, "B3/S23");
    printMatrix(field1);
    EXPECT_EQ(field1.getMatrix()[6][5], true);
    EXPECT_EQ(field1.getMatrix()[5][6], true);
    EXPECT_EQ(field1.getMatrix()[4][6], true);
    EXPECT_EQ(field1.getMatrix()[4][5], true);
    EXPECT_EQ(field1.getMatrix()[4][4], true);
}

TEST(GameStateTests, InitFieldWithAliveCellsTest) {
    std::vector<std::pair<int, int>> aliveCells = {{1,1}, {2, 1}, {3, 1},
    {4,1},{4, 2},{4,3},{4,4},
    {3,4},{2,4},{1,4},{1,3}, {1,2},

    {-1,1},{-2,1},{-2,2},{-1,2},

    {-1,-1},{0,-2},{0,-3},{-1,-3},{-2,-3}
    };

    GameState field1(10, 10, "B3/S23", aliveCells);
    field1.getMatrix()[0][0] = true;
    printMatrix(field1);
    SUCCEED();
}

#endif
