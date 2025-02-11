cmake_minimum_required(VERSION 3.27)
project(Task0b)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /STACK:16777216")

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(0b main.cpp
        Reader.cpp
        Reader.h
        GoogleTests/readerTests.h

        Splitter.cpp
        Splitter.h
        GoogleTests/splitterTests.h

        WordsStatistics.cpp
        WordsStatistics.h
        GoogleTests/wordsStatisticsTests.h

        CSVFileWriter.cpp
        CSVFileWriter.h
        GoogleTests/csvFileWriterTests.h)

target_link_libraries(0b GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(0b)

set_property(TEST PROPERTY TIMEOUT 0)