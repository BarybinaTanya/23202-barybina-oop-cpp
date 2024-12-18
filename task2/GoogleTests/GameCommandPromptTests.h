#ifndef TASK2_GAMECOMMANDPROMPTTESTS_H
#define TASK2_GAMECOMMANDPROMPTTESTS_H

#include <gtest/gtest.h>
#include <sstream>
#include "..\GameCommandPrompt.h"

class GameCommandPromptTest : public ::testing::Test {
protected:
    std::istringstream input;
    std::ostringstream output;

    void SetUp() override {
        std::cin.rdbuf(input.rdbuf());
        std::cout.rdbuf(output.rdbuf());
    }

    void TearDown() override {
        std::cin.rdbuf(nullptr);
        std::cout.rdbuf(nullptr);
    }
};

TEST_F(GameCommandPromptTest, ExitGame) {
    input.str("exit\n");

    GameCommandPrompt gamePrompt;
    gamePrompt.start();

    std::string expectedOutput = "Goodbye!\n";
    EXPECT_NE(output.str().find(expectedOutput), std::string::npos);
}

TEST_F(GameCommandPromptTest, MainMenuHelp) {
    input.str("help\nexit\n");

    GameCommandPrompt gamePrompt;
    gamePrompt.start();

    std::string expectedOutput = "Main menu:\n"
                                 " - online_mode: Interactive mode\n"
                                 " - offline_mode: Batch mode\n"
                                 " - exit: Quit\n"
                                 "Enter your choice: ";
    EXPECT_NE(output.str().find(expectedOutput), std::string::npos);
}


#endif //TASK2_GAMECOMMANDPROMPTTESTS_H
