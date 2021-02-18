cmake_minimum_required(VERSION 3.17)
project(ChatProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(ChatProject main.cpp tests/messageTest.cpp classes/Message.cpp classes/Message.h tests/userTest.cpp classes/User.cpp classes/User.h classes/Chat.cpp classes/Chat.h tests/chatTest.cpp)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)
target_link_libraries(ChatProject gtest gtest_main)