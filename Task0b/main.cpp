#include <iostream>
#include <gtest/gtest.h>
#include "GoogleTests/readerTests.h"
#include "GoogleTests/splitterTests.h"
#include "GoogleTests/wordsStatisticsTests.h"
#include "GoogleTests/csvFileWriterTests.h"

const size_t FLASH_SIZE = 50;

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
//
//    Reader file;
//    file.openFile("input1.txt");
//
//    WordsStatistics statistics;
//
//    std::vector <string> splitted;
//    std::string line;
//    for (int i = 0; i < 1000; i++) {
//        line = file.readLine();
//        splitted = Splitter::splitLine(line);
//
//        if (splitted.empty()) {
//            continue;
//        }
//
//        for (const auto& pLine : splitted) {
//            statistics.addWord(pLine);
//        }
//    }
//
//    CSVFileWriter writer;
//    writer.openFile("word_statistics.csv");
//    writer.write({"Word", "Count", "Frequency"});
//
//    string word = "first";
//    std::pair<int, float> stat = statistics.getStatisticsByWord(word);
//    writer.write({word, std::to_string(stat.first), std::to_string(stat.second)});
//
//    for (auto const &pushWord : statistics.getWordsInStatistics()) {
//        auto res = statistics.getStatisticsByWord(pushWord);
//        writer.write({pushWord, std::to_string(res.first), std::to_string(res.second)});
//    }
//
//    std::cout << "Number of words: " << statistics.getNumberWords() << std::endl;
//    std::cout << "Word statistics written to word_statistics.csv" << std::endl;
//
//    file.closeFile();
//    writer.closeFile();

    return RUN_ALL_TESTS();
}