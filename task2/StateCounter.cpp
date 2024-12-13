#include "StateCounter.h"

using namespace std;

enum results {
    EMPTY_MATRIX,
    EMPTY_RULES,
    SUCCESS
};

short countNeighbors(GameState &state, size_t x, size_t y) {
    short neighborsCount = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) {
                continue;
            }
            if (state.getMatrixProxy().at(x + i, y + j)) {
                neighborsCount++;
            }
        }
    }
    return neighborsCount;
}

bool shouldStayAlive(short neighborsNumber, const std::set<int> &survivalRules) {
    for (auto const &number : survivalRules) {
        if (neighborsNumber == number) {
            return true;
        }
    }
    return false;
}

bool shouldBorn(short neighborsNumber, const std::set<int> &birthRules) {
    for (auto const &number : birthRules) {
        if (neighborsNumber == number) {
            return true;
        }
    }
    return false;
}

short StateCounter::processGeneration(GameState &state) {
    size_t widthX = state.getWidth();
    size_t heightY = state.getHeight();

    if (widthX == 0 || heightY == 0) {
        return EMPTY_MATRIX;
    }

    std::set<int> survivalRules = state.getSurvivalRules();
    std::set<int> birthRules = state.getBirthRules();

    if (survivalRules.empty() || birthRules.empty()) {
        return EMPTY_RULES;
    }

    GameState newState(widthX, heightY, birthRules, survivalRules);

    short neighborsNumber;
    for (size_t y = 0; y < heightY; ++y) {
        for (size_t x = 0; x < widthX; ++x) {
            neighborsNumber = countNeighbors(state, x, y);

            if (state.getMatrixProxy().at(x, y) && shouldStayAlive(neighborsNumber, survivalRules)) {
                newState.getMatrixProxy().at(x, y) = true;
            }
            else if (!state.getMatrixProxy().at(x, y) && shouldBorn(neighborsNumber, birthRules)) {
                newState.getMatrixProxy().at(x, y) = true;
            }

        }
    }
    state = newState;
    return SUCCESS;
}

