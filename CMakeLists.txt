cmake_minimum_required(VERSION 3.14)

## Project-wide setup
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

project(hw1_cpp VERSION 1.0)

include(FetchContent)

# Externally provided libraries
FetchContent_Declare(googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main)

FetchContent_Declare(googlebenchmark
        GIT_REPOSITORY https://github.com/google/benchmark.git
        GIT_TAG main) # need main for benchmark::benchmark

FetchContent_MakeAvailable(
        googletest
        googlebenchmark)



# include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


################################
# Application
add_executable(main src/main.cpp src/add.cpp)

################################
# Google Test
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
enable_testing()

# include(GoogleTest)
# find_package(GTest REQUIRED)

add_executable(runUnitTests src/add.t.cpp src/add.cpp)
target_link_libraries(runUnitTests gtest gtest_main Threads::Threads)

# gtest_discover_tests(runUnitTests)
# add_test(runUnitTests runUnitTests)
# find_package(benchmark REQUIRED)

################################
# Google Benchmark
#include(benchmark)

add_executable(runBenchmark src/add.b.cpp src/add.cpp)
target_link_libraries(runBenchmark benchmark::benchmark Threads::Threads)