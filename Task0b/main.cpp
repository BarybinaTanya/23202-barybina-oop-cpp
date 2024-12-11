#include <iostream>
#include <gtest/gtest.h>
#include "GoogleTests/readerTests.h"
#include "GoogleTests/splitterTests.h"
#include "GoogleTests/wordsStatisticsTests.h"
#include "GoogleTests/csvFileWriterTests.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    Reader file;
    file.openFile("input1.txt");
    std::string line;
    std::vector <string> splitted;
    std::vector <string> res;
    WordsStatistics statistics;

    for (int i = 0; i < 10; ++i) {
        line = file.readLine();
        splitted = Splitter::splitLine(line);
        for (const auto& pLine : splitted) {
            res.push_back(pLine);
            statistics.addWord(pLine);
        }
    }
    std::vector <string> allWords = statistics.getAllWords();

    std::cout << "Number of words: " << statistics.getNumberWords() << std::endl;

    for (const auto& word : allWords) {
        std::cout << word << ": " << statistics.getStatisticsByWord(word).first << "  " <<
        statistics.getStatisticsByWord(word).second << std::endl;
    }
    std::cout << "_____________________________________________________________" << std::endl;
    for (const auto& elem : res) {
        std::cout << elem << std::endl;
    }

    file.closeFile();
    return RUN_ALL_TESTS();
}
