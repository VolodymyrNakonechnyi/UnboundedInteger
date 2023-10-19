cmake_minimum_required(VERSION 3.10)

project(UnboundedInteger)

set(CMAKE_CXX_STANDARD 11)

add_executable(Tests/tests Tests/tests.cpp)
add_library(UnboundedInteger UnboundedInteger/UnboundedInteger.h)

target_link_libraries(Tests/tests UnboundedInteger)
