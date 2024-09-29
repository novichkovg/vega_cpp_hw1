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

add_executable(main src/main.cpp src/add.cpp)

################################
# Google Test
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
# target_link_libraries(my_app PRIVATE Threads::Threads)

enable_testing()
find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(runUnitTests src/add.t.cpp src/add.cpp)

target_link_libraries(runUnitTests gtest gtest_main Threads::Threads)
gtest_discover_tests(runUnitTests)

add_test(runUnitTests runUnitTests)


find_package(benchmark REQUIRED)
add_executable(runBenchmark src/add.b.cpp src/add.cpp)
target_link_libraries(runBenchmark benchmark::benchmark Threads::Threads)