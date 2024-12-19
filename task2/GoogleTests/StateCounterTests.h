#ifndef TASK2_STATECOUNTERTESTS_H
#define TASK2_STATECOUNTERTESTS_H

#include <gtest/gtest.h>
#include "..\StateCounter.h"

TEST(StateCounterTest, RegularRulesTest) {
    GameState state(15, 10, {3}, {2,3});

    state.initializeDefaultState();
    printMatrix(state);

    StateCounter::processGeneration(state);
    printMatrix(state);

    StateCounter::processGeneration(state);
    printMatrix(state);

    std::vector<std::pair<int, int>> aliveCellsArr = {{-5,-5}, {-4,-5}, {-4,-4}, {-5,-4}};
    state.initializeState(aliveCellsArr);
    printMatrix(state);

    StateCounter::processGeneration(state);
    printMatrix(state);

    StateCounter::processGeneration(state);
    printMatrix(state);
    SUCCEED();
}

#endif //TASK2_STATECOUNTERTESTS_H
