#include "Reader.h"

void Reader::openFile(string fileName) {
    inputFile.open(fileName);
    if (!inputFile) {
        std::cerr << "Error opening the file" << std::endl;
        exit(1);
    }
}

void Reader::closeFile() {
    if (inputFile.is_open()) {
        inputFile.close();
    }
    else {
        std::cerr << "File wasn't opened" << std::endl;
    }
}

bool Reader::isFileEmpty() {
    std::streampos originalPosition = inputFile.tellg();
    inputFile.seekg(0, std::ios::end);
    std::streampos size = inputFile.tellg();

    if (size == 0) {
        inputFile.seekg(originalPosition);
        return true;
    }
    else {
        inputFile.seekg(originalPosition);
        return false;
    }
}

string Reader::readLine() {
    string line;
    if (std::getline(inputFile, line)) {
        allLines.push_back(line);
        numberLinesRead++;
        return line;
    }
    else {
        return "";
    }
}

bool Reader::hasNextLine() {
    if (this->isFileEmpty()) {
        return false;
    }
    std::streampos pos = inputFile.tellg();
    string line;
    std::getline(inputFile, line);
    if (!line.empty()) {
        inputFile.seekg(pos);
        return true;
    }
    else {
        inputFile.seekg(pos);
        return false;
    }
}

void Reader::readAllLines() {
    inputFile.seekg(0, std::ios::beg);

    string line = this->readLine();
    while (!line.empty()) {
        line = this->readLine();
    }
    numberLinesRead = allLines.size();
    inputFile.seekg(0, std::ios::beg);
}

unsigned long long Reader::getNumberLinesRead() const {
    return numberLinesRead;
}

