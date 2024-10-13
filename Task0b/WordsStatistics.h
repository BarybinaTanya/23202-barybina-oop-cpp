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
    int numberWordsInText = 0;
public:
    std::map<string, std::pair<int, float>> wordsFrequencyStatistics;
    std::vector<string> allKeyWordsMet;

    int getNumberWordsContained();
    void getAllKeyWords(std::vector<string> &splittedText);
    void getFullFrequencyMap(std::vector<string> &splittedText);
};

#endif //INC_0B_WORDSSTATISTICS_H
