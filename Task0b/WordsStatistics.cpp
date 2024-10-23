#include "WordsStatistics.h"

std::vector<string> WordsStatistics::getAllWords() {
    std::vector<string> result;
    for (const auto &element : statistics) {
        string str_push;
        str_push.append(element.first);
        result.push_back(str_push);
    }
    return result;
}

void WordsStatistics::addWords(std::vector<string> &splittedText) {
    int iterator1 = 0;
    while (iterator1 < splittedText.size()) {
        string lowerCaseWord = splittedText[iterator1];
        std::transform(lowerCaseWord.begin(), lowerCaseWord.end(),
                       lowerCaseWord.begin(), ::tolower);

        statistics[lowerCaseWord].first++;
        numberWordsInText++;
        iterator1++;
    }
    for (auto &element : statistics) {
        std::pair<int, float> &stat = element.second;
        stat.second = (float)stat.first / (float)numberWordsInText;
    }

//    std::cout << "Total words: " << numberWordsInText << std::endl;
//    for (const auto &element : statistics) {
//        std::cout << element.first << ": " << element.second.first << ", " << element.second.second << std::endl;
//    }
}

void WordsStatistics::addWord(const string &word_orig) {
    string word = word_orig;
    std::transform(word.begin(), word.end(),word.begin(), ::tolower);
    statistics[word].first++;
    numberWordsInText++;
    statistics[word].second = (float)statistics[word].first / (float)numberWordsInText;
}

std::pair<int, float> WordsStatistics::getStatisticsByWord(const string &word) {
    std::pair<int, float> result;
    result.first = statistics[word].first;
    result.second = statistics[word].second;
    return result;
}
