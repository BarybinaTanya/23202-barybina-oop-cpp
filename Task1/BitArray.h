#ifndef TASK1_BITARRAY_H
#define TASK1_BITARRAY_H

#include <iostream>
#include "BitReference.h"

class BitArray {
private:
    unsigned long *data;
    int numberBits;
    int numberBlocks;
public:
    friend class BitReference;

    explicit BitArray(int elements_num, bool value_fill_array_with);
    ~BitArray();
    BitArray(const BitArray &another_bit_array);
    BitArray& operator=(const BitArray &another_bit_array);
    int getNumberBits();
    unsigned long* getData();
    int getNumberBlocks();
    BitReference operator[](int index);
    bool operator[](int index) const;
};


#endif //TASK1_BITARRAY_H
