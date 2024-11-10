#ifndef TASK1_BITARRAY_H
#define TASK1_BITARRAY_H

#include <iostream>
#include "BitReference.h"

class BitArray {
private:
    unsigned long *data;
    int numberBits;
    int numberBlocks;

    void resizeLogic(int num_bits, bool value);
public:
    BitArray();
    ~BitArray();
    explicit BitArray(int elements_num, bool value_fill_array_with);
    BitArray(const BitArray &anotherBitArray);
    void swap(BitArray& anotherBitArray);
    BitArray& operator=(const BitArray &anotherBitArray);

    void resize(int num_bits, bool value);
    void resize(int num_bits);

    void clear();
    void pushBack(bool bit);

    BitArray& operator&=(const BitArray& anotherBitArray);
    BitArray& operator|=(const BitArray& anotherBitArray);
    BitArray& operator^=(const BitArray& anotherBitArray);

    BitArray& operator<<=(int n);
    BitArray& operator>>=(int n);
    BitArray operator<<(int n) const;
    BitArray operator>>(int n) const;

    BitArray& setAllTrue();
    BitArray& setAllFalse();

    bool any() const;
    bool none() const;

    BitArray operator~() const;

    int count() const;
    int size() const;
    bool empty() const;

    std::string to_string() const;

    int getNumberBits();
    unsigned long* getData();
    int getNumberBlocks();
    BitReference operator[](int index) const;

    friend bool operator==(const BitArray & a, const BitArray & b);
    friend bool operator!=(const BitArray & a, const BitArray & b);

    friend BitArray operator&(const BitArray& b1, const BitArray& b2);
    friend BitArray operator|(const BitArray& b1, const BitArray& b2);
    friend BitArray operator^(const BitArray& b1, const BitArray& b2);
};

#endif //TASK1_BITARRAY_H
