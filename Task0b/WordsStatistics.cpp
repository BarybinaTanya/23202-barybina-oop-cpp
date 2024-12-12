#include "WordsStatistics.h"

static string toLower(const string &str) {
    string result = str;
    std::transform(result.begin(),
                   result.end(),
                   result.begin(),
                   ::tolower);
    return result;
}

void WordsStatistics::recalculateFrequencies() {
    for (auto &entry : statistics) {
        entry.second.second =
                static_cast<float>(entry.second.first) / totalWordCount;
    }
}

void WordsStatistics::addWords(const std::vector<string> &splittedText) {
    for (const auto &word : splittedText) {
        addWord(word);
    }
}

void WordsStatistics::addWord(const string &word) {
    string lowerWord = toLower(word);
    statistics[lowerWord].first++;
    totalWordCount++;
    recalculateFrequencies();
}

std::list<string> WordsStatistics::getWordsInStatistics() const {
    std::list<std::string> result;
    for (const auto &entry : statistics) {
        result.push_back(entry.first);
    }
    return result;
}

std::pair<int, float> WordsStatistics::getStatisticsByWord(const string &word) const {
    string lowerWord = toLower(word);
    auto it = statistics.find(lowerWord);
    if (it != statistics.end()) {
        return it->second;
    }
    return {0, 0.0f};
}

int WordsStatistics::getNumberWords() const {
    return totalWordCount;
}


