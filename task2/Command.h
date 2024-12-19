#ifndef TASK2_COMMAND_H
#define TASK2_COMMAND_H

class GameState;

class Command {
public:
    virtual void execute(GameState& gameState) = 0;
    virtual ~Command() = default;
};

#endif //TASK2_COMMAND_H
