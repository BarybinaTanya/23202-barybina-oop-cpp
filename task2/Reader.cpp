#include "Reader.h"

void Reader::openFile(const std::string& fileName) {
    inputFile.open(fileName, std::ios::in);
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open the file: " + fileName;
        exit(1);
    }
}

void Reader::closeFile() {
    if (inputFile.is_open()) {
        inputFile.close();
    }
}

std::ifstream* Reader::getFile() {
    return inputFile.is_open() ? &inputFile : nullptr;
}

bool Reader::isFileEmpty() {
    if (!inputFile.is_open()) {
        std::cerr << "File is not opened";
        exit(1);
    }
    // Save the current position
    std::streampos currentPos = inputFile.tellg();
    inputFile.seekg(0, std::ios::end);
    bool isEmpty = (inputFile.tellg() == 0);
    inputFile.seekg(currentPos, std::ios::beg);
    return isEmpty;
}

std::string Reader::readLine() {
    if (!inputFile.is_open()) {
        std::cerr << "File is not opened";
        exit(1);
    }

    std::string line;
    if (std::getline(inputFile, line)) {
        allLines.push_back(line);
        numberLinesRead++;
    }
    return line;
}

bool Reader::hasNextLine() {
    if (!inputFile.is_open()) {
        std::cerr << "File is not opened";
        exit(1);
    }
    // Check if the next read operation will not hit EOF
    return inputFile.peek() != std::ifstream::traits_type::eof();
}

const std::vector<std::string>& Reader::getAllLinesRead() const {
    return allLines;
}

unsigned long long Reader::getNumberLinesRead() const {
    return numberLinesRead;
}
