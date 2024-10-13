#include <iostream>
#include <gtest/gtest.h>
#include "GoogleTests/readerTests.h"          // This directive is actually used! I checked!
#include "GoogleTests/splitterTests.h"        // This directive is also actually used! I checked!
#include "GoogleTests/wordsStatisticsTests.h" // This directive is also actually used! I checked!
#include "GoogleTests/csvFileWriterTests.h"   // This directive is also actually used! I checked!

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
