#ifndef INC_0B_WORDSSTATISTICS_H
#define INC_0B_WORDSSTATISTICS_H

#include <algorithm>
#include <list>
#include <iostream>
#include <fstream>
#include <utility>
#include <string>
#include <vector>
#include <map>

using std::string;

class WordsStatistics {
private:
    int totalWordCount = 0;
    std::map<string, std::pair<int, float>> statistics;
    void recalculateFrequencies();
public:
    void addWords(const std::vector<string> &splittedText);
    void addWord(const string &word);
    [[nodiscard]] std::list<string> getWordsInStatistics() const;
    [[nodiscard]] std::pair<int, float> getStatisticsByWord(const string &word) const;
    [[nodiscard]] int getNumberWords() const;
};

#endif //INC_0B_WORDSSTATISTICS_H
