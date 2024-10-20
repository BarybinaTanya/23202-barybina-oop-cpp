#ifndef INC_0B_CSVFILEWRITER_H
#define INC_0B_CSVFILEWRITER_H

#include <iostream>
#include <fstream>
#include <utility>
#include <string>
#include <vector>
#include <map>

using std::string;

class CSVFileWriter {
private:
    std::ofstream outputFile;
    static bool isCSV(const string &fileName);
public:
    void openFile(const string &fileName);
    void closeFile();
    void write(std::vector<string> &vector);
    std::ofstream* getFile();
};

#endif //INC_0B_CSVFILEWRITER_H
