#ifndef TASK2_FILEHANDLERTESTS_H
#define TASK2_FILEHANDLERTESTS_H

#include <gtest/gtest.h>
#include "..\FileHandler.h"
#include <fstream>

TEST(FileHandler, LoadUniverseFromFile_Success) {
    std::string inputFileName = "test_input.txt";
    std::ofstream outFile(inputFileName);
    outFile << "OOO\nO.O\nOOO\n";
    outFile.close();

    std::vector<std::string> lines;
    short result = FileHandler::loadUniverseFromFile(inputFileName, lines);

    EXPECT_EQ(result, SUCCESS_READING_FILE);
    ASSERT_EQ(lines.size(), 3);
    EXPECT_EQ(lines[0], "OOO");
    EXPECT_EQ(lines[1], "O.O");
    EXPECT_EQ(lines[2], "OOO");

    std::remove(inputFileName.c_str());
}

TEST(FileHandler, LoadFieldToFile_Success) {
    std::string outputFileName = "test_output.txt";
    GameState gameState(3, 3, {3}, {2, 3});
    gameState.initializeState({{0, 0}, {1, 1}, {-1, -1}});

    short result = FileHandler::loadFieldToFile(outputFileName, gameState);

    EXPECT_EQ(result, SUCCESS_WRITING_FILE);

    std::ifstream inFile(outputFileName);
    ASSERT_TRUE(inFile.is_open());
    std::string line;
    while (std::getline(inFile, line)) {
        std::cout << line << '\n';
    }
    inFile.close();
    SUCCEED();
}

#endif //TASK2_FILEHANDLERTESTS_H
