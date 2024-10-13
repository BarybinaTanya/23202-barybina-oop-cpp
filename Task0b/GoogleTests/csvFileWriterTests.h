#ifndef INC_0B_CSVFILEWRITERTESTS_H
#define INC_0B_CSVFILEWRITERTESTS_H

#include <gtest/gtest.h>
#include <fstream>
#include "../CSVFileWriter.h"
#include "../Reader.h"
#include "../WordsStatistics.h"

TEST (CSVFileWriterTest, OpenOrCreateOutputFileTest) {
    CSVFileWriter fileWriter;
    fileWriter.openOrCreateOutputFile("file_4_statistics.csv");
    EXPECT_EQ(fileWriter.outputFile.is_open(), true);
    fileWriter.outputFile.close();
}

TEST (CSVFileWriterTest, CloseOutputFileTest) {
    CSVFileWriter fileWriter;
    fileWriter.openOrCreateOutputFile("file_4_statistics.csv");
    fileWriter.closeOutputFile();
    EXPECT_EQ(fileWriter.outputFile.is_open(), false);
}

TEST (CSVFileWriterTest, WriteCSVFileHeaderTest) {
    CSVFileWriter fileWriter;
    fileWriter.openOrCreateOutputFile("file_4_statistics.csv");
    fileWriter.writeCSVFileHeader("Word,Frequency,Frequency-%");
    fileWriter.closeOutputFile();

    Reader readerWizard;
    readerWizard.openFile("file_4_statistics.csv");
    EXPECT_EQ(readerWizard.readLine(), "Word,Frequency,Frequency-%");
    readerWizard.closeFile();
}

TEST (CSVFileWriterTest, WriteFrequencyMapToCSVTest) {
    Reader reader;
    reader.openFile("test_file4.txt");
    reader.readAllLines();
    reader.closeFile();

    Splitter splitter;
    splitter.splitText(reader.allLines);

    WordsStatistics wordsStatisticsGetter;
    wordsStatisticsGetter.getFullFrequencyMap(splitter.splittedText);

    CSVFileWriter fileWriter;
    fileWriter.openOrCreateOutputFile("file_4_statistics.csv");
    fileWriter.writeFrequencyMapToCSV(wordsStatisticsGetter.wordsFrequencyStatistics);
    fileWriter.closeOutputFile();

    Reader resultFileReader;
    resultFileReader.openFile("file_4_statistics.csv");
    resultFileReader.readLine();
    EXPECT_EQ(resultFileReader.allLines[0], "Word,Frequency,%Frequency");
    resultFileReader.readLine();
    EXPECT_EQ(resultFileReader.allLines[1], "everything,4,0.333333");
}

#endif //INC_0B_CSVFILEWRITERTESTS_H
