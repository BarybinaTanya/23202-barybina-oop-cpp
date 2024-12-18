#ifndef TASK2_DUMPCOMMAND_H
#define TASK2_DUMPCOMMAND_H

#include "UniverseConfig.h"
#include "Command.h"
#include "FileWriter.h"
#include "Reader.h"
#include "GameState.h"
#include <string>
#include <iostream>

class DumpCommand : public Command {
    std::string filename;

public:
    DumpCommand(const std::string& filename) : filename(filename) {}

    void execute(GameState& gameState) override {
        if (FileWriter::loadFieldToFile(filename, gameState) != 0) {
            std::cout << "Failed to write to file: " << filename << "\n";
        } else {
            std::cout << "Universe saved to " << filename << "\n";
        }
    }
};

#endif //TASK2_DUMPCOMMAND_H
