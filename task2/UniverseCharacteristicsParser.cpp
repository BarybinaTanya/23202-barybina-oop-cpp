#include "UniverseCharacteristicsParser.h"

void parseWindowSize(const std::string& windowSizeLine, int& width, int& height, UniverseConfig &config) {
    std::istringstream iss(windowSizeLine);
    if (!(iss >> width >> height)) {
        config.setFileError(INVALID_WINDOW_SIZE_FORMAT);
    }
    std::string extra;
    if (iss >> extra) {
        config.setFileError(INVALID_WINDOW_SIZE_FORMAT);
    }
    if (width == 0 || height == 0) {
        config.setFileError(WINDOW_SIZE_MUST_BE_POSITIVE);
    }
}

void parseRules(const std::string& rules, std::set<int>& birth, std::set<int>& survival, UniverseConfig &config) {
    if (rules.substr(0, 3) != "#R " || rules[3] != 'B') {
        config.setFileError(INVALID_RULE_FORMAT);
    }
    size_t i = 4;
    while (isdigit(rules[i])) {
        birth.insert(rules[i] - '0');
        i++;
    }
    if (rules[i++] != '/' || rules[i++] != 'S') {
        config.setFileError(INVALID_RULE_FORMAT);
    }
    while (isdigit(rules[i])) {
        survival.insert(rules[i] - '0');
        i++;
    }
}

void parseAliveCells(const std::vector<std::string>& lines,
                      std::vector<std::pair<int, int>> &aliveCells, UniverseConfig &config) {
    for (const auto& line : lines) {
        if (line.empty()) {
            continue;
        }
        std::istringstream iss(line);
        int x, y;
        if (!(iss >> x >> y)) {
            config.setFileError(INVALID_COORDINATE_FORMAT);
        }

        std::string extra;
        if (iss >> extra) {
            config.setFileError(INVALID_COORDINATE_FORMAT);
        }
        aliveCells.emplace_back(x, y);
    }
}

UniverseConfig UniverseCharacteristicsParser::parse(std::string &filePath) {
    UniverseConfig configs;
    Reader reader;

    reader.openFile(filePath);


//    std::string name = reader.readLine();
//    configs.setUniverseName(name);

    std::string rules = reader.readLine();
    std::set<int> birth;
    std::set<int> survival;
    parseRules(rules, birth, survival, configs);

    configs.setBirthRules(birth);
    configs.setSurvivalRules(survival);

    std::string sizeLine = reader.readLine();
    int sizeX;
    int sizeY;
    parseWindowSize(sizeLine, sizeX, sizeY, configs);
    configs.setWidth(sizeX);
    configs.setHeight(sizeY);

    std::vector<std::string> lines;
    std::vector<std::pair<int, int>> aliveCells;
    while (reader.hasNextLine()) {
        lines.push_back(reader.readLine());
    }
    parseAliveCells(lines, aliveCells, configs);
    configs.setAliveCells(aliveCells);
    return configs;
}