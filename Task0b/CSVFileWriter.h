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
    bool isCSV(const string &fileName);
    void writeDefaultCSVFileHeader();
public:
    std::ofstream outputFile;

    void openOrCreateOutputFile(const string &fileName);
    void closeOutputFile();
    void writeCSVFileHeader(const string &commaSeparatedLine);
    void writeFrequencyMapToCSV(const std::map<string, std::pair<int, float>> &frequencyMap);
};

#endif //INC_0B_CSVFILEWRITER_H
