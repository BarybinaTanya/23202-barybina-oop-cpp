#ifndef TASK2_GAMESTATETESTS_H
#define TASK2_GAMESTATETESTS_H

#include <gtest/gtest.h>
#include "..\GameState.h"

void printMatrix(GameState& gameState) {
    for (size_t y = 0; y < gameState.getHeight(); ++y) {
        for (size_t x = 0; x < gameState.getWidth(); ++x) {
            std::cout << (gameState.getMatrixProxy().at(x,y) ? "O" : ".") << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    std::cout << "\n";
}

TEST(GameStateTest, initializeDefaultStateTest) {
    GameState gameState(5, 5, {2}, {2,3});
    gameState.initializeDefaultState();

    std::cout << "Default state:\n";
    printMatrix(gameState);
    SUCCEED();
}

TEST(GameStateTest, testSetAliveCellsTest) {
    GameState gameState(5, 5, {}, {});
    gameState.initializeState({{0,  0},
                               {1,  1},
                               {2,  2},
                               {-2, -2}});

    std::cout << "State after setting alive cells:\n";
    printMatrix(gameState);
    SUCCEED();
}

TEST(GameStateTest, testToroidalWrappingTest) {
    GameState gameState(5, 5, {}, {});
    gameState.initializeState({{-1, 0},
                               {0,  0},
                               {0,  -1},
                               {0,  0}});

    std::cout << "State with toroidal wrapping:\n";
    printMatrix(gameState);
    SUCCEED();
}

#endif
