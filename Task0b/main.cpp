#include <iostream>
#include <gtest/gtest.h>
#include "GoogleTests/readerTests.h"
#include "GoogleTests/splitterTests.h"
#include "GoogleTests/wordsStatisticsTests.h"
#include "GoogleTests/csvFileWriterTests.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    Reader reader;
    reader.openFile("input1.txt");

    Splitter splitter;
    WordsStatistics statistics;
    CSVFileWriter writer;;

    while (reader.hasNextLine()) {
        string line = reader.readLine();
        std::vector<string> splitted_line = splitter.splitLine(line);
        statistics.addWords(splitted_line);
    }

    std::cout << "Lines read: "<< reader.getNumberLinesRead() <<  std::endl;
    string word = "first";
    std::pair<int, float> stat = statistics.getStatisticsByWord(word);

    writer.openFile("output2.csv");
    std::vector<string> to_write;
    to_write.push_back(word);
    to_write.push_back(std::to_string(stat.first));
    to_write.push_back(std::to_string(stat.second));

    writer.write(to_write);

    reader.closeFile();
    writer.closeFile();

    return RUN_ALL_TESTS();
}
