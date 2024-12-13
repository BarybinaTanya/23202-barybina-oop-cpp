#ifndef TASK2_STATECOUNTER_H
#define TASK2_STATECOUNTER_H

#include "GameState.h"

class StateCounter {
private:
    GameState currentField;
public:
    void processGeneration(GameState &field);
};

#endif //TASK2_STATECOUNTER_H
