#include "CSVFileWriter.h"
#include <stdexcept>

bool CSVFileWriter::isCSV(const string &fileName) {
    const string extension = ".csv";
    return fileName.size() >= extension.size() &&
           fileName.compare(fileName.size() - extension.size(), extension.size(), extension) == 0;
}

void CSVFileWriter::openFile(const string &fileName) {
    if (!isCSV(fileName)) {
        throw std::invalid_argument("File name must have .csv extension: " + fileName);
    }

    outputFile.open(fileName, std::ios::out | std::ios::trunc);
    if (!outputFile.is_open()) {
        throw std::ios_base::failure("Failed to open file: " + fileName);
    }
}

void CSVFileWriter::closeFile() {
    if (outputFile.is_open()) {
        outputFile.close();
    }
}

void CSVFileWriter::write(const std::vector<string> &data) {
    if (!outputFile.is_open()) {
        throw std::ios_base::failure("File is not open for writing.");
    }

    if (data.empty()) {
        return;
    }

    for (size_t i = 0; i < data.size(); ++i) {
        outputFile << data[i];
        if (i < data.size() - 1) {
            outputFile << ',';
        }
    }
    outputFile << '\n';
}

std::ofstream* CSVFileWriter::getFile() {
    return outputFile.is_open() ? &outputFile : nullptr;
}
