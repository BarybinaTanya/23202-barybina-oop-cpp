#include "MatrixProxy.h"

size_t normalizeIndex1(size_t index, size_t size) {
    return (index % size + size) % size;
}

std::vector<bool>::reference MatrixProxy::at(size_t x, size_t y) {
    assert(!matrix.empty() && "Matrix cannot be empty");
    assert(!matrix[0].empty() && "Matrix rows cannot be empty");

    return matrix[normalizeIndex1(matrix.size() - y - 1, matrix.size())]
    [normalizeIndex1(x, matrix[0].size())];
}

[[nodiscard]] bool MatrixProxy::at(size_t x, size_t y) const {
    assert(!matrix.empty() && "Matrix cannot be empty");
    assert(!matrix[0].empty() && "Matrix rows cannot be empty");

    return matrix[normalizeIndex1(matrix.size() - y - 1, matrix.size())]
    [normalizeIndex1(x, matrix[0].size())];
}
