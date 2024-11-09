#ifndef TASK1_BITARRAYTESTS_H
#define TASK1_BITARRAYTESTS_H

#include <gtest/gtest.h>
#include "../BitArray.h"

#define BITS_IN_BYTE 8

bool getBit(unsigned long container, int n) {
    return (container >> n) & 1;
}

void checkArray(BitArray &myArray) {
    int num_bits_left = myArray.getNumberBits();
    int iterations_counter = 0;
    for (int i = 0; i < myArray.getNumberBlocks(); ++i) {
        for (int j = sizeof(unsigned long) * BITS_IN_BYTE - 1; j >= 0; --j) {
            EXPECT_EQ(getBit(myArray.getData()[i], j), 1);
            iterations_counter++;
            num_bits_left--;
            if (num_bits_left == 0) {
                break;
            }
        }
    }
    EXPECT_EQ(iterations_counter, 10);
}

TEST(BitArrayTest, ConstuctorAndGettersTest) {
    BitArray myArray(10, true);
    EXPECT_EQ(myArray.getNumberBits(), 10);
    EXPECT_EQ(myArray.getNumberBlocks(), 1);

    checkArray(myArray);
}

TEST(BitArrayTest, CopyConstructorTest) {
    BitArray myArray(10, true);
    BitArray array1(myArray);
    EXPECT_EQ(array1.getNumberBits(), 10);
    EXPECT_EQ(array1.getNumberBlocks(), 1);

    checkArray(array1);
}

TEST(BitArrayTest, CopyOperatorTest) {
    BitArray myArray(10, true);
    BitArray array = myArray;
    EXPECT_EQ(array.getNumberBits(), 10);
    EXPECT_EQ(array.getNumberBlocks(), 1);

    checkArray(array);
}

#endif //TASK1_BITARRAYTESTS_H
