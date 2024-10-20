#include "Splitter.h"
#define notMatchRegularExpressionFlag (-1)

void Splitter::setDefaultDelimiters() {
    delimiters = " |\\n|!|;|\\.|:|,|\\\"|\\?";
}

void Splitter::addDelimiter(const string &delimiter) {
    if (!delimiters.empty()) {
        delimiters += '|';
    }
    for (int i = 0; i < delimiter.size(); ++i) {
        if (delimiter[i] == '+' || delimiter[i] == '.' || delimiter[i] == '?') {
            delimiters += "\\";
            delimiters += delimiter[i];
        }
        else if (delimiter[i] == '\n') {
            delimiters += "\\n";
        }
        else {
            delimiters += delimiter[i];
        }
    }
}

void Splitter::removeAllDelimiters() {
    delimiters.clear();
}

string Splitter::getDelimiters() {
    return this->delimiters;
}

std::vector<string> Splitter::splitLine(const string &line) {
    std::vector<string> splitted_line;
    if (delimiters.empty()) {
        setDefaultDelimiters();
    }
    std::regex regularExpression(delimiters);
    std::sregex_token_iterator iterator
    (line.begin(), line.end(),regularExpression, notMatchRegularExpressionFlag);
    std::sregex_token_iterator emptyEndIterator;

    while (iterator != emptyEndIterator) {
        if (!(*iterator).str().empty()) {
            splitted_line.push_back(*iterator);
        }
        *iterator++;
    }
    return splitted_line;
}

string getEscapedVersion(string &delimiterToDelete) {
    int it = 0;
    string result;
    while (it < delimiterToDelete.size()) {
        if (delimiterToDelete[it] == '+' || delimiterToDelete[it] == '.' || delimiterToDelete[it] == '?') {
            result += "\\";
            result += delimiterToDelete[it];
        }
        else if (delimiterToDelete[it] == '\n') {
            result += "\\n";
        }
        else {
            result += delimiterToDelete[it];
        }
        it++;
    }
    return result;
}

void Splitter::removeDelimiter(const string &delimiterToDelete) {
    if (delimiters.empty()) {
        setDefaultDelimiters();
    }
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