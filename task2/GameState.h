#ifndef TASK2_GAMESTATE_H
#define TASK2_GAMESTATE_H

typedef unsigned long ul;

class GameState {
private:
    ul windowWidth;
    ul windowHeight;

    bool** matrix;

public:
    GameState(ul width, ul height);
    ~GameState();
    bool** getMatrix();
    void setDefaultMatrixState();
};


#endif //TASK2_GAMESTATE_H
