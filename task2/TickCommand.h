#ifndef TASK2_TICKCOMMAND_H
#define TASK2_TICKCOMMAND_H

#include "Command.h"
#include "GameState.h"
#include "StateCounter.h"
#include <iostream>

class TickCommand : public Command {
    size_t ticks;

public:
    TickCommand(size_t ticks = 1) : ticks(ticks) {}

    void execute(GameState& gameState) override {
        for (size_t i = 0; i < ticks; ++i) {
            if (StateCounter::processGeneration(gameState) != SUCCESS_PROCESSING) {
                std::cout << "Error during processing generation.\n";
                return;
            }
        }
        std::cout << "Completed " << ticks << " tick(s).\n";
        std::cout << "Current Universe:\n";
        for (size_t y = 0; y < gameState.getHeight(); ++y) {
            for (size_t x = 0; x < gameState.getWidth(); ++x) {
                std::cout << (gameState.getMatrixProxy().at(x, y) ? "O" : ".") << " ";
            }
        }
    }
};

#endif //TASK2_TICKCOMMAND_H
