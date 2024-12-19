#include "MatrixProxy.h"
#include <cmath>

int normalizeIndex1(int index, int size) {
    return (abs(index)) % size;
}

std::vector<bool>::reference MatrixProxy::at(int x, int y) {
    assert(!matrix.empty() && "Matrix cannot be empty");
    assert(!matrix[0].empty() && "Matrix rows cannot be empty");

    return matrix[normalizeIndex1(matrix.size() - y - 1, matrix.size())]
    [normalizeIndex1(x, matrix[0].size())];
}

[[nodiscard]] bool MatrixProxy::at(int x, int y) const {
    assert(!matrix.empty() && "Matrix cannot be empty");
    assert(!matrix[0].empty() && "Matrix rows cannot be empty");

    return matrix[normalizeIndex1(matrix.size() - y - 1, matrix.size())]
    [normalizeIndex1(x, matrix[0].size())];
}
