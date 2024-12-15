#ifndef TASK2_UNIVERSECHARACTERISTICSPARSERTESTS_H
#define TASK2_UNIVERSECHARACTERISTICSPARSERTESTS_H

#include <gtest/gtest.h>
#include "..\UniverseCharacteristicsParser.h"

TEST(RuleParserTest, ValidRules) {
    std::set<int> birth, survival;
    short result = UniverseCharacteristicsParser::parseRules("#R B3/S23", birth, survival);

    EXPECT_EQ(result, SUCCESS_PARSING);
    EXPECT_EQ(birth, (std::set<int>{3}));
    EXPECT_EQ(survival, (std::set<int>{2, 3}));
}

TEST(RuleParserTest, InvalidPrefix) {
    std::set<int> birth, survival;
    short result = UniverseCharacteristicsParser::parseRules("#X B3/S23", birth, survival);

    EXPECT_EQ(result, INVALID_RULE_FORMAT);
    EXPECT_TRUE(birth.empty());
    EXPECT_TRUE(survival.empty());
}

TEST(RuleParserTest, MissingBirth) {
    std::set<int> birth, survival;
    short result = UniverseCharacteristicsParser::parseRules("#R S23", birth, survival);

    EXPECT_EQ(result, INVALID_RULE_FORMAT);
}

TEST(RuleParserTest, MissingSurvival) {
    std::set<int> birth, survival;
    short result = UniverseCharacteristicsParser::parseRules("#R B3/", birth, survival);

    EXPECT_EQ(result, INVALID_RULE_FORMAT);
}

TEST(RuleParserTest, EmptyString) {
    std::set<int> birth, survival;
    short result = UniverseCharacteristicsParser::parseRules("", birth, survival);

    EXPECT_EQ(result, INVALID_RULE_FORMAT);
}

TEST(RuleParserTest, ValidComplexRules) {
    std::set<int> birth, survival;
    short result = UniverseCharacteristicsParser::parseRules("#R B1357/S2468", birth, survival);

    EXPECT_EQ(result, SUCCESS_PARSING);
    EXPECT_EQ(birth, (std::set<int>{1, 3, 5, 7}));
    EXPECT_EQ(survival, (std::set<int>{2, 4, 6, 8}));
}

TEST(UniverseCharacteristicsParserTest, ParseWindowSize_ValidInput) {
    size_t width, height;

    EXPECT_EQ(UniverseCharacteristicsParser::parseWindowSize("800 600", width, height), SUCCESS_PARSING);
    EXPECT_EQ(width, 800);
    EXPECT_EQ(height, 600);

    EXPECT_EQ(UniverseCharacteristicsParser::parseWindowSize
    ("  1024   768  ", width, height), SUCCESS_PARSING);
    EXPECT_EQ(width, 1024);
    EXPECT_EQ(height, 768);
}

TEST(UniverseCharacteristicsParserTest, ParseWindowSize_InvalidInput) {
    size_t width, height;

    EXPECT_EQ(UniverseCharacteristicsParser::parseWindowSize
    ("abc 600", width, height), INVALID_WINDOW_SIZE_FORMAT);

    EXPECT_EQ(UniverseCharacteristicsParser::parseWindowSize
    ("800 600 extra", width, height), INVALID_WINDOW_SIZE_FORMAT);

    EXPECT_EQ(UniverseCharacteristicsParser::parseWindowSize
    ("0 600", width, height), WINDOW_SIZE_MUST_BE_POSITIVE);
    EXPECT_EQ(UniverseCharacteristicsParser::parseWindowSize
    ("800 0", width, height), WINDOW_SIZE_MUST_BE_POSITIVE);
}

TEST(UniverseCharacteristicsParserTest, ParseAliveCells_ValidInput) {
    std::vector<std::pair<int, int>> aliveCells;

    std::vector<std::string> lines = {"0 0", "1 -1", "2 3"};
    EXPECT_EQ(UniverseCharacteristicsParser::parseAliveCells(lines, aliveCells), SUCCESS_PARSING);
    ASSERT_EQ(aliveCells.size(), 3);
    EXPECT_EQ(aliveCells[0], std::make_pair(0, 0));
    EXPECT_EQ(aliveCells[1], std::make_pair(1, -1));
    EXPECT_EQ(aliveCells[2], std::make_pair(2, 3));
}

TEST(UniverseCharacteristicsParserTest, ParseAliveCells_InvalidInput) {
    std::vector<std::pair<int, int>> aliveCells;

    std::vector<std::string> lines = {"0 0", "a b"};
    EXPECT_EQ(UniverseCharacteristicsParser::parseAliveCells(lines, aliveCells), INVALID_COORDINATE_FORMAT);
    aliveCells.clear();

    lines = {"1 1", "2 2 extra"};
    EXPECT_EQ(UniverseCharacteristicsParser::parseAliveCells(lines, aliveCells), INVALID_COORDINATE_FORMAT);
    aliveCells.clear();

    lines = {"0 0", ""};
    EXPECT_EQ(UniverseCharacteristicsParser::parseAliveCells(lines, aliveCells), SUCCESS_PARSING);
    ASSERT_EQ(aliveCells.size(), 1);
    EXPECT_EQ(aliveCells[0], std::make_pair(0, 0));
}

#endif
