#ifndef INC_0B_SPLITTERTESTS_H
#define INC_0B_SPLITTERTESTS_H

#include <gtest/gtest.h>
#include <fstream>
#include "../Splitter.h"
#include "../Reader.h"

std::string splitterTestFiles[] = {"test_file1.txt", "test_file2.txt", "test_file3.txt", "test_file4.txt"};

void createTestFileType3 (std::string newFileName) {
    std::ofstream test_file(newFileName);
    test_file << "Hello_I'm_Tanya!_I'm+++learning+++c++";
    test_file.close();
}

TEST(SpliterTests, DelimiterSetterTest) {
    Splitter splitWizard;
    splitWizard.addDelimiter("__");
    splitWizard.addDelimiter("++");
    EXPECT_EQ(splitWizard.getDelimiters(), "__|\\+\\+");
}

void printSplittedText(std::vector<string> splittedText) {
    int it = 0;
    while (it < splittedText.size()) {
        std::cout << splittedText[it] << std::endl;
        it++;
    }
}

TEST(SpliterTests, SplitLineTest) {
    createTestFileType3(splitterTestFiles[2]);

    Reader readWizard;
    readWizard.openFile(splitterTestFiles[2]);
    readWizard.readAllLines();

    Splitter splitWizard;
    splitWizard.addDelimiter("_");
    splitWizard.addDelimiter("+++");

    splitWizard.splitLine(readWizard.allLines[0]);
    EXPECT_EQ(splitWizard.splittedText.size(), 6);

    //printSplittedText(splitWizard.splittedText);

    Reader readWizard2;
    readWizard2.openFile(splitterTestFiles[0]);
    readWizard2.readAllLines();

    Splitter splitWizard2;
    splitWizard2.splitLine(readWizard2.allLines[0]);
    splitWizard2.splitLine(readWizard2.allLines[1]);
    EXPECT_EQ(splitWizard2.splittedText.size(), 4);

    //printSplittedText(splitWizard2.splittedText);

    readWizard.closeFile();
    readWizard2.closeFile();
}

TEST(SpliterTests, SplitTextTest) {
    Reader readWizard;
    readWizard.openFile(splitterTestFiles[0]);
    readWizard.readAllLines();

    Splitter splitWizard;
    splitWizard.splitText(readWizard.allLines);
    EXPECT_EQ(11, splitWizard.splittedText.size());

    //printSplittedText(splitWizard.splittedText);

    readWizard.closeFile();
}

TEST(SpliterTests, RemoveAllDelimitersTest) {
    Splitter splitWizard;
    splitWizard.addDelimiter("__");
    splitWizard.addDelimiter("++");
    EXPECT_EQ(splitWizard.getDelimiters(), "__|\\+\\+");

    splitWizard.removeAllDelimiters();
    EXPECT_EQ(splitWizard.getDelimiters(), "");
}

TEST(SpliterTests, RemoveDelimiterTest) {
    Splitter splitWizard;
    splitWizard.addDelimiter("__");
    splitWizard.addDelimiter("++");

    splitWizard.removeDelimiter("++");
    EXPECT_EQ(splitWizard.getDelimiters(), "__");
    splitWizard.removeDelimiter("__");
    EXPECT_EQ(splitWizard.getDelimiters(), "");

    splitWizard.addDelimiter("__");
    splitWizard.addDelimiter("++");
    splitWizard.addDelimiter("**");

    splitWizard.removeDelimiter("++");
    EXPECT_EQ(splitWizard.getDelimiters(), "__|**");

    splitWizard.addDelimiter("\n");
    EXPECT_EQ(splitWizard.getDelimiters(), "__|**|\\n");
}

#endif //INC_0B_SPLITTERTESTS_H
