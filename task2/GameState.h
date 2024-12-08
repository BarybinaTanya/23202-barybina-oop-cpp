#ifndef TASK2_GAMESTATE_H
#define TASK2_GAMESTATE_H

#include <iostream>
#include <xstring>
#include <vector>

typedef unsigned long ul;

class GameState {
private:
    ul windowX;
    ul windowY;
    std::string rules;
    bool** matrix;

    void setDefaultMatrixState();

public:
    GameState(ul width_x, ul height_y, const std::string &inRules);
    GameState(ul width_x, ul height_y, const std::string &inRules, std::vector<std::pair<int, int>> &aliveCells);
    ~GameState();
    //void updateGameState();

    [[nodiscard]] ul getWidth() const;
    [[nodiscard]] ul getHeight() const;
    bool** getMatrix();
};


#endif //TASK2_GAMESTATE_H
