#ifndef TASK1_BITARRAY_H
#define TASK1_BITARRAY_H

#include <iostream>

class BitArray {
private:
    unsigned long *data;
    int numberBits;
    int numberBlocks;
public:
    explicit BitArray(int elements_num, bool value_fill_array_with);
    ~BitArray();
    BitArray(const BitArray &another_bit_array);
    BitArray& operator=(const BitArray &another_bit_array);
    int getNumberBits();
    unsigned long* getData();
    int getNumberBlocks();

};


#endif //TASK1_BITARRAY_H
