#ifndef TASK1_BITARRAYTESTS_H
#define TASK1_BITARRAYTESTS_H

#include <gtest/gtest.h>
#include "../BitArray.h"
#include "../BitReference.h"

#define BITS_IN_BYTE 8

TEST(BitArrayTest, DefaultConstuctorTest) {
    BitArray array;
    EXPECT_EQ(array.getNumberBlocks(), 1);
    EXPECT_EQ(array.getNumberBits(), sizeof(unsigned long) * BITS_IN_BYTE);
}

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

void printArray(BitArray array) {
    int num_bits_left1 = array.getNumberBits();
    for (int i = 0; i < array.getNumberBlocks(); ++i) {
        for (int j = sizeof(unsigned long) * BITS_IN_BYTE - 1; j >= 0; --j) {
            std::cout << "block " << i << " " << (sizeof(unsigned long) * BITS_IN_BYTE) - j - 1 << ": " <<
                      getBit(array.getData()[i], j) << std::endl;
            num_bits_left1--;
            if (num_bits_left1 == 0) {
                break;
            }
        }
    }
    std::cout << "\n\n" << std::endl;
}

TEST(BitArrayTest, ElementValueAssignmentComplexOperatorTest) {
    BitArray myArray(10, true);

    myArray[5] = false;
    myArray[0] = false;
    myArray[9] = false;

    //printArray(myArray);

    EXPECT_EQ(myArray[0], false);


    BitArray array(100, false);
    array[5] = true;
    array[0] = true;
    array[67] = true;

    //printArray(array);

    BitArray array1(1000, false);
    array1[0] = true;
    EXPECT_EQ(array1[0], true);
    array1[2] = true;
    EXPECT_EQ(array1[2], true);
    array1[96] = true;
    EXPECT_EQ(array1[96], true);
    array1[129] = true;
    EXPECT_EQ(array1[129], true);
    array1[130] = true;
    EXPECT_EQ(array1[130], true);

    for (int i = 132; i < 150; ++i) {
        array1[i] = true;
    }

    //printArray(array1);
}

TEST(BitArrayTest, ResizeTest) {
    BitArray array(10, true);
    array.resize(15, false);
    //printArray(array);
    EXPECT_EQ(array.getNumberBlocks(), 1);
    EXPECT_EQ(array.getNumberBits(), 15);
    EXPECT_EQ(array[9] ,1);
    EXPECT_EQ(array[10] ,0);

    array.resize(9);
    //printArray(array);

    array.resize(62, false);
    //printArray(array);
}

TEST(BitArrayTest, SwapTest) {
    BitArray array1(10, true);
    BitArray array2(65, false);
    array1.swap(array2);
    //printArray(array2);
    //printArray(array1);
    EXPECT_EQ(array2.getNumberBits(), 10);
    EXPECT_EQ(array2.getNumberBlocks(), 1);

    EXPECT_EQ(array1.getNumberBits(), 65);
    EXPECT_EQ(array1.getNumberBlocks(), (65 + (sizeof(unsigned long) * BITS_IN_BYTE - 1)) /
    (sizeof(unsigned long) * BITS_IN_BYTE));
}

#endif //TASK1_BITARRAYTESTS_H
