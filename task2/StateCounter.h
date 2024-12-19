#ifndef TASK2_STATECOUNTER_H
#define TASK2_STATECOUNTER_H

#include "GameState.h"

enum processGameResults {
    EMPTY_MATRIX,
    EMPTY_RULES,
    SUCCESS_PROCESSING
};

class StateCounter {
public:
    static short processGeneration(GameState &state);
};

#endif //TASK2_STATECOUNTER_H
