#ifndef INC_0B_READER_H
#define INC_0B_READER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdexcept>

using std::string;

class Reader {
private:
    std::ifstream inputFile;
    std::vector<string> allLines;
    unsigned long long numberLinesRead = 0;
public:
    void openFile(const string &fileName);
    void closeFile();
    std::ifstream* getFile();
    bool isFileEmpty();
    string readLine();
    bool hasNextLine();
    [[nodiscard]] const std::vector<std::string>& getAllLinesRead() const;
    [[nodiscard]] unsigned long long getNumberLinesRead() const;
};

#endif //INC_0B_READER_H
