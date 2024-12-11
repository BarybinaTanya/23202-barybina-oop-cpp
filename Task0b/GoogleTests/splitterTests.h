#ifndef INC_0B_SPLITTERTESTS_H
#define INC_0B_SPLITTERTESTS_H

#include <gtest/gtest.h>
#include <fstream>
#include "../Splitter.h"

TEST(SplitterTest, SplitLine_EmptyString) {
    Splitter splitter;
    std::vector<std::string> result = splitter.splitLine("");
    EXPECT_TRUE(result.empty());
}

TEST(SplitterTest, SplitLine_SingleWord) {
    Splitter splitter;
    std::vector<std::string> result = splitter.splitLine("Hello");
    ASSERT_EQ(result.size(), 1);
    EXPECT_EQ(result[0], "Hello");
}

TEST(SplitterTest, SplitLine_MultipleWords) {
    Splitter splitter;
    std::vector<std::string> result = splitter.splitLine("Hello world! This is a test.");
    std::vector<std::string> expected = {"Hello", "world", "This", "is", "a", "test"};
    EXPECT_EQ(result, expected);
}

TEST(SplitterTest, SplitLine_Punctuation) {
    Splitter splitter;
    std::vector<std::string> result = splitter.splitLine("Good morning, world! How are you?");
    std::vector<std::string> expected = {"Good", "morning", "world", "How", "are", "you"};
    EXPECT_EQ(result, expected);
}

TEST(SplitterTest, SplitLine_NumbersAndWords) {
    Splitter splitter;
    std::vector<std::string> result = splitter.splitLine("123 apples and 456 oranges.");
    std::vector<std::string> expected = {"123", "apples", "and", "456", "oranges"};
    EXPECT_EQ(result, expected);
}

#endif //INC_0B_SPLITTERTESTS_H
