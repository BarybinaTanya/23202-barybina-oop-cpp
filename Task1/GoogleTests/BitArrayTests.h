#ifndef TASK1_BITARRAYTESTS_H
#define TASK1_BITARRAYTESTS_H

#include <gtest/gtest.h>
#include "../BitArray.h"
#include "../BitReference.h"

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

TEST(BitArrayTest, ElementValueAssignmentComplexOperatorTest) {
    BitArray myArray(10, true);

    myArray[5] = false;
    myArray[0] = false;
    myArray[9] = false;

    int num_bits_left = myArray.getNumberBits();
    for (int i = 0; i < myArray.getNumberBlocks(); ++i) {
        for (int j = sizeof(unsigned long) * BITS_IN_BYTE - 1; j >= 0; --j) {
            std::cout << 32 - j - 1 << ": " << getBit(myArray.getData()[i], j) << std::endl;
            num_bits_left--;
            if (num_bits_left == 0) {
                break;
            }
        }
    }

    EXPECT_EQ(1, 1);

    BitArray array(100, false);
    array[5] = true;
    array[0] = true;
    array[67] = true;

    int num_bits_left1 = array.getNumberBits();
    for (int i = 0; i < array.getNumberBlocks(); ++i) {
        for (int j = sizeof(unsigned long) * BITS_IN_BYTE - 1; j >= 0; --j) {
            std::cout << "block " << i << " " << 32 - j - 1 << ": " << getBit(array.getData()[i], j) << std::endl;
            num_bits_left1--;
            if (num_bits_left1 == 0) {
                break;
            }
        }
    }
}

#endif //TASK1_BITARRAYTESTS_H
