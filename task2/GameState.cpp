#include "GameState.h"

GameState::GameState(ul width, ul height) {
    windowWidth = width;
    windowHeight = height;

    matrix = new bool* [windowHeight];
    for (int i = 0; i < windowHeight; ++i) {
        matrix[i] = new bool [windowWidth];
        for (int j = 0; j < windowWidth; ++j) {
            matrix[i][j] = false;
        }
    }
}

GameState::~GameState() {
    for (int i = 0; i < windowHeight; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;
}

bool** GameState::getMatrix() {
    return matrix;
}

void GameState::setDefaultMatrixState() {
    ul centerX = windowWidth / 2;
    ul centerY = windowHeight / 2;

    // easy spaceship
    matrix[centerY + 1][centerX] = true;
    matrix[centerY][centerX + 1] = true;
    matrix[centerY - 1][centerX - 1] = true;
    matrix[centerY - 1][centerX] = true;
    matrix[centerY - 1][centerX + 1] = true;
}
