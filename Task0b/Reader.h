#ifndef INC_0B_READER_H
#define INC_0B_READER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using std::string;

class Reader {
private:
    std::ifstream inputFile;
    std::vector<string> allLines;
    unsigned long long numberLinesRead = 0;
public:
    void openFile(string fileName);
    void closeFile();
    std::ifstream* getFile();
    bool isFileEmpty();
    string readLine();
    bool hasNextLine();
    std::vector<string> getAllLinesRead() const;
    unsigned long long getNumberLinesRead() const;
};

#endif //INC_0B_READER_H
