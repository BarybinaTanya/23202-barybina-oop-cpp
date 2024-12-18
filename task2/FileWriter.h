#ifndef TASK2_FILEWRITER_H
#define TASK2_FILEWRITER_H

#include "GameState.h"

#include <fstream>
#include <cstring>

class FileWriter {
public:
    static short loadFieldToFile(std::string &outputFileName, GameState &gameState);
};

#endif //TASK2_FILEWRITER_H
