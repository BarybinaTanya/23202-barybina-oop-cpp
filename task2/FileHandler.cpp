#include "FileHandler.h"

fileRWResults FileHandler::loadUniverseFromFile(std::string &inputFileName, std::vector <std::string> &input_lines) {
    std::ifstream file;
    file.open(inputFileName);

    if (!(file.is_open())) {
        return UNABLE_TO_OPEN_THE_FILE;
    }

    std::string line;
    while (std::getline(file, line)) {
        input_lines.push_back(line);
    }

    if(input_lines.empty()) {
        return UNABLE_TO_READ_FROM_FILE;
    }
    return SUCCESS_READING_FILE;
}

fileRWResults FileHandler::loadFieldToFile(std::string &outputFileName, GameState &gameState) {
    std::ofstream outFile;
    outFile.open(outputFileName);

    if (!(outFile.is_open())) {
        return UNABLE_TO_OPEN_THE_FILE;
    }

    for (int y = 0; y < gameState.getWidth(); ++y) {
        for (int x = 0; x < gameState.getHeight(); ++x) {
            outFile << (gameState.getMatrixProxy().at(x, y) ? "O" : ".") << " ";
        }
        outFile << '\n';
    }
    outFile << '\n';
    outFile.close();
    return SUCCESS_WRITING_FILE;
}