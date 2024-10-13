#ifndef INC_0B_WORDSSTATISTICSTESTS_H
#define INC_0B_WORDSSTATISTICSTESTS_H

#include <gtest/gtest.h>
#include <fstream>
#include "../Splitter.h"
#include "../Reader.h"
#include "../WordsStatistics.h"

void createTestFileType4 (std::string newFileName) {
    std::ofstream test_file(newFileName);
    test_file << "Everything is fine! Everything is fine!\nEverything is fine! Everything is fine!";
    test_file.close();
}

TEST(WordsStatisticsTests, GetNumberWordsContainedTest) {
    WordsStatistics wordsStatisticsGetter;
    EXPECT_EQ(wordsStatisticsGetter.getNumberWordsContained(), 0);
}

TEST(WordsStatisticsTests, GetAllKeyWordsTest) {
    createTestFileType4(splitterTestFiles[3]);
    Reader readWizard;
    readWizard.openFile(splitterTestFiles[3]);
    readWizard.readAllLines();

    Splitter splitWizard;
    splitWizard.splitText(readWizard.allLines);

    WordsStatistics wordsStatisticsGetter;
    wordsStatisticsGetter.getAllKeyWords(splitWizard.splittedText);

    EXPECT_EQ(wordsStatisticsGetter.allKeyWordsMet.size(), 3);
    //printSplittedText(wordsStatisticsGetter.allKeyWordsMet);
}

void printMap(std::map<string, std::pair<int, float>> wordsFrequencyStatistics) {
    for (const auto &pair : wordsFrequencyStatistics) {
        std::cout << pair.first << ": ("
                  << pair.second.first << ", "
                  << pair.second.second << ")"
                  << std::endl;
    }
}

TEST(WordsStatisticsTests, GetFullWordsStatisticsTest) {
    Reader readWizard;
    readWizard.openFile(splitterTestFiles[3]);
    readWizard.readAllLines();

    Splitter splitWizard;
    splitWizard.splitText(readWizard.allLines);

    WordsStatistics wordsStatisticsGetter;
    wordsStatisticsGetter.getFullFrequencyMap(splitWizard.splittedText);

    EXPECT_EQ(wordsStatisticsGetter.wordsFrequencyStatistics[wordsStatisticsGetter.allKeyWordsMet[0]].first, 4);
    EXPECT_EQ(wordsStatisticsGetter.wordsFrequencyStatistics[wordsStatisticsGetter.allKeyWordsMet[1]].first, 4);
    EXPECT_EQ(wordsStatisticsGetter.wordsFrequencyStatistics[wordsStatisticsGetter.allKeyWordsMet[2]].first, 4);
    //printMap(wordsStatisticsGetter.wordsFrequencyStatistics);
}

#endif //INC_0B_WORDSSTATISTICSTESTS_H
