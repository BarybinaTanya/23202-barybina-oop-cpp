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

BitArray::BitArray(const BitArray &anotherBitArray) {
    numberBits = anotherBitArray.numberBits;
    numberBlocks = anotherBitArray.numberBlocks;

    data = new unsigned long[numberBlocks];

    for (int i = 0; i < numberBlocks; ++i) {
        data[i] = anotherBitArray.data[i];
    }
}

BitArray& BitArray::operator=(const BitArray &anotherBitArray) {
    if (this == &anotherBitArray) {
        return *this;
    }
    numberBits = anotherBitArray.numberBits;
    numberBlocks = anotherBitArray.numberBlocks;

    delete[] data;
    data = new unsigned long[numberBlocks];

    for (int i = 0; i < numberBlocks; ++i) {
        data[i] = anotherBitArray.data[i];
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

BitReference BitArray::operator[](int index) const{
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

void BitArray::swap(BitArray& anotherBitArray) {
    BitArray copy = *this;
    (*this) = anotherBitArray;
    anotherBitArray = copy;
}

void BitArray::clear() {
    numberBits = 0;
    numberBlocks = 0;
    delete[] data;
    data = new unsigned long[0];
}

void BitArray::pushBack(bool bit) {
    this->resize(numberBits + 1, bit);
}

BitArray& BitArray::operator&=(const BitArray& anotherBitArray) {
    if (numberBits != anotherBitArray.numberBits) {
        perror("BitArrays have different size");
        return *this;
    }
    for (int index = 0; index < numberBits; ++index) {
        bool op_1 = (*this)[index];
        bool op_2 = anotherBitArray[index];
        bool res = op_1 && op_2;
        (*this)[index] = res;
    }
    return *this;
}

BitArray& BitArray::operator|=(const BitArray& anotherBitArray) {
    if (numberBits != anotherBitArray.numberBits) {
        perror("BitArrays have different size");
        return *this;
    }
    for (int index = 0; index < numberBits; ++index) {
        bool op_1 = (*this)[index];
        bool op_2 = anotherBitArray[index];
        bool res = op_1 || op_2;
        (*this)[index] = res;
    }
    return *this;
}

BitArray& BitArray::operator^=(const BitArray& anotherBitArray) {
    if (numberBits != anotherBitArray.numberBits) {
        perror("BitArrays have different size");
        return *this;
    }
    for (int index = 0; index < numberBits; ++index) {
        bool op_1 = (*this)[index];
        bool op_2 = anotherBitArray[index];
        bool res = op_1 ^ op_2;
        (*this)[index] = res;
    }
    return *this;
}

BitArray& BitArray::operator>>=(int n) {
    if (n <= 0) {
        perror("Use <<= for left shift");
        return *this;
    }

    if (n >= numberBits) {
        for (int index = 0; index < numberBits; ++index) {
            (*this)[index] = false;
        }
        return *this;
    }

    for (int index = 0; index < numberBits - n; ++index) {
        bool rep = (*this)[index];
        (*this)[index + n] = rep;
    }
    for (int index = 0; index < n - 1; ++index) {
        (*this)[index] = false;
    }
    return *this;
}

BitArray& BitArray::operator<<=(int n) {
    if (n <= 0) {
        perror("Use >>= for right shift");
        return *this;
    }

    if (n >= numberBits) {
        for (int index = 0; index < numberBits; ++index) {
            (*this)[index] = false;
        }
        return *this;
    }

    for (int index = n; index < numberBits; ++index) {
        bool rep = (*this)[index];
        (*this)[index - n] = rep;
    }
    for (int index = numberBits - n; index < numberBits; ++index) {
        (*this)[index] = false;
    }
    return *this;
}

BitArray BitArray::operator<<(int n) const {
    BitArray result = *this;
    result <<= n;
    return result;
}

BitArray BitArray::operator>>(int n) const {
    BitArray result = *this;
    result >>= n;
    return result;
}

std::string BitArray::to_string() const {
    std::string res;
    for (int index = 0; index < numberBits; ++index) {
        if ((*this)[index]) {
            res += '1';
        } else {
            res += '0';
        }
    }
    return res;
}

bool operator==(const BitArray &a, const BitArray &b) {
    if (a.numberBits != b.numberBits) {
        return false;
    }

    for (int i = 0; i < a.numberBlocks; ++i) {
        if (a.data[i] != b.data[i]) {
            return false;
        }
    }
    return true;
}

bool operator!=(const BitArray &a, const BitArray &b) {
    if (a.numberBits != b.numberBits) {
        return true;
    }

    for (int i = 0; i < a.numberBlocks; ++i) {
        if (a.data[i] != b.data[i]) {
            return true;
        }
    }
    return false;
}

BitArray operator&(const BitArray& a, const BitArray& b) {
    if (a.numberBits != b.numberBits) {
        perror("Arrays have different size");
    }
    BitArray result(a.numberBits, false);
    for (int index = 0; index < a.numberBits; ++index) {
        bool res_1 = a[index];
        bool res_2 = b[index];
        result[index] = res_1 && res_2;
    }
    return result;
}

BitArray operator|(const BitArray& a, const BitArray& b) {
    if (a.numberBits != b.numberBits) {
        perror("Arrays have different size");
    }
    BitArray result(a.numberBits, false);
    for (int index = 0; index < a.numberBits; ++index) {
        bool res_1 = a[index];
        bool res_2 = b[index];
        result[index] = res_1 || res_2;
    }
    return result;
}

BitArray operator^(const BitArray& a, const BitArray& b) {
    if (a.numberBits != b.numberBits) {
        perror("Arrays have different size");
    }
    BitArray result(a.numberBits, false);
    for (int index = 0; index < a.numberBits; ++index) {
        bool res_1 = a[index];
        bool res_2 = b[index];
        result[index] = res_1 ^ res_2;
    }
    return result;
}

BitArray& BitArray::setAllTrue() {
    for (int index = 0; index < numberBits; ++index) {
        (*this)[index] = true;
    }
    return *this;
}

BitArray& BitArray::setAllFalse() {
    for (int index = 0; index < numberBits; ++index) {
        (*this)[index] = false;
    }
    return *this;
}

bool BitArray::any() const {
    for (int index = 0; index < numberBits; ++index) {
        if ((*this)[index]) {
            return true;
        }
    }
    return false;
}

bool BitArray::none() const {
    for (int index = 0; index < numberBits; ++index) {
        if ((*this)[index]) {
            return false;
        }
    }
    return true;
}

BitArray BitArray::operator~() const {
    for (int index = 0; index < numberBits; ++index) {
        if ((*this)[index]) {
            (*this)[index] = false;
        } else {
            (*this)[index] = true;
        }
    }
    return *this;
}

int BitArray::count() const {
    int count = 0;
    for (int index = 0; index < numberBits; ++index) {
        if ((*this)[index]) {
            count++;
        }
    }
    return count;
}

bool BitArray::empty() const {
    if (numberBits == 0) {
        return true;
    }
}
