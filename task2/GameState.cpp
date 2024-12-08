#include "GameState.h"

void GameState::setDefaultMatrixState() {
    ul centerX = windowX / 2;
    ul centerY = windowY / 2;

    // easy spaceship
    matrix[(centerY + 1) % windowY][(centerX) % windowX] = true;
    matrix[(centerY) % windowY][(centerX + 1) % windowX] = true;
    matrix[(centerY - 1) % windowY][(centerX - 1) % windowX] = true;
    matrix[(centerY - 1) % windowY][(centerX) % windowX] = true;
    matrix[(centerY - 1) % windowY][(centerX + 1) % windowX] = true;
}

GameState::GameState(ul width_x, ul height_y, const std::string &inRules) {
    windowX = width_x;
    windowY = height_y;
    rules = inRules;

    matrix = new bool* [windowY];
    for (int i = 0; i < windowY; ++i) {
        matrix[i] = new bool [windowX];
        for (int j = 0; j < windowX; ++j) {
            matrix[i][j] = false;
        }
    }
    if (windowX > 4 && windowY > 4) {
        this->setDefaultMatrixState();
    }
}

GameState::GameState(ul width_x, ul height_y, const std::string &inRules, std::vector<std::pair<int, int>> &aliveCells) {

    windowX = width_x;
    windowY = height_y;
    rules = inRules;

    matrix = new bool* [windowY];
    for (int i = 0; i < windowY; ++i) {
        matrix[i] = new bool [windowX];
        for (int j = 0; j < windowX; ++j) {
            matrix[i][j] = false;
        }
    }
    ul centerX = windowX / 2;
    ul centerY = windowY / 2;

    for (auto coordinateShift : aliveCells) {
        matrix[(centerY + coordinateShift.second) % windowY][(centerX + coordinateShift.first) % windowX] = true;
    }
}

GameState::~GameState() {
    for (int i = 0; i < windowY; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;
}

ul GameState::getWidth() const{
    return windowX;
}

ul GameState::getHeight() const{
    return windowY;
}

bool** GameState::getMatrix() {
    return matrix;
}
