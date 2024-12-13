#ifndef TASK2_MATRIXPROXY_H
#define TASK2_MATRIXPROXY_H

#include <vector>

size_t normalizedIndex(size_t index, size_t size) {
    return (index % size + size) % size;
}

class MatrixProxy {
private:
    std::vector<std::vector<bool>>& matrix;
public:
    explicit MatrixProxy(std::vector<std::vector<bool>>& matrixRef) : matrix(matrixRef) {}

    std::vector<bool>::reference at(size_t x, size_t y) {
        return matrix[matrix.size() - y - 1][x];
    }

    [[nodiscard]] bool at(size_t x, size_t y) const {
        return matrix[matrix.size() - y - 1][x];
    }
};

#endif
