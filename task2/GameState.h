#ifndef TASK2_GAMESTATE_H
#define TASK2_GAMESTATE_H

#include <iostream>
#include <cstring>
#include <vector>
#include <set>

class GameState {
private:
    size_t widthX, heightY;
    std::vector<std::vector<bool>> matrix;
    std::set<int> birthRules;
    std::set<int> survivalRules;

    void initializeDefaultState();

public:
    GameState(size_t width, size_t height, const std::set<int>& birth, const std::set<int>& survival);
    void setAliveCells(const std::vector<std::pair<int, int>>& aliveCells);

    [[nodiscard]] size_t getWidth() const;
    [[nodiscard]] size_t getHeight() const;
    std::vector<std::vector<bool>>& getMatrix();
};

#endif //TASK2_GAMESTATE_H
