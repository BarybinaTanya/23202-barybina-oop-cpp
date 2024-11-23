#include <iostream>
#include <gtest/gtest.h>
#include "GoogleTests/testFile.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}