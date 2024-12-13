#ifndef TASK2_MATRIXPROXY_H
#define TASK2_MATRIXPROXY_H

#include <vector>
#include <cassert>

class MatrixProxy {
private:
    std::vector<std::vector<bool>>& matrix;
public:
    explicit MatrixProxy(std::vector<std::vector<bool>>& matrixRef) : matrix(matrixRef) {}
    std::vector<bool>::reference at(size_t x, size_t y);
    [[nodiscard]] bool at(size_t x, size_t y) const;
};

#endif
