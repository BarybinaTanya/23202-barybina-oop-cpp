#ifndef TASK2_UNIVERSECONFIG_H
#define TASK2_UNIVERSECONFIG_H

#include <string>
#include <set>
#include <vector>

enum fileProcessingResults{
    INVALID_RULE_FORMAT,
    INVALID_WINDOW_SIZE_FORMAT,
    INVALID_COORDINATE_FORMAT,
    WINDOW_SIZE_MUST_BE_POSITIVE,
    SUCCESS_PARSING
};

class UniverseConfig {
    std::string universeName;

    std::set<int> birthRules;
    std::set<int> survivalRules;

    size_t widthX;
    size_t heightY;

    std::vector<std::pair<int, int>> aliveCells;
    fileProcessingResults fileError = SUCCESS_PARSING;

public:
    [[nodiscard]] std::string getUniverseName() const;
    [[nodiscard]] std::set<int> getBirthRules() const;
    [[nodiscard]] std::set<int> getSurvivalRules() const;
    [[nodiscard]] size_t getWidth() const;
    [[nodiscard]] size_t getHeight() const;
    [[nodiscard]] std::vector<std::pair<int, int>> getAliveCells() const;
    [[nodiscard]] fileProcessingResults getFileError() const;

    void setUniverseName(const std::string& name);
    void setBirthRules(const std::set<int>& birth);
    void setSurvivalRules(const std::set<int>& survival);
    void setWidth(size_t width);
    void setHeight(size_t height);
    void setAliveCells(const std::vector<std::pair<int, int>>& cells);
    fileProcessingResults setFileError(fileProcessingResults result);
};

#endif //TASK2_UNIVERSECONFIG_H
