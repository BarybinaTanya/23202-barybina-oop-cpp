#ifndef INC_0B_SPLITTERTESTS_H
#define INC_0B_SPLITTERTESTS_H

#include <gtest/gtest.h>
#include <fstream>
#include "../Splitter.h"

TEST(SplitterTests, AddDelimiterTest) {
    Splitter splitWizard;
    splitWizard.addDelimiter("__");
    splitWizard.addDelimiter("++");
    EXPECT_EQ(splitWizard.getDelimiters(), "__|\\+\\+");
}

TEST(SplitterTest, GetDelimitersTest) {
    Splitter splitter;
    EXPECT_EQ(splitter.getDelimiters(), "");
}

TEST(SplitterTest, RemoveDelimiterTest) {
    Splitter splitter;
    splitter.removeDelimiter("!");
    EXPECT_EQ(splitter.getDelimiters(), " |\\n|;|\\.|:|,|\\\"|\\?");
}

TEST(SplitterTest, RemoveAllDelimitersTest) {
    Splitter splitter;
    splitter.removeAllDelimiters();
    EXPECT_EQ(splitter.getDelimiters().size(), 0);
}

TEST(SplitterTest, SplitLineTest) {
    Splitter splitter;
    int print_it = 0;
    std::vector<string> splitted_line = splitter.splitLine("I want to code! Math, please, let me code!");
    EXPECT_EQ(splitted_line.size(), 9);
    while (print_it < splitted_line.size()) {
        std::cout << splitted_line[print_it] << std::endl;
        print_it++;
    }
}

#endif //INC_0B_SPLITTERTESTS_H
