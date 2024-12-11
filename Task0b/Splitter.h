#ifndef INC_0B_SPLITTER_H
#define INC_0B_SPLITTER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <regex>
#include <cctype>

using std::string;

class Splitter {
public:
    static std::vector<string> splitLine(const string &line);
};

#endif //INC_0B_SPLITTER_H
