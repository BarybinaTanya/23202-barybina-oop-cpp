#include "WordsStatistics.h"

int WordsStatistics::getNumberWordsContained() {
    return numberWordsInText;
}

void WordsStatistics::getAllKeyWords(std::vector<string> &splittedText) {
    int iterator = 0;
    while (iterator < splittedText.size()) {
        string lowerCaseWord = splittedText[iterator];
        std::transform(lowerCaseWord.begin(), lowerCaseWord.end(), lowerCaseWord.begin(), ::tolower);
        if (!(std::find(allKeyWordsMet.begin(), allKeyWordsMet.end(),
                        lowerCaseWord) != allKeyWordsMet.end())) {
            allKeyWordsMet.push_back(lowerCaseWord);
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
        string lowerCaseWord = splittedText[iterator1];
        std::transform(lowerCaseWord.begin(), lowerCaseWord.end(), lowerCaseWord.begin(), ::tolower);
        wordsFrequencyStatistics[lowerCaseWord].first++;
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
