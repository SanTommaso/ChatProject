cmake_minimum_required(VERSION 3.17)
project(ChatProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(ChatProject main.cpp tests/messageTest.cpp classes/Message.cpp classes/Message.h)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)
target_link_libraries(ChatProject gtest gtest_main)