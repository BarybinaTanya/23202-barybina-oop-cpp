#ifndef TASK1_BITREFERENCE_H
#define TASK1_BITREFERENCE_H

#include <iostream>

class BitReference {
private:
    unsigned long &blockRef;
    unsigned long bitIndex;
public:
    BitReference(unsigned long &block_reference, int bit_index) : blockRef(block_reference), bitIndex(bit_index) {};
    BitReference& operator=(bool value);
    operator bool() const;
};

#endif //TASK1_BITREFERENCE_H
