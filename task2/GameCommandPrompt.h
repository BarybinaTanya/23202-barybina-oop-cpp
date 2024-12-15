#ifndef TASK2_GAMECOMMANDPROMPT_H
#define TASK2_GAMECOMMANDPROMPT_H

#include <map>
#include <string>
#include <fstream>

enum commandPromptStates {
    MAIN_MENU,
    NON_MODE,
    OFFLINE_MODE,
    ONLINE_MODE,
    EXIT_GAME
};

class GameCommandPrompt {
public:
    static void start();
};

#endif //TASK2_GAMECOMMANDPROMPT_H
