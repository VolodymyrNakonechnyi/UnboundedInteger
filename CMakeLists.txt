cmake_minimum_required(VERSION 3.12)

project(UnboundedInteger)

set(CMAKE_CXX_STANDARD 17)

add_executable(tests Tests/tests.cpp)

enable_testing()
add_test(NAME tests COMMAND tests)
