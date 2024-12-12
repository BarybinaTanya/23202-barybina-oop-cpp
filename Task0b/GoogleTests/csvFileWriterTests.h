#ifndef INC_0B_CSVFILEWRITERTESTS_H
#define INC_0B_CSVFILEWRITERTESTS_H

#include <gtest/gtest.h>
#include <fstream>
#include "../CSVFileWriter.h"

#include "CSVFileWriter.h"
#include <gtest/gtest.h>
#include <fstream>

TEST(CSVFileWriterTest, OpenFileSuccess) {
    CSVFileWriter writer;
    ASSERT_NO_THROW(writer.openFile("test.csv"));
    writer.closeFile();
}

TEST(CSVFileWriterTest, OpenFileInvalidExtension) {
    CSVFileWriter writer;
    ASSERT_THROW(writer.openFile("test.txt"), std::invalid_argument);
}

TEST(CSVFileWriterTest, WriteToFile) {
    CSVFileWriter writer;
    writer.openFile("test.csv");

    std::vector<string> data = {"one", "two", "three"};
    ASSERT_NO_THROW(writer.write(data));

    writer.closeFile();

    std::ifstream inputFile("test.csv");
    ASSERT_TRUE(inputFile.is_open());

    string line;
    std::getline(inputFile, line);
    EXPECT_EQ(line, "one,two,three");
    inputFile.close();
}

TEST(CSVFileWriterTest, WriteEmptyVector) {
    CSVFileWriter writer;
    writer.openFile("test.csv");

    std::vector<string> emptyData;
    ASSERT_NO_THROW(writer.write(emptyData));

    writer.closeFile();

    std::ifstream inputFile("test.csv");
    ASSERT_TRUE(inputFile.is_open());

    string line;
    EXPECT_FALSE(std::getline(inputFile, line));
    inputFile.close();
}

TEST(CSVFileWriterTest, WriteToClosedFile) {
    CSVFileWriter writer;
    writer.openFile("test.csv");
    writer.closeFile();

    std::vector<string> data = {"one", "two", "three"};
    ASSERT_THROW(writer.write(data), std::ios_base::failure);
}

TEST(CSVFileWriterTest, CloseFileTwice) {
    CSVFileWriter writer;
    writer.openFile("test.csv");

    ASSERT_NO_THROW(writer.closeFile());
    ASSERT_NO_THROW(writer.closeFile());
}


#endif //INC_0B_CSVFILEWRITERTESTS_H
