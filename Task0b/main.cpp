#include <iostream>
#include <gtest/gtest.h>
#include "GoogleTests/readerTests.h"
#include "GoogleTests/splitterTests.h"
#include "GoogleTests/wordsStatisticsTests.h"
#include "GoogleTests/csvFileWriterTests.h"

const size_t FLASH_SIZE = 50;

void flushStatisticsToCSV(WordsStatistics &statistics, CSVFileWriter &writer) {
    for (auto const &word : (statistics.getWordsInStatistics())) {
        auto stat = statistics.getStatisticsByWord(word);
        writer.write({word, std::to_string(stat.first), std::to_string(stat.second)});
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    Reader file;
    file.openFile("input1.txt");

    CSVFileWriter writer;
    writer.openFile("word_statistics1.csv");
    writer.write({"Word", "Count", "Frequency"});

    WordsStatistics statistics;

    std::vector <string> splitted;
    std::string line;
    for (int i = 0; i < 10; i++) {
        line = file.readLine();
        splitted = Splitter::splitLine(line);

        if (splitted.empty()) {
            continue;
        }

        for (const auto& pLine : splitted) {
            statistics.addWord(pLine);
        }
    }
    flushStatisticsToCSV(statistics, writer);

    std::cout << "Number of words: " << statistics.getNumberWords() << std::endl;
    std::cout << "Word statistics written to word_statistics.csv" << std::endl;

    file.closeFile();
    writer.closeFile();

    return RUN_ALL_TESTS();
}