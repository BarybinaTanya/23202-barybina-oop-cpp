#include "BitArray.h"

BitArray::BitArray (int elements_num, bool value_fill_array_with) {
    if (elements_num <= 0) {
        throw std::invalid_argument("Number of elements must be positive.");
    }

    numberBits = elements_num;
    numberBlocks = (numberBits + 63) / 64;

    data = new unsigned long[numberBlocks];

    unsigned long mask_value;
    if (value_fill_array_with == 0) {
        mask_value = 0;
    } else {
        mask_value = ~0UL;
    }

    for (int i = 0; i < numberBlocks; ++i) {
        data[i] = mask_value;
    }
}

BitArray::~BitArray() {
    delete[] data;
}

BitArray::BitArray(const BitArray &another_bit_array) {
    numberBits = another_bit_array.numberBits;
    numberBlocks = another_bit_array.numberBlocks;

    data = new unsigned long[numberBlocks];

    for (int i = 0; i < numberBlocks; ++i) {
        data[i] = another_bit_array.data[i];
    }
}

int BitArray::getNumberBits() {
    return numberBits;
}

unsigned long* BitArray::getData() {
    return data;
}

int BitArray::getNumberBlocks() {
    return numberBlocks;
}