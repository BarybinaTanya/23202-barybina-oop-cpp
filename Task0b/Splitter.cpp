#include "Splitter.h"

std::vector<std::string> Splitter::splitLine(const std::string &line) {
    std::vector<std::string> result;
    std::regex wordRegex(R"((\w+))");
    auto wordsBegin = std::sregex_iterator(line.begin(), line.end(), wordRegex);
    auto wordsEnd = std::sregex_iterator();

    for (std::sregex_iterator it = wordsBegin; it != wordsEnd; ++it) {
        result.push_back(it->str());
    }

    return result;
}