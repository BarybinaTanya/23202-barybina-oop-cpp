#include "BitArray.h"
#define BITS_IN_BYTE 8

BitArray::BitArray() {
    numberBlocks = 1;
    numberBits = sizeof(unsigned long) * BITS_IN_BYTE; // 32 or 64 bits depending on compiler
    data = new unsigned long[numberBlocks];
    data[0] = 0; // Filled all bits with 0;
}

BitArray::~BitArray() {
    delete[] data;
}

BitArray::BitArray (int elements_num, bool value_fill_array_with) {
    if (elements_num <= 0) {
        throw std::invalid_argument("Number of elements must be positive.");
    }

    numberBits = elements_num;
    numberBlocks = (numberBits + (sizeof(unsigned long) * BITS_IN_BYTE - 1)) /
                   (sizeof(unsigned long) * BITS_IN_BYTE);

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
    if (index >= numberBits) {
        throw std::invalid_argument("Index is out of range");
    } // This is VERY important part of the class. It makes our bit array contain exactly numberBits elements and
    // work like regular array.
    unsigned long block_number = index / (sizeof(unsigned long) * BITS_IN_BYTE);
    unsigned long &block_ref = data[block_number];
    int bit_index = index % (sizeof(unsigned long) * BITS_IN_BYTE);
    return BitReference(block_ref, bit_index);
}

void BitArray::resizeLogic(int num_bits, bool value) {
    if (num_bits < 0) {
        throw std::invalid_argument("num_bits must be non-negative");
    }

    if (numberBits == num_bits) {
        return;
    }
    else if (numberBits > num_bits) {
        int old_num_blocks = numberBlocks;
        int new_num_blocks = (num_bits + (sizeof(unsigned long) * BITS_IN_BYTE - 1)) /
                             (sizeof(unsigned long) * BITS_IN_BYTE);

        if (new_num_blocks < old_num_blocks) {
            BitArray copy = *this;

            numberBits = num_bits;
            numberBlocks = new_num_blocks;

            delete[] data; // reallocate
            data = new unsigned long[new_num_blocks];

            for (int block = 0; block < numberBlocks; ++block) {
                data[block] = copy.data[block];
            }
            return;
        } else { // new_num_blocks = old_num_blocks
            numberBits = num_bits;
        }
    }
    else { // num_bits > numberBits
        int old_num_blocks = numberBlocks;
        int new_num_blocks = (num_bits + (sizeof(unsigned long) * BITS_IN_BYTE - 1)) /
                             (sizeof(unsigned long) * BITS_IN_BYTE);

        if (new_num_blocks > old_num_blocks) {
            BitArray copy = *this;

            numberBits = num_bits;
            numberBlocks = new_num_blocks;

            delete[] data; // reallocate
            data = new unsigned long[new_num_blocks];

            for (int block = 0; block < new_num_blocks; ++block) {
                if (block < old_num_blocks) {
                    data[block] = copy.data[block];
                } else {
                    data[block] = 0; // will put correct value here later. It's just initialization.
                }
            }

            int position = copy.numberBits;
            while (position < numberBits) {
                (*this)[position] = value;
                position++;
            }
            return;
        } else { // new_num_blocks = old_num_blocks
            int position = numberBits;
            numberBits = num_bits;

            while (position < numberBits) {
                (*this)[position] = value;
                position++;
            }
            return;
        }
    }
}

void BitArray::resize(int num_bits, bool value) {
    resizeLogic(num_bits, value);
}

void BitArray::resize(int num_bits) {
    resizeLogic(num_bits, false);
}

void BitArray::swap(BitArray& another_array) {
    BitArray copy = *this;
    (*this) = another_array;
    another_array = copy;
}


