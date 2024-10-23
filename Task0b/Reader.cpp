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

bool Reader::isFileEmpty() const {
    return numberLinesRead == 0 && !hasNextLine();
}

string Reader::readLine() {
    char buff[100000];
    if (inputFile.getline(buff, 100000, '\n')) {
        string line(buff);
        allLines.push_back(line);
        numberLinesRead++;
        return line;
    }
    else {
        return "";
    }
}

bool Reader::hasNextLine() const {
    return !inputFile.eof();
}

std::ifstream* Reader::getFile() {
    if (inputFile.is_open()) {
        return &inputFile;
    } else {
        return nullptr;
    }
}


std::vector<string> Reader::getAllLinesRead() const{
    return allLines;
}

unsigned long long Reader::getNumberLinesRead() const {
    return numberLinesRead;
}



