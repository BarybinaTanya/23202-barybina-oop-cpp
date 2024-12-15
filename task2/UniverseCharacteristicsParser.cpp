#include "UniverseCharacteristicsParser.h"

short UniverseCharacteristicsParser::parseWindowSize(const std::string& windowSizeLine, size_t& width, size_t& height) {
    std::istringstream iss(windowSizeLine);
    if (!(iss >> width >> height)) {
        return INVALID_WINDOW_SIZE_FORMAT;
    }
    std::string extra;
    if (iss >> extra) {
        return INVALID_WINDOW_SIZE_FORMAT;
    }
    if (width == 0 || height == 0) {
        return WINDOW_SIZE_MUST_BE_POSITIVE;
    }
    return SUCCESS_PARSING;
}

short UniverseCharacteristicsParser::parseRules(const std::string& rules, std::set<int>& birth, std::set<int>& survival) {
    if (rules.substr(0, 3) != "#R " || rules[3] != 'B') {
        return INVALID_RULE_FORMAT;
    }
    size_t i = 4;
    while (isdigit(rules[i])) {
        birth.insert(rules[i] - '0');
        i++;
    }
    if (rules[i++] != '/' || rules[i++] != 'S') {
        return INVALID_RULE_FORMAT;
    }
    while (isdigit(rules[i])) {
        survival.insert(rules[i] - '0');
        i++;
    }
    return SUCCESS_PARSING;
}

short UniverseCharacteristicsParser::parseAliveCells(const std::vector<std::string>& lines,
                                                     std::vector<std::pair<int, int>> &aliveCells) {
    for (const auto& line : lines) {
        if (line.empty()) {
            continue;
        }
        std::istringstream iss(line);
        int x, y;
        if (!(iss >> x >> y)) {
            return INVALID_COORDINATE_FORMAT;
        }

        std::string extra;
        if (iss >> extra) {
            return INVALID_COORDINATE_FORMAT;
        }
        aliveCells.emplace_back(x, y);
    }
    return SUCCESS_PARSING;
}