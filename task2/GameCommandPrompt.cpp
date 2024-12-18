#include "GameCommandPrompt.h"
#include "GameState.h"
#include "StateCounter.h"
#include "Reader.h"
#include "UniverseCharacteristicsParser.h"
#include "TickCommand.h"
#include "DumpCommand.h"

#include <iostream>
#include <string>
#include <vector>
#include <set>

Command* parseCommand(const std::string& input) {
    if (input.substr(0, 4) == "tick") {
        size_t ticks = 1;
        if (input.size() > 5) {
            size_t start = input.find("<n=");
            size_t end = input.find(">", start);
            if (start != std::string::npos && end != std::string::npos) {
                ticks = std::stoi(input.substr(start + 3, end - start - 3));
            }
        }
        return new TickCommand(ticks);
    } else if (input.substr(0, 4) == "dump") {
        std::string filename = input.substr(5);
        return new DumpCommand(filename);
    }
    return nullptr;
}

GameState initGameState() {
    std::string inputFile;
    std::cout << "Enter the input file name: ";
    std::cin >> inputFile;

    UniverseConfig configs;
    UniverseCharacteristicsParser parser;
    configs = parser.parse(inputFile);

    GameState gameState(configs.getWidth(), configs.getHeight(),
                        configs.getBirthRules(), configs.getSurvivalRules());
    gameState.initializeState(configs.getAliveCells());
    return gameState;
}

void processOnlineMode() {
    GameState gameState = initGameState();

    std::string inputCommand;
    while (true) {
        std::cout << "Enter command: ";
        std::cin >> inputCommand;

        if (inputCommand == "exit") {
            break;
        }
        Command* command = parseCommand(inputCommand);
        if (command) {
            command->execute(gameState);
            delete command;
        }
        else {
            std::cout << "Unknown command. Use 'tick', 'dump<filename>', or 'exit'.\n";
        }
    }
}

void processOfflineMode() {
    GameState gameState = initGameState();
    size_t numberIterations;

    std::string outFileName;
    std::cout << "Enter the output file name: ";
    std::cin >> outFileName;

    std::cout << "Enter the number of iterations: ";
    std::cin >> numberIterations;

    for (size_t i = 0; i < numberIterations; ++i) {
        if (StateCounter::processGeneration(gameState) != SUCCESS_PROCESSING) {
            std::cout << "Error during processing generation.\n";
            return;
        }
    }
    FileWriter::loadFieldToFile(outFileName, gameState);
}

void mainMenu() {
    std::string command;
    while (true) {
        std::cout << "Main menu:\n";
        std::cout << " - online_mode: Interactive mode\n";
        std::cout << " - offline_mode: Batch mode\n";
        std::cout << " - exit: Quit\n";
        std::cout << "Enter your choice: ";
        std::cin >> command;

        if (command == "online_mode") {
            processOnlineMode();
        } else if (command == "offline_mode") {
            processOfflineMode(); // Аналогичная реализация для offline режима
        } else if (command == "exit") {
            break;
        } else {
            std::cout << "Unknown command. Try again.\n";
        }
    }
}

void GameCommandPrompt::start() {
    commandPromptStates state = MAIN_MENU;

    mainMenu();

    std::cout << "Goodbye!" << std::endl;
}
