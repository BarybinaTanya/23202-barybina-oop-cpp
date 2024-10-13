#ifndef INC_0B_READERTESTS_H
#define INC_0B_READERTESTS_H

#include <gtest/gtest.h>
#include <fstream>
#include "../Reader.h"

std::string readerTestFiles[] = {"test_file1.txt", "test_file2.txt"};

void createTestFileType1 (std::string newFileName) {
    std::ofstream test_file(newFileName);
    test_file << "First Line\nSecond Line\nNSU, please, stop doing this to me!";
    test_file.close();
}

void createTestFileType2 (std::string newFileName) {
    std::ofstream test_file(newFileName);
    test_file << "";
    test_file.close();
}

TEST(ReaderTest, OpenFileTest) {
    Reader readerWizard;
    createTestFileType1(readerTestFiles[0]);

    readerWizard.openFile(readerTestFiles[0]);
    ASSERT_TRUE(readerWizard.inputFile.is_open());
    if (readerWizard.inputFile.is_open()) {
        readerWizard.inputFile.close();
    }
}

TEST(ReaderTest, CloseFileTest) {
    Reader readerWizard;
    readerWizard.openFile(readerTestFiles[0]);
    readerWizard.closeFile();
    ASSERT_TRUE(!readerWizard.inputFile.is_open());
}

std::string getRightLineByFileName(std::string FileName) {
    std::string line;
    std::ifstream test_file(FileName);
    std::getline(test_file, line);
    return line;
}

TEST(ReaderTest, ReadLineTest) {
    Reader readerWizard;
    readerWizard.openFile(readerTestFiles[0]);

    std::string lineRead = readerWizard.readLine();
    std::string rightLine = getRightLineByFileName(readerTestFiles[0]);

    EXPECT_EQ(lineRead, rightLine) << "Unexpected line was read";
//    if (lineRead == rightLine) {
//        std::cout << "Lines coincide. Line read: " << lineRead  << std::endl;
//    }
    readerWizard.closeFile();
}

TEST(ReaderTest, IsFileEmptyTest) {
    Reader readerWizard;
    readerWizard.openFile(readerTestFiles[0]);
    EXPECT_EQ(readerWizard.isFileEmpty(), false);
    EXPECT_EQ(readerWizard.inputFile.tellg(), 0);
}

TEST(ReaderTest, HasNextLineTest) {
    Reader readerWizard;
    createTestFileType2(readerTestFiles[1]);
    readerWizard.openFile(readerTestFiles[1]);

    std::streampos pos1 = readerWizard.inputFile.tellg();
    bool answer1 = readerWizard.hasNextLine();
    std::streampos pos2 = readerWizard.inputFile.tellg();

    bool rightAnswer1;
    if (!readerWizard.readLine().empty()) {
        rightAnswer1 = true;
    }
    else {
        rightAnswer1 = false;
    }

    EXPECT_EQ(answer1, rightAnswer1);
    if (answer1 == rightAnswer1) {
        std::cout << "Answer: " << answer1 << std::endl;
    }

    EXPECT_EQ(pos1, pos2);
    if (pos1 == pos2) {
        std::cout << "Position saved" << std::endl;
    }

    readerWizard.closeFile();
}

TEST(ReaderTest, AllLineasReadTest) {
    Reader readerWizard;
    readerWizard.inputFile.open(readerTestFiles[0]);

    readerWizard.readAllLines();
    EXPECT_EQ(readerWizard.allLines.size(), 3);
}

TEST(ReaderTest, GetNumberLinesReadTest) {
    Reader readerWizard;
    readerWizard.inputFile.open(readerTestFiles[0]);

    unsigned long long lines_read;
    readerWizard.readLine();
    lines_read = readerWizard.getNumberLinesRead();
    EXPECT_EQ(1, lines_read);
}

#endif //INC_0B_READERTESTS_H
