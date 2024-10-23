#ifndef INC_0B_READERTESTS_H
#define INC_0B_READERTESTS_H

#include <gtest/gtest.h>
#include <fstream>
#include "../Reader.h"

std::string readerTestFiles[] = {"test_file1.txt", "test_file2.txt"};

void createTestFileType1 (std::string newFileName) {
    std::ofstream test_file(newFileName);
    test_file << "First Line\nSecond Line\nThird line";
    test_file.close();
}

void createTestFileType2 (std::string newFileName) {
    std::ofstream test_file(newFileName);
    test_file << "";
    test_file.close();
}

TEST(ReaderTest, GetFileTest) {
    Reader readerWizard;
    ASSERT_TRUE(!readerWizard.getFile());
}

TEST(ReaderTest, OpenFileTest) {
    Reader readerWizard;
    createTestFileType1(readerTestFiles[0]);
    readerWizard.openFile(readerTestFiles[0]);

    ASSERT_TRUE(readerWizard.getFile()->is_open());
}

TEST(ReaderTest, CloseFileTest) {
    Reader readerWizard;
    readerWizard.openFile(readerTestFiles[0]);
    readerWizard.closeFile();

    ASSERT_TRUE(readerWizard.getFile() == nullptr);
}

TEST(ReaderTest, ReadLineTest) {
    Reader readerWizard;
    readerWizard.openFile(readerTestFiles[0]);

    EXPECT_EQ("First Line", readerWizard.readLine());
    EXPECT_EQ("Second Line", readerWizard.readLine());
    EXPECT_EQ("Third line", readerWizard.readLine());
}

TEST(ReaderTest, HasNextLineTest) {
    Reader readerWizard;

    readerWizard.openFile(readerTestFiles[0]);
    EXPECT_EQ(readerWizard.hasNextLine(), true);

    readerWizard.closeFile();
}

TEST(ReaderTest, GetAllLinesReadTest) {
    Reader readerWizard;
    readerWizard.openFile(readerTestFiles[0]);
    EXPECT_EQ(readerWizard.getAllLinesRead().size(), 0);

    readerWizard.readLine();
    EXPECT_EQ(readerWizard.getAllLinesRead().size(), 1);
    readerWizard.closeFile();
}

TEST(ReaderTest, GetNumberLinesMetTest) {
    Reader readerWizard;
    readerWizard.openFile(readerTestFiles[0]);
    EXPECT_EQ(readerWizard.getNumberLinesRead(), 0);

    readerWizard.readLine();
    EXPECT_EQ(readerWizard.getNumberLinesRead(), 1);
    readerWizard.closeFile();
}

TEST(ReaderTest, IsFileEmptyTest) {
    Reader reader;
    reader.openFile(readerTestFiles[1]);
    EXPECT_EQ(reader.isFileEmpty(), false);
    reader.closeFile();
}

#endif //INC_0B_READERTESTS_H
