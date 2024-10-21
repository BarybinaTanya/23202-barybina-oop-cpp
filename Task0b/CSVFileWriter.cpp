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

void CSVFileWriter::openFile(const string &fileName) {
    if (!isCSV(fileName)) {
        std::cerr << "You are trying to create or open non .csv file!" << std::endl;
        return;
    }
    outputFile.open(fileName);
    if (!outputFile.is_open()) {
        std::cerr << "Error opening file: " << fileName << std::endl;
    }
}

std::ofstream* CSVFileWriter::getFile() {
    if (outputFile.is_open()) {
        return &outputFile;
    } else {
        return nullptr;
    }
}

void CSVFileWriter::closeFile() {
    if (outputFile.is_open()) {
        outputFile.close();
    }
}

void CSVFileWriter::write(std::vector<string> &vector) {
    if (!outputFile.is_open()) {
        perror("Nowhere to write. Output file is closed.");
        return;
    }
    for (const auto &element : vector) {
        outputFile << element << '\n';
    }
}
