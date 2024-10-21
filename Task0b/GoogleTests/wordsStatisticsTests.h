#ifndef INC_0B_WORDSSTATISTICSTESTS_H
#define INC_0B_WORDSSTATISTICSTESTS_H

#include <gtest/gtest.h>
#include <fstream>
#include "../WordsStatistics.h"

TEST(WoersStatisticsTest, AddWordsAndGetStatisticsTest) {
    std::vector<string> test = {"Hello", "hello", "world", "Soon", "I", "will", "die"};
    WordsStatistics wordsStatistics;

    wordsStatistics.addWords(test);
    std::vector<string> stats = wordsStatistics.getStatistics();

    EXPECT_EQ(stats[0], "die,1,0.142857");
}

TEST(WoersStatisticsTest, AddWordTest) {
    WordsStatistics wordsStatistics;

    wordsStatistics.addWord("Hello");
    std::vector<string> stats = wordsStatistics.getStatistics();

    EXPECT_EQ(stats[0], "hello,1,1.000000");
}

#endif //INC_0B_WORDSSTATISTICSTESTS_H
