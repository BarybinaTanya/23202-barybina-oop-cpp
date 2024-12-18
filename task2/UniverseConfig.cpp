#include "UniverseConfig.h"

std::string UniverseConfig::getUniverseName() const {
    return universeName;
}

std::set<int> UniverseConfig::getBirthRules() const {
    return birthRules;
}

std::set<int> UniverseConfig::getSurvivalRules() const {
    return survivalRules;
}

size_t UniverseConfig::getWidth() const {
    return widthX;
}

size_t UniverseConfig::getHeight() const {
    return heightY;
}

std::vector<std::pair<int, int>> UniverseConfig::getAliveCells() const {
    return aliveCells;
}

[[nodiscard]] fileProcessingResults UniverseConfig::getFileError() const {
    return fileError;
}


void UniverseConfig::setUniverseName(const std::string& name) {
    universeName = name;
}

void UniverseConfig::setBirthRules(const std::set<int>& birth) {
    birthRules = birth;
}

void UniverseConfig::setSurvivalRules(const std::set<int>& survival) {
    survivalRules = survival;
}

void UniverseConfig::setWidth(size_t width) {
    widthX = width;
}

void UniverseConfig::setHeight(size_t height) {
    heightY = height;
}

void UniverseConfig::setAliveCells(const std::vector<std::pair<int, int>>& cells) {
    aliveCells = cells;
}

fileProcessingResults UniverseConfig::setFileError(fileProcessingResults result) {
    fileError = result;
}
