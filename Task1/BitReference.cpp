#include "BitReference.h"
#define BITS_IN_BYTE 8

BitReference& BitReference::operator=(bool value) {
    if (value) {
        blockRef |= (1UL << ((sizeof(unsigned long) * BITS_IN_BYTE) - 1 - bitIndex));
    } else {
        blockRef &= ~(1UL << ((sizeof(unsigned long) * BITS_IN_BYTE) - 1 - bitIndex));
    }
    return *this;
}

BitReference::operator bool() const {
    int shift = (sizeof(unsigned long) * BITS_IN_BYTE) - bitIndex - 1;
    return (blockRef >> shift) & 1;
}

//const bool BitArray::operator[](int index) const {
//    unsigned long block_number = index / (sizeof(unsigned long) * BITS_IN_BYTE);
//    int container_index = index % (sizeof(unsigned long) * BITS_IN_BYTE);
//    int shift = (sizeof(unsigned long) * BITS_IN_BYTE) - container_index - 1;
//    return (data[block_number] >> shift) & 1;
//}