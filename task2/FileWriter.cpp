#include "FileWriter.h"

short FileWriter::loadFieldToFile(std::string &outputFileName, GameState &gameState) {
    std::ofstream outFile;
    outFile.open(outputFileName);

    if (!(outFile.is_open())) {
        return -1;
    }

    for (int y = 0; y < gameState.getWidth(); ++y) {
        for (int x = 0; x < gameState.getHeight(); ++x) {
            outFile << (gameState.getMatrixProxy().at(x, y) ? "O" : ".") << " ";
        }
        outFile << '\n';
    }
    outFile << '\n';
    outFile.close();
    return 0;
}