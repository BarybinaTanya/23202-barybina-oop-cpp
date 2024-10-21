#include <iostream>
#include <gtest/gtest.h>
#include "GoogleTests/readerTests.h"          // This directive is actually used! I checked!
#include "GoogleTests/splitterTests.h"        // This directive is also actually used! I checked!
#include "GoogleTests/wordsStatisticsTests.h" // This directive is also actually used! I checked!
#include "GoogleTests/csvFileWriterTests.h"   // This directive is also actually used! I checked!

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

//    Reader reader;
//    reader.openFile("using.txt");
//
//    Splitter splitter;
//    WordsStatistics statistics;
//    CSVFileWriter writer;
//
//    while (reader.hasNextLine()) {
//        string line = reader.readLine();
//        std::vector<string> splitted_line = splitter.splitLine(line);
//        statistics.addWords(splitted_line);
//        std::vector<string> stat = statistics.getStatistics();
//        writer.openFile("using_res.csv");
//        writer.write(stat);
//    }
//    reader.closeFile();
//    writer.closeFile();

    return RUN_ALL_TESTS();
}
