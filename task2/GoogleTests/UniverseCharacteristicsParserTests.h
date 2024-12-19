#include <gtest/gtest.h>
#include "..\UniverseCharacteristicsParser.h"
#include <fstream>

class UniverseCharacteristicsParserTest : public ::testing::Test {
protected:
    // Helper function to create a test file with given content
    void createTestFile(const std::string& filename, const std::vector<std::string>& lines) {
        std::ofstream file(filename);
        for (const auto& line : lines) {
            file << line << "\n";
        }
    }

    // Cleanup function to remove test files
    void removeTestFile(const std::string& filename) {
        std::remove(filename.c_str());
    }
};

TEST_F(UniverseCharacteristicsParserTest, ValidFileParsesSuccessfully) {
    const std::string filename = "valid_universe.txt";
    createTestFile(filename, {
            "#R B3/S23",        // Rules
            "30 30",            // Dimensions
            "1 1", "2 2", "3 3" // Alive cells
    });

    UniverseCharacteristicsParser parser;
    UniverseConfig config = parser.parse(const_cast<std::string&>(filename));

    // Check dimensions
    EXPECT_EQ(config.getWidth(), 30);
    EXPECT_EQ(config.getHeight(), 30);

    // Check rules
    std::set<int> expectedBirth = {3};
    std::set<int> expectedSurvival = {2, 3};
    EXPECT_EQ(config.getBirthRules(), expectedBirth);
    EXPECT_EQ(config.getSurvivalRules(), expectedSurvival);

    // Check alive cells
    std::vector<std::pair<int, int>> expectedAliveCells = {{1, 1}, {2, 2}, {3, 3}};
    EXPECT_EQ(config.getAliveCells(), expectedAliveCells);

    removeTestFile(filename);
}