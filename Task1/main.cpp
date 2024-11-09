#include <iostream>
#include <gtest/gtest.h>
#include "GoogleTests/BitArrayTests.h"

bool getBit1(unsigned long container, int n) {
    return (container >> n) & 1;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

//    unsigned long cont[] = {0b11110000, 0b00000000};
//    for (int i = 0; i < 2; ++i) {
//        for (int j = 8 - 1; j >= 0; --j) {
//            std::cout << getBit1(cont[i], j) << std::endl;
//        }
//    }

    return RUN_ALL_TESTS();
}
