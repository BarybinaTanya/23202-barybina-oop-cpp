#ifndef TASK2_RULEPARSERTESTS_H
#define TASK2_RULEPARSERTESTS_H

#include <gtest/gtest.h>
#include "..\RuleParser.h"

TEST(RuleParserTest, ValidRules) {
    std::set<int> birth, survival;
    short result = RuleParser::parseRules("#R B3/S23", birth, survival);

    EXPECT_EQ(result, RULES_PARSED);
    EXPECT_EQ(birth, (std::set<int>{3}));
    EXPECT_EQ(survival, (std::set<int>{2, 3}));
}

TEST(RuleParserTest, InvalidPrefix) {
    std::set<int> birth, survival;
    short result = RuleParser::parseRules("#X B3/S23", birth, survival);

    EXPECT_EQ(result, INVALID_RULE_FORMAT);
    EXPECT_TRUE(birth.empty());
    EXPECT_TRUE(survival.empty());
}

TEST(RuleParserTest, MissingBirth) {
    std::set<int> birth, survival;
    short result = RuleParser::parseRules("#R S23", birth, survival);

    EXPECT_EQ(result, INVALID_RULE_FORMAT);
}

TEST(RuleParserTest, MissingSurvival) {
    std::set<int> birth, survival;
    short result = RuleParser::parseRules("#R B3/", birth, survival);

    EXPECT_EQ(result, INVALID_RULE_FORMAT);
}

TEST(RuleParserTest, EmptyString) {
    std::set<int> birth, survival;
    short result = RuleParser::parseRules("", birth, survival);

    EXPECT_EQ(result, INVALID_RULE_FORMAT);
}

TEST(RuleParserTest, ValidComplexRules) {
    std::set<int> birth, survival;
    short result = RuleParser::parseRules("#R B1357/S2468", birth, survival);

    EXPECT_EQ(result, RULES_PARSED);
    EXPECT_EQ(birth, (std::set<int>{1, 3, 5, 7}));
    EXPECT_EQ(survival, (std::set<int>{2, 4, 6, 8}));
}

#endif
