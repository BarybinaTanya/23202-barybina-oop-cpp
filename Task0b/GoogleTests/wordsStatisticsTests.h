#ifndef INC_0B_WORDSSTATISTICSTESTS_H
#define INC_0B_WORDSSTATISTICSTESTS_H

#include <gtest/gtest.h>
#include <fstream>
#include "../WordsStatistics.h"

TEST(WordsStatisticsTest, AddWordTest) {
    WordsStatistics stats;
    stats.addWord("Hello");
    stats.addWord("world");
    stats.addWord("hello");

    EXPECT_EQ(stats.getStatisticsByWord("hello").first, 2);
    EXPECT_EQ(stats.getStatisticsByWord("world").first, 1);
    EXPECT_FLOAT_EQ(stats.getStatisticsByWord("hello").second, 2.0f / 3.0f);
    EXPECT_FLOAT_EQ(stats.getStatisticsByWord("world").second, 1.0f / 3.0f);
}

TEST(WordsStatisticsTest, AddWordsTest) {
    WordsStatistics stats;
    std::vector<string> words = {"This", "is", "a", "test", "this", "test"};
    stats.addWords(words);

    EXPECT_EQ(stats.getStatisticsByWord("this").first, 2);
    EXPECT_EQ(stats.getStatisticsByWord("test").first, 2);
    EXPECT_EQ(stats.getStatisticsByWord("is").first, 1);
    EXPECT_FLOAT_EQ(stats.getStatisticsByWord("this").second, 2.0f / 6.0f);
    EXPECT_FLOAT_EQ(stats.getStatisticsByWord("test").second, 2.0f / 6.0f);
}

TEST(WordsStatisticsTest, GetAllWordsTest) {
    WordsStatistics stats;
    stats.addWords({"one", "two", "two", "three", "three", "three"});

    auto words = stats.getAllWords();
    EXPECT_EQ(words.size(), 3);
    EXPECT_NE(std::find(words.begin(), words.end(), "one"), words.end());
    EXPECT_NE(std::find(words.begin(), words.end(), "two"), words.end());
    EXPECT_NE(std::find(words.begin(), words.end(), "three"), words.end());
}

TEST(WordsStatisticsTest, CaseInsensitiveTest) {
    WordsStatistics stats;
    stats.addWords({"Case", "case", "CASE"});

    EXPECT_EQ(stats.getStatisticsByWord("case").first, 3);
    EXPECT_FLOAT_EQ(stats.getStatisticsByWord("case").second, 1.0f);
}

TEST(WordsStatisticsTest, GetStatisticsByWordNotFoundTest) {
    WordsStatistics stats;
    EXPECT_EQ(stats.getStatisticsByWord("nonexistent").first, 0);
    EXPECT_FLOAT_EQ(stats.getStatisticsByWord("nonexistent").second, 0.0f);
}

#endif //INC_0B_WORDSSTATISTICSTESTS_H
