#include "Splitter.h"
#define notMatchRegularExpressionFlag (-1)

void Splitter::setDefaultDelimiters() {
    delimiters = " |\\n";
}

void Splitter::addDelimiter(const string &delimiter) {
    if (!delimiters.empty()) {
        delimiters += '|';
    }
    for (int i = 0; i < delimiter.size(); ++i) {
        if (delimiter[i] == '+') {
            delimiters += "\\";
            delimiters += delimiter[i];
        }
        else {
            delimiters += delimiter[i];
        }
    }
}

void Splitter::removeAllDelimiters() {
    if (!delimiters.empty()) {
        delimiters.clear();
    }
}

string Splitter::getDelimiters() {
    return this->delimiters;
}

void Splitter::splitLine(const string &line, bool removePunctuationFlag) {
    if (delimiters.empty()) {
        setDefaultDelimiters();
    }
    std::regex regularExpression(this->delimiters);
    std::sregex_token_iterator iterator
    (line.begin(), line.end(),regularExpression, notMatchRegularExpressionFlag);
    std::sregex_token_iterator emptyEndIterator;

    while (iterator != emptyEndIterator) {
        this->splittedText.push_back(*iterator++);
        if (removePunctuationFlag) {
            if (!splittedText.empty() && (
                    splittedText.back().front() == '(' || splittedText.back().front() == '"')) {
                splittedText.back().erase(0, 1);
            }
            if (!splittedText.empty() && (
                    splittedText.back().back() == '!' || splittedText.back().back() == '.' ||
                    splittedText.back().back() == ';' || splittedText.back().back() == ':' ||
                    splittedText.back().back() == ',' || splittedText.back().back() == '?' ||
                    splittedText.back().back() == ')' || splittedText.back().back() == '"')) {
                splittedText.back().erase(splittedText.back().size() - 1, 1);
            }
        }
    }
}

void Splitter::splitText(std::vector<string> &allLines, bool removePunctuationFlag) {
    int iterator = 0;
    while (iterator < allLines.size()) {
        this->splitLine(allLines[iterator], removePunctuationFlag);
        iterator++;
    }
}

string getEscapedVersion(string &delimiterToDelete) {
    int it = 0;
    while (it < delimiterToDelete.size()) {
        if (delimiterToDelete[it] == '+') {
            delimiterToDelete.insert(it, "\\");
            it += 2;
        }
        else if (delimiterToDelete[it] == '\n') {
            delimiterToDelete.insert(it, "\\");
            it += 2;
        }
        else {
            it++;
        }
    }
    return delimiterToDelete;
}

void Splitter::removeDelimiter(const string &delimiterToDelete) {
    string delLine = delimiterToDelete;
    delLine = getEscapedVersion(delLine);

    int generalIt = 0;
    int dDelimiterIt = 0;
    int size = delLine.size();

    while (generalIt < delimiters.size()) {
        if (delimiters[generalIt] == delLine[dDelimiterIt]) {
            dDelimiterIt++;
            generalIt++;
        }
        else {
            dDelimiterIt = 0;
            generalIt++;
        }
        if (dDelimiterIt == size) {
            generalIt = generalIt - size;
            delimiters.erase(generalIt, size);
            if ((generalIt - 1 >= 0) && (delimiters[generalIt - 1] == '|')) {
                delimiters.erase(generalIt - 1, 1);
            }
            dDelimiterIt = 0;
        }
    }
}