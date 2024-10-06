#include "CSVFileWriter.h"

bool CSVFileWriter::isCSV(const string &fileName) {
    int lastInd = fileName.size() - 1;
    if (!(fileName[lastInd] == 'v' && fileName[lastInd - 1] == 's' &&
          fileName[lastInd - 2] == 'c' && fileName[lastInd - 3] == '.')) {
        return false;
    }
    else {
        return true;
    }
}

void CSVFileWriter::openOrCreateOutputFile(const string &fileName) {
    if (!isCSV(fileName)) {
        std::cerr << "You are trying to create or open non .csv file!" << std::endl;
        return;
    }
    outputFile.open(fileName);
    if (!outputFile.is_open()) {
        std::cerr << "Error opening file: " << fileName << std::endl;
    }
}

void CSVFileWriter::closeOutputFile() {
    if (outputFile.is_open()) {
        outputFile.close();
    }
}

void CSVFileWriter::writeCSVFileHeader(const string &commaSeparatedLine) {
    if (outputFile.is_open()) {
        outputFile << commaSeparatedLine << std::endl;
    }
}

void CSVFileWriter::writeDefaultCSVFileHeader() {
    if (outputFile.is_open()) {
        outputFile << "Word,Frequency,%Frequency" << std::endl;
    }
}

void CSVFileWriter::writeFrequencyMapToCSV(const std::map<string, std::pair<int, float>> &frequencyMap) {
    writeDefaultCSVFileHeader();
    for (const auto &it : frequencyMap) {
        outputFile << it.first << "," << it.second.first << "," << it.second.second << std::endl;
    }
}
