#ifndef INC_0B_READER_H
#define INC_0B_READER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using std::string;

class Reader {
    unsigned long long numberLinesRead = 0;
public:
    std::ifstream inputFile;
    std::vector<string> allLines;

    void openFile(string fileName);
    void closeFile();
    bool isFileEmpty();
    string readLine();
    bool hasNextLine();
    void readAllLines();
    unsigned long long getNumberLinesRead() const;
};

#endif //INC_0B_READER_H
