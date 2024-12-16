#ifndef INC_0B_CSVFILEWRITER_H
#define INC_0B_CSVFILEWRITER_H

#include <fstream>
#include <string>
#include <vector>

using std::string;

class CSVFileWriter {
private:
    std::ofstream outputFile;
    static bool isCSV(const string &fileName);

public:
    void openFile(const string &fileName);
    void closeFile();
    void write(const std::vector<string> &data);
    std::ofstream* getFile();
};

#endif //INC_0B_CSVFILEWRITER_H
