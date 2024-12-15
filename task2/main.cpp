#include <iostream>
#include <gtest/gtest.h>
#include "GoogleTests/GameStateTests.h"
#include "GoogleTests/UniverseCharacteristicsParserTests.h"
#include "GoogleTests/StateCounterTests.h"
#include "GoogleTests/FileHandlerTests.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}