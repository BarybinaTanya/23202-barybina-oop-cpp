#ifndef TASK2_GAMESTATETESTS_H
#define TASK2_GAMESTATETESTS_H

#include <gtest/gtest.h>
#include "GameState.h"

TEST(GameStateTests, ConstructorDestructorTest) {
    auto* field = new GameState(100, 100);
    EXPECT_EQ(field->getMatrix()[0][0], false);
    delete field;
    SUCCEED();
}



#endif
