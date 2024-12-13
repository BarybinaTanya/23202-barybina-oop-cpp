#include "GameState.h"

void GameState::initializeDefaultState() {
    matrix.resize(heightY, std::vector<bool>(widthX, false));
    size_t centerX = widthX / 2;
    size_t centerY = heightY / 2;

    // easy spaceship
    matrix[(centerY + 1) % heightY][(centerX) % widthX] = true;
    matrix[(centerY) % heightY][(centerX + 1) % widthX] = true;
    matrix[(centerY - 1) % heightY][(centerX - 1) % widthX] = true;
    matrix[(centerY - 1) % heightY][(centerX) % widthX] = true;
    matrix[(centerY - 1) % heightY][(centerX + 1) % widthX] = true;
}

GameState::GameState(size_t width, size_t height, const std::set<int>& birth, const std::set<int>& survival) {
    widthX = width;
    heightY = height;
    birthRules = birth;
    survivalRules = survival;

    matrix.resize(height, std::vector<bool>(width, false));
}

size_t normalizedIndex(size_t index, size_t size) {
    return (index % size + size) % size;
}

void GameState::initializeState(const std::vector<std::pair<int, int>>& aliveCells) {
    // If the figure is not balanced around the center, it doesn't really matter
    // as the field is toroidal. Layering may happen only if the figure has
    // its size grater then one of window parameters.
    size_t centerX = widthX / 2;
    size_t centerY = heightY / 2;
    for (auto coordinateShift : aliveCells) {
        matrix[normalizedIndex(centerY + coordinateShift.second,heightY)]
              [normalizedIndex(centerX + coordinateShift.first,widthX)] = true;
    }
}

size_t GameState::getWidth() const {
    return widthX;
}

size_t GameState::getHeight() const {
    return heightY;
}

std::set<int> GameState::getBirthRules() const {
    return birthRules;
}

std::set<int> GameState::getSurvivalRules() const {
    return survivalRules;
}
