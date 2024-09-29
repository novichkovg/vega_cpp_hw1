cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(hw1_cpp VERSION 1.0)


include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# ====================================================================   
# if you need to add all files in the src directory, use these 2 line:
#
#file(GLOB_RECURSE SRC_FILES src/*.cpp)
#add_executable(hw1 ${SRC_FILES})
# ====================================================================   

################################
# Application
add_executable(main src/main.cpp src/add.cpp)

################################
# Google Test

include(FetchContent)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)


FetchContent_Declare (
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.2
)

FetchContent_MakeAvailable(googletest)
FetchContent_GetProperties(googletest)

enable_testing()

include(GoogleTest)
# find_package(GTest REQUIRED)

add_executable(runUnitTests src/add.t.cpp src/add.cpp)
target_link_libraries(runUnitTests gtest gtest_main Threads::Threads)
gtest_discover_tests(runUnitTests)
add_test(runUnitTests runUnitTests)


FetchContent_Declare(
  benchmark
  GIT_REPOSITORY https://github.com/google/benchmark.git
  GIT_TAG v1.9.0
)

FetchContent_MakeAvailable(benchmark)
FetchContent_GetProperties(benchmark)

# find_package(benchmark REQUIRED)

include(benchmark)
add_executable(runBenchmark src/add.b.cpp src/add.cpp)
target_link_libraries(runBenchmark benchmark::benchmark Threads::Threads)