cmake_minimum_required(VERSION 3.27)
project(Task1)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(1b main.cpp
        GoogleTests/BitArrayTests.h
        BitArray.cpp
        BitArray.h
        BitReference.cpp
        BitReference.h
)

target_link_libraries(1b GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(1b)
