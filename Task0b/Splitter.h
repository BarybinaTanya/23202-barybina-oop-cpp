#ifndef INC_0B_SPLITTER_H
#define INC_0B_SPLITTER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <regex>

using std::string;

class Splitter {
private:
    string delimiters;
    void setDefaultDelimiters();
public:
    void addDelimiter(const string &delimiter);
    void removeDelimiter(const string &delimiterToDelete);
    void removeAllDelimiters();
    std::vector<string> splitLine(const string &line);
    string getDelimiters();
};

#endif //INC_0B_SPLITTER_H
