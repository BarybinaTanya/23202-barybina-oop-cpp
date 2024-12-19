cmake_minimum_required(VERSION 3.27)
project(task2)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(t2 main.cpp
        GameState.cpp
        GameState.h
        GoogleTests/GameStateTests.h

        StateCounter.cpp
        StateCounter.h
        GoogleTests/StateCounterTests.h

        MatrixProxy.cpp
        MatrixProxy.h

        UniverseCharacteristicsParser.cpp
        UniverseCharacteristicsParser.h
        GoogleTests/UniverseCharacteristicsParserTests.h

        Reader.cpp
        Reader.h

        GameCommandPrompt.cpp
        GameCommandPrompt.h
        GoogleTests/GameCommandPromptTests.h

        UniverseConfig.cpp
        UniverseConfig.h

        Command.h

        TickCommand.h

        DumpCommand.h

        FileWriter.cpp
        FileWriter.h
)

target_link_libraries(t2 GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(t2)