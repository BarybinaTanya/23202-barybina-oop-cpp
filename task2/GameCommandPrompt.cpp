#include "GameCommandPrompt.h"
#include "GameState.h"
#include "StateCounter.h"
#include "FileHandler.h"
#include "UniverseCharacteristicsParser.h"

#include <iostream>
#include <string>
#include <vector>
#include <set>

int extractTickNumber(const std::string& command) {
    size_t pos = command.find("<n=");
    if (pos != std::string::npos) {
        size_t start = pos + 3;
        size_t end = command.find(">", start);
        if (end != std::string::npos) {
            std::string numberStr = command.substr(start, end - start);
            try {
                return std::stoi(numberStr);
            } catch (const std::invalid_argument& e) {
                std::cerr << "Invalid number format in command: " << command << std::endl;
                return 1;
            } catch (const std::out_of_range& e) {
                std::cerr << "Number out of range in command: " << command << std::endl;
                return 1;
            }
        }
    }
    return 1;
}

commandPromptStates processOnlineMode() {
    std::string inFileName;
    fileRWResults res = UNABLE_TO_OPEN_THE_FILE;
    std::vector<std::string> inLines;

    while (res != SUCCESS_READING_FILE) {
        std::cout << "Enter the name of the file with universe description: " << std::endl;
        std::cin >> inFileName;

        res = FileHandler::loadUniverseFromFile(inFileName, inLines);

        if (res == UNABLE_TO_OPEN_THE_FILE) {
            std::cout << "Unable to open the file." << std::endl;
        } else if (res == UNABLE_TO_READ_FROM_FILE) {
            std::cout << "Unable to read from the file." << std::endl;
        }
    }

    std::set<int> birthRules;
    std::set<int> survivalRules;
    if (UniverseCharacteristicsParser::parseRules(inLines[0], birthRules, survivalRules) != SUCCESS_PARSING) {
        std::cout << "Invalid rule format in the file." << std::endl;
        return MAIN_MENU;
    }

    int widthX, heightY;
    if (UniverseCharacteristicsParser::parseWindowSize(inLines[1], widthX, heightY) != SUCCESS_PARSING) {
        std::cout << "Invalid window size format in the file." << std::endl;
        return MAIN_MENU;
    }

    std::vector<std::pair<int, int>> aliveCells;
    inLines.erase(inLines.begin(), inLines.begin() + 2);
    if (UniverseCharacteristicsParser::parseAliveCells(inLines, aliveCells) != SUCCESS_PARSING) {
        std::cout << "Invalid coordinate format in the file." << std::endl;
        return MAIN_MENU;
    }

    GameState gameState(widthX, heightY, birthRules, survivalRules);
    gameState.initializeState(aliveCells);

    std::cout << "Game started!" << std::endl;
    std::string command;
    size_t iteration = 0;

    while (true) {
        std::cout << "Enter command (help for list of commands): ";
        std::cin >> command;

        if (command == "exit") {
            return MAIN_MENU;
        } else if (command == "help") {
            std::cout << "Available commands:\n";
            std::cout << " - dump <filename>: Save the universe to a file.\n";
            std::cout << " - tick <n>: Calculate n iterations (default: 1) and print the result.\n";
            std::cout << " - exit: Return to main menu.\n";
        } else if (command.substr(0, 4) == "dump") {
            std::string outputFileName = command.substr(5);
            if (FileHandler::loadFieldToFile(outputFileName, gameState) != SUCCESS_WRITING_FILE) {
                std::cout << "Failed to write to file." << std::endl;
            } else {
                std::cout << "Universe saved to " << outputFileName << std::endl;
            }
        } else if (command.substr(0, 4) == "tick") {
            size_t ticks = 1;
            if (command.size() > 5) {
                ticks = extractTickNumber(command);
            }
            for (size_t i = 0; i < ticks; ++i) {
                if (StateCounter::processGeneration(gameState) != SUCCESS_PROCESSING) {
                    std::cout << "Error during processing generation." << std::endl;
                    break;
                }
                ++iteration;
            }
            std::cout << "Iteration: " << iteration << "\n";
            std::cout << "Current Universe:\n";
            for (size_t y = 0; y < gameState.getHeight(); ++y) {
                for (size_t x = 0; x < gameState.getWidth(); ++x) {
                    std::cout << (gameState.getMatrixProxy().at(x, y) ? "O" : ".") << " ";
                }
                std::cout << "\n";
            }
        } else {
            std::cout << "Unknown command. Type 'help' for assistance." << std::endl;
        }
    }
}

commandPromptStates processOfflineMode() {
    std::string inFileName, outFileName;
    size_t iterations;

    std::cout << "Enter the input file name: ";
    std::cin >> inFileName;
    std::cout << "Enter the output file name: ";
    std::cin >> outFileName;
    std::cout << "Enter the number of iterations: ";
    std::cin >> iterations;

    std::vector<std::string> inLines;
    if (FileHandler::loadUniverseFromFile(inFileName, inLines) != SUCCESS_READING_FILE) {
        std::cout << "Failed to load universe from file." << std::endl;
        return MAIN_MENU;
    }

    std::set<int> birthRules, survivalRules;
    int widthX, heightY;
    std::vector<std::pair<int, int>> aliveCells;

    if (UniverseCharacteristicsParser::parseRules(inLines[0], birthRules, survivalRules) != SUCCESS_PARSING ||
        UniverseCharacteristicsParser::parseWindowSize(inLines[1], widthX, heightY) != SUCCESS_PARSING ||
        UniverseCharacteristicsParser::parseAliveCells(inLines, aliveCells) != SUCCESS_PARSING) {
        std::cout << "Error parsing input file." << std::endl;
        return MAIN_MENU;
    }

    GameState gameState(widthX, heightY, birthRules, survivalRules);
    gameState.initializeState(aliveCells);

    for (size_t i = 0; i < iterations; ++i) {
        if (StateCounter::processGeneration(gameState) != SUCCESS_PROCESSING) {
            std::cout << "Error during processing generation." << std::endl;
            return MAIN_MENU;
        }
    }

    if (FileHandler::loadFieldToFile(outFileName, gameState) != SUCCESS_WRITING_FILE) {
        std::cout << "Failed to save universe to file." << std::endl;
    } else {
        std::cout << "Universe saved to " << outFileName << std::endl;
    }

    return MAIN_MENU;
}

commandPromptStates processMainMenu() {
    std::string command;

    while (true) {
        std::cout << "Main menu:\n";
        std::cout << " - Type 'online mode' to play interactively.\n";
        std::cout << " - Type 'offline mode' to run in batch mode.\n";
        std::cout << " - Type 'exit' to quit the game.\n";
        std::cout << " - Type 'help' to view available commands.\n";
        std::cout << "Enter your command: ";
        std::cin >> command;

        if (command == "help") {
            std::cout << "Available commands:\n";
            std::cout << " - online_mode: Play interactively.\n";
            std::cout << " - offline_mode: Process a file and save the results.\n";
            std::cout << " - exit: Quit the game.\n";
        } else if (command == "exit") {
            return EXIT_GAME;
        } else if (command == "online_mode") {
            return processOnlineMode();
        } else if (command == "offline_mode") {
            return processOfflineMode();
        } else {
            std::cout << "Unknown command. Type 'help' for assistance." << std::endl;
        }
    }
}

void GameCommandPrompt::start() {
    commandPromptStates state = MAIN_MENU;

    while (state != EXIT_GAME) {
        state = processMainMenu();
    }

    std::cout << "Goodbye!" << std::endl;
}
