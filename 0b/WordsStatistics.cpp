#include "WordsStatistics.h"

int WordsStatistics::getNumberWordsContained() {
    return numberWordsInText;
}

void WordsStatistics::getAllKeyWords(std::vector<string> &splittedText) {
    int iterator = 0;
    while (iterator < splittedText.size()) {
        if (!(std::find(allKeyWordsMet.begin(), allKeyWordsMet.end(),
                        splittedText[iterator]) != allKeyWordsMet.end())) {
            allKeyWordsMet.push_back(splittedText[iterator]);
        }
        iterator++;
    }
}

void WordsStatistics::getFullFrequencyMap(std::vector<string> &splittedText) {
    if (allKeyWordsMet.empty()) {
        getAllKeyWords(splittedText);
    }
    int iterator1 = 0;
    while (iterator1 < splittedText.size()) {
        wordsFrequencyStatistics[splittedText[iterator1]].first++;
        numberWordsInText++;
        iterator1++;
    }
    int iterator2 = 0;
    while (iterator2 < allKeyWordsMet.size()) {
        wordsFrequencyStatistics[allKeyWordsMet[iterator2]].second =
                (float)wordsFrequencyStatistics[allKeyWordsMet[iterator2]].first / (float)numberWordsInText;
        iterator2++;
    }
}
