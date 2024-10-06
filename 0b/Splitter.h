#ifndef INC_0B_SPLITTER_H
#define INC_0B_SPLITTER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <regex>

using std::string;

class Splitter {
    string delimiters;
    void setDefaultDelimiters();
public:
    std::vector<string> splittedText;
    // Words in this list can repeat.

    void addDelimiter(const string &delimiter);
    void removeDelimiter(const string &delimiterToDelete);
    void removeAllDelimiters();
    void splitLine(const string &line, bool removePunctuationFlag);
    void splitText(std::vector<string> &allLines, bool removePunctuationFlag);
    string getDelimiters();
};

#endif //INC_0B_SPLITTER_H
