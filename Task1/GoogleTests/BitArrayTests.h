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

TEST(BitArrayTest, PushBackTest) {
    BitArray array(10, true);
    array.pushBack(false);
    array.pushBack(false);
    //printArray(array);
}

TEST(BitArrayTest, BitANDTest) {
    BitArray array(10, true);
    BitArray array2(10, true);
    array2[5] = false;
    array &= array2;
    EXPECT_EQ(array[5], false);
    //printArray(array);
}

TEST(BitArrayTest, BitORTest) {
    BitArray array(10, true);
    BitArray array2(10, true);
    array2[5] = false;
    array |= array2;
    EXPECT_EQ(array[5], true);
    array[0] = false;
    array2[0] = false;
    array2 |= array;
    EXPECT_EQ(array[0], false);
    //printArray(array);
}

TEST(BitArrayTest, BitXORTest) {
    BitArray array(10, true);
    BitArray array2(10, true);
    array2[5] = false;
    array ^= array2;
    EXPECT_EQ(array[5], true);
    EXPECT_EQ(array[0], false);
   //printArray(array);
}

TEST(BitArrayTest, AssignBitRightShiftTest) {
    BitArray array(4, true);
    array.resize(8, false);
    //printArray(array);

    array >>= 5;
    //printArray(array);
    EXPECT_EQ(array[5], 1);
    EXPECT_EQ(array[6], 1);
    EXPECT_EQ(array[7], 1);
}

TEST(BitArrayTest, AssignBitLeftShiftTest) {
    BitArray array(4, false);
    array.resize(8, true);
    //printArray(array);

    array <<= 5;
    //printArray(array);
    EXPECT_EQ(array[0], 1);
    EXPECT_EQ(array[1], 1);
    EXPECT_EQ(array[2], 1);
}

TEST(BitArrayTest, BitLeftShiftTest) {
    BitArray array(4, false);
    array.resize(8, true);

    BitArray array1 = array << 5;
    EXPECT_EQ(array1[0], 1);
    EXPECT_EQ(array1[1], 1);
    EXPECT_EQ(array1[2], 1);
}

TEST(BitArrayTest, BitRightShiftTest) {
    BitArray array(4, true);
    array.resize(8, false);

    BitArray array1 = array >> 5;
    EXPECT_EQ(array1[5], 1);
    EXPECT_EQ(array1[6], 1);
    EXPECT_EQ(array1[7], 1);
}

TEST(BitArrayTest, ToStringTest) {
    BitArray array(4, true);
    array.resize(8, false);
    //printArray(array);

    std::string res = array.to_string();
    std::cout << res << std::endl;

    array.resize(64, true);
    std::string res2 = array.to_string();
    std::cout << res2 << std::endl;
}

TEST(BitArrayTest, EqualityOperatorTest) {
    BitArray array1(65, true);
    BitArray array2(65, true);
    EXPECT_EQ(array1 == array2, true);
}

TEST(BitArrayTest, NonEqualityOperatorTest) {
    BitArray array1(65, true);
    BitArray array2(65, false);
    EXPECT_EQ(array1 != array2, true);
}

TEST(BitArrayTest, NonAssignANDOperatorTest) {
    BitArray array(10, true);
    BitArray array2(10, true);
    array2[5] = false;
    BitArray result = array & array2;
    EXPECT_EQ(result[5], false);
}

TEST(BitArrayTest, NonAssignOROperatorTest) {
    BitArray array(10, true);
    BitArray array2(10, true);
    array2[5] = false;
    array[0] = false;
    array2[0] = false;
    BitArray result = array | array2;
    EXPECT_EQ(result[5], true);
    EXPECT_EQ(result[0], false);
}

TEST(BitArrayTest, NonAssignXOROperatorTest) {
    BitArray array(10, true);
    BitArray array2(10, true);
    array2[5] = false;
    BitArray result = array ^ array2;
    EXPECT_EQ(result[5], true);
    EXPECT_EQ(result[0], false);
}

TEST(BitArrayTest, SetAllTrueTest) {
    BitArray array(64, false);
    array.resize(100, true);
    std::cout << array.to_string() << std::endl;
    array.setAllTrue();
    std::cout << array.to_string() << std::endl;
    EXPECT_EQ(array[63], true);
}

TEST(BitArrayTest, SetAllFalseTest) {
    BitArray array(64, false);
    array.resize(100, true);
    std::cout << array.to_string() << std::endl;
    array.setAllFalse();
    std::cout << array.to_string() << std::endl;
    EXPECT_EQ(array[86], false);
}

TEST(BitArrayTest, AnyTest) {
    BitArray array(64, false);
    EXPECT_EQ(array.any(), false);
    array[0] = true;
    EXPECT_EQ(array.any(), true);
}

TEST(BitArrayTest, NoneTest) {
    BitArray array(64, false);
    EXPECT_EQ(array.none(), true);
    array[0] = true;
    EXPECT_EQ(array.none(), false);
}

TEST(BitArrayTest, TildaOperatorTest) {
    BitArray array(4, true);
    array.resize(8, false);
    std::cout << array.to_string() << std::endl;
    EXPECT_EQ(array[0], true);
    array = (~array);
    EXPECT_EQ(array[0], false);
    std::cout << array.to_string() << std::endl;
}

TEST(BitArrayTest, CountTest) {
    BitArray array(4, true);
    array.resize(8, false);
    EXPECT_EQ(array.count(), 4);
}

TEST(BitArrayTest, ClearTest) {
    BitArray array(4, true);
    array.clear();
    EXPECT_EQ(array.getNumberBits(), 0);
    EXPECT_EQ(array.getNumberBlocks(), 0);
}

TEST(BitArrayTest, EmptyTest) {
    BitArray array;
    array.clear();
    EXPECT_EQ(array.empty(), true);
}

#endif //TASK1_BITARRAYTESTS_H
