#ifndef INC_0B_WORDSSTATISTICSTESTS_H
#define INC_0B_WORDSSTATISTICSTESTS_H

#include <gtest/gtest.h>
#include <fstream>
#include "../WordsStatistics.h"

TEST(WordsStatisticsTest, AddWordsAndGetStatisticsByWordTest) {
    WordsStatistics statistics;
    std::vector<string> words = {"Word1", "word2", "word3"};
    statistics.addWords(words);
    std::pair<int, float> res = statistics.getStatisticsByWord("word2");
    EXPECT_EQ(res.first, 1);
}

TEST(WordsStatisticsTest, AddWordTest) {
    WordsStatistics statistics;
    std::vector<string> words = {"Word1", "word2", "word3"};
    statistics.addWords(words);
    statistics.addWord("bla");
    std::pair<int, float> res = statistics.getStatisticsByWord("bla");
    EXPECT_EQ(res.first, 1);
}

TEST(WordsStatisticsTest, GetAllWordsTest) {
    WordsStatistics statistics;
    std::vector<string> words = {"Word1", "word2", "word3", "word2"};
    statistics.addWords(words);
    std::vector<string> res;
    res = statistics.getAllWords();
    EXPECT_EQ(res.size(), 3);
}

#endif //INC_0B_WORDSSTATISTICSTESTS_H
