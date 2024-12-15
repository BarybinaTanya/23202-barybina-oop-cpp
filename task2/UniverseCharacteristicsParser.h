#ifndef TASK2_UNIVERSECHARACTERISTICSPARSER_H
#define TASK2_UNIVERSECHARACTERISTICSPARSER_H

#include <sstream>
#include <vector>
#include <string>
#include <set>

enum fileProcessingResults{
    INVALID_RULE_FORMAT,
    INVALID_WINDOW_SIZE_FORMAT,
    INVALID_COORDINATE_FORMAT,
    WINDOW_SIZE_MUST_BE_POSITIVE,
    SUCCESS_PARSING
};

class UniverseCharacteristicsParser {
public:
    static short parseWindowSize(const std::string& windowSizeLine, int& width, int& height);
    static short parseRules(const std::string& rules, std::set<int>& birth, std::set<int>& survival);
    static short parseAliveCells(const std::vector<std::string>& lines,
                                 std::vector<std::pair<int, int>> &aliveCells);
};

#endif //TASK2_UNIVERSECHARACTERISTICSPARSER_H
