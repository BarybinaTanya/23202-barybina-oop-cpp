#include "GameCommandPrompt.h"
#include "GameState.h"
#include "StateCounter.h"
#include "FileHandler.h"
#include "UniverseCharacteristicsParser.h"



commandPromptStates processOnlineMode() {
    std::string inFileName;
    fileRWResults res = UNABLE_TO_OPEN_THE_FILE;
    std::vector<std::string> inLines;
    while (res != SUCCESS_READING_FILE) {
        std::cout << "print name of the file with universe description" << std::endl;
        std::cin >> inFileName;

        res = FileHandler::loadUniverseFromFile(inFileName, inLines);

        if (res == UNABLE_TO_OPEN_THE_FILE) {
            std::cout << "Unable to open the file" << std::endl;
        } else if (res == UNABLE_TO_READ_FROM_FILE) {
            std::cout << "Unable to read from file" << std::endl;
        }
    }
    std::cout << "Game started!" << std::endl;
    std::string command;
    while (true) {
        std::cin >> command;
        if (command == "exit") {
            return OFFLINE_MODE;
        }
        else if (command == "help") {

        }
        else if (command.substr(0, 4) == "tick") {

        }
        else if (command.substr(0, 4) == "dump") {

        }
    }


//    std::set<int> birthRules;
//    std::set<int> survivalRules;
//    UniverseCharacteristicsParser::parseRules(inLines[0], birthRules, survivalRules);
//
//    size_t widthX;
//    size_t heightY;
//    UniverseCharacteristicsParser::parseWindowSize(inLines[1], widthX, heightY);
//
//    inLines.erase(inLines.begin());
//    inLines.erase(inLines.begin());


}

commandPromptStates processNonMode() {

}

commandPromptStates processOfflineMode() {

}

commandPromptStates processMainMenu() {
    std::string mainMenuCommand;
    std::cin >> mainMenuCommand;
    while (true) {
        if (mainMenuCommand == "help") {

        }
        else if (mainMenuCommand == "exit game") {
            return EXIT_GAME;
        }
        else if (mainMenuCommand == "non mode") {
            return NON_MODE;
        }
        else if (mainMenuCommand == "online mode") {
            int OnlineModeRes = processOnlineMode();
            return ONLINE_MODE;
        }
        else if (mainMenuCommand == "offline mode") {
            return OFFLINE_MODE;
        }
        else {
            std::cout << "Unknown command!" << std::endl;
        }
    }
}

void GameCommandPrompt::start() {
    commandPromptStates state = MAIN_MENU;
    while (true) {
        std::cout << "Hello! You are in the Life Game (main menu)! Print \"Help\" "
                     "if you need more information about commands and file formats ;)";
        state = processMainMenu();
        if (state == EXIT_GAME) {
            break;
        }
    }
}