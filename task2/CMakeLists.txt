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
        GoogleTests/GameStateTests.h

        GameState.cpp
        GameState.h

        StateCounter.cpp
        StateCounter.h
        MatrixProxy.h
        RuleParser.cpp
        RuleParser.h
        RuleParser.h
)

target_link_libraries(t2 GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(t2)