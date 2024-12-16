#ifndef INC_0B_READERTESTS_H
#define INC_0B_READERTESTS_H

#include <gtest/gtest.h>
#include <fstream>
#include <cstdio>
#include "../Reader.h"

// Helper function to create a temporary file
std::string createTempFile(const std::string& content) {
    const std::string fileName = "temp_test_file.txt";
    std::ofstream tempFile(fileName);
    tempFile << content;
    tempFile.close();
    return fileName;
}

// Helper function to delete a temporary file
void deleteTempFile(const std::string& fileName) {
    std::remove(fileName.c_str());
}

// Test for the openFile method
//TEST(ReaderTest, OpenFileTest) {
//    Reader reader;
//    std::string fileName = createTempFile("Test content\nAnother line\n");
//
//    EXPECT_NO_THROW(reader.openFile(fileName));
//
//    EXPECT_THROW(reader.openFile("nonexistent_file.txt"), std::runtime_error);
//
//    reader.closeFile();
//    deleteTempFile(fileName);
//}

// Test for the closeFile method
TEST(ReaderTest, CloseFileTest) {
    Reader reader;
    std::string fileName = createTempFile("Test content\n");
    reader.openFile(fileName);

    EXPECT_NO_THROW(reader.closeFile());
    EXPECT_NO_THROW(reader.closeFile()); // Ensure no exception when closing already closed file

    deleteTempFile(fileName);
}

// Test for the isFileEmpty method
//TEST(ReaderTest, IsFileEmptyTest) {
//    Reader reader;
//    std::string emptyFile = createTempFile("");
//    std::string nonEmptyFile = createTempFile("Not empty\n");
//
//    reader.openFile(emptyFile);
//    EXPECT_TRUE(reader.isFileEmpty());
//    reader.closeFile();
//
//    reader.openFile(nonEmptyFile);
//    EXPECT_FALSE(reader.isFileEmpty());
//    reader.closeFile();
//
//    deleteTempFile(emptyFile);
//    deleteTempFile(nonEmptyFile);
//}

// Test for the readLine method
TEST(ReaderTest, ReadLineTest) {
    Reader reader;
    std::string fileName = createTempFile("Line1\nLine2\n");

    reader.openFile(fileName);

    EXPECT_EQ(reader.readLine(), "Line1");
    EXPECT_EQ(reader.readLine(), "Line2");
    EXPECT_EQ(reader.readLine(), ""); // Ensure empty string for EOF

    EXPECT_EQ(reader.getNumberLinesRead(), 2);

    reader.closeFile();
    deleteTempFile(fileName);
}

// Test for the hasNextLine method
TEST(ReaderTest, HasNextLineTest) {
    Reader reader;
    std::string fileName = createTempFile("Line1\nLine2\n");

    reader.openFile(fileName);

    EXPECT_TRUE(reader.hasNextLine());
    reader.readLine();
    EXPECT_TRUE(reader.hasNextLine());
    reader.readLine();
    EXPECT_FALSE(reader.hasNextLine());

    reader.closeFile();
    deleteTempFile(fileName);
}

// Test for the getAllLinesRead method
TEST(ReaderTest, GetAllLinesReadTest) {
    Reader reader;
    std::string fileName = createTempFile("Line1\nLine2\nLine3\n");

    reader.openFile(fileName);

    reader.readLine();
    reader.readLine();

    auto allLines = reader.getAllLinesRead();
    EXPECT_EQ(allLines.size(), 2);
    EXPECT_EQ(allLines[0], "Line1");
    EXPECT_EQ(allLines[1], "Line2");

    reader.closeFile();
    deleteTempFile(fileName);
}

// Test for the getNumberLinesRead method
TEST(ReaderTest, GetNumberLinesReadTest) {
    Reader reader;
    std::string fileName = createTempFile("Line1\nLine2\n");

    reader.openFile(fileName);

    reader.readLine();
    reader.readLine();

    EXPECT_EQ(reader.getNumberLinesRead(), 2);

    reader.closeFile();
    deleteTempFile(fileName);
}

// Test for the getFile method
TEST(ReaderTest, GetFileTest) {
    Reader reader;
    std::string fileName = createTempFile("Test content\n");

    reader.openFile(fileName);

    EXPECT_NE(reader.getFile(), nullptr); // File should be open

    reader.closeFile();
    EXPECT_EQ(reader.getFile(), nullptr); // File should be closed

    deleteTempFile(fileName);
}

#endif //INC_0B_READERTESTS_H
