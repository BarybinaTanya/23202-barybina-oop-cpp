#include "BitReference.h"
#define NUMBER_BITS_IN_BYTE 8

BitReference& BitReference::operator=(bool value) {
    if (value) {
        blockRef |= (1UL << ((sizeof(unsigned long) * NUMBER_BITS_IN_BYTE) - 1 - bitIndex));
    } else {
        blockRef &= ~(1UL << ((sizeof(unsigned long) * NUMBER_BITS_IN_BYTE) - 1 - bitIndex));
    }
    return *this;
}