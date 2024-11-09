#include "BitArray.h"
#define NUMBER_OF_BITS_IN_BYTE 8

BitArray::BitArray (int elements_num, bool value_fill_array_with) {
    if (elements_num <= 0) {
        throw std::invalid_argument("Number of elements must be positive.");
    }

    numberBits = elements_num;
    numberBlocks = (numberBits + (sizeof(unsigned long) * NUMBER_OF_BITS_IN_BYTE - 1)) /
            (sizeof(unsigned long) * NUMBER_OF_BITS_IN_BYTE);

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

BitArray& BitArray::operator=(const BitArray &another_bit_array) {
    if (this == &another_bit_array) {
        return *this;
    }
    numberBits = another_bit_array.numberBits;
    numberBlocks = another_bit_array.numberBlocks;

    delete[] data;
    data = new unsigned long[numberBlocks];

    for (int i = 0; i < numberBlocks; ++i) {
        data[i] = another_bit_array.data[i];
    }
    return *this;
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

BitReference BitArray::operator[](int index) {
    unsigned long block_number = index / (sizeof(unsigned long) * NUMBER_OF_BITS_IN_BYTE);
    unsigned long &block_ref = data[block_number];
    int bit_index = index % (sizeof(unsigned long) * NUMBER_OF_BITS_IN_BYTE);
    return BitReference(block_ref, bit_index);
}

bool BitArray::operator[](int index) const {
    unsigned long block_number = index / (sizeof(unsigned long) * NUMBER_OF_BITS_IN_BYTE);
    int bit_index = index % (sizeof(unsigned long) * NUMBER_OF_BITS_IN_BYTE);
    return data[block_number]
}



