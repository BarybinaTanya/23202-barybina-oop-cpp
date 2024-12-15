#ifndef TASK2_FILEHANDLER_H
#define TASK2_FILEHANDLER_H

#include <fstream>
#include <cstring>

#include "GameState.h"

enum fileRWResults{
    UNABLE_TO_OPEN_THE_FILE,
    UNABLE_TO_READ_FROM_FILE,
    SUCCESS_READING_FILE,
    SUCCESS_WRITING_FILE
};

class FileHandler {
public:
    static fileRWResults loadUniverseFromFile(std::string &inputFileName, std::vector <std::string> &input_lines);
    static fileRWResults loadFieldToFile(std::string &outputFileName, GameState &gameState);
};


#endif //TASK2_FILEHANDLER_H
