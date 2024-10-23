#ifndef INC_0B_WORDSSTATISTICS_H
#define INC_0B_WORDSSTATISTICS_H

#include <algorithm>
#include <iostream>
#include <fstream>
#include <utility>
#include <string>
#include <vector>
#include <map>

using std::string;

class WordsStatistics {
private:
    int numberWordsInText = 0;
    std::map<string, std::pair<int, float>> statistics;
public:
    void addWords(std::vector<string> &splittedText);
    void addWord(const string &word_orig);
    std::vector<string> getAllWords();
    std::pair<int, float> getStatisticsByWord(const string &word);
};

#endif //INC_0B_WORDSSTATISTICS_H
