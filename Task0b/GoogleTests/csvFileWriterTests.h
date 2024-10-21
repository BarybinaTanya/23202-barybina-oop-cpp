#ifndef INC_0B_CSVFILEWRITERTESTS_H
#define INC_0B_CSVFILEWRITERTESTS_H

#include <gtest/gtest.h>
#include <fstream>
#include "../CSVFileWriter.h"

TEST(CSVFileWriterTest, OpenFileAndGetFileTest) {
    CSVFileWriter writer;
    writer.openFile("writer_test1.csv");
    EXPECT_EQ(writer.getFile()->is_open(), true);
    writer.getFile()->close();
}

TEST(CSVFileWriterTest, CloseFile) {
    CSVFileWriter writer;
    writer.openFile("writer_test1.csv");
    writer.closeFile();
    EXPECT_EQ(writer.getFile() == nullptr, true);
}

TEST(CSVFileWriterTest, WriteTest) {
    CSVFileWriter writer;
    writer.openFile("writer_test1.csv");
    std::vector<string> to_write = {"hello,1,0.333333", "new,1,0.333333", "world,1,0.333333"};
    writer.write(to_write);
    writer.closeFile();

    std::ifstream file("writer_test1.csv");
    EXPECT_EQ(file.is_open(), true);
    string line;
    std::getline(file, line);
    EXPECT_EQ(line.empty(), false);
    EXPECT_EQ(line, "hello,1,0.333333");
}

#endif //INC_0B_CSVFILEWRITERTESTS_H
