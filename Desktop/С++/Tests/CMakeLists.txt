cmake_minimum_required(VERSION 3.10)

project(UnboundedIntegerTests)

set(CMAKE_CXX_STANDARD 11)

set(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(${PROJECT_ROOT}/UnboundedInteger)

set(UNBOUNDED_INTEGER_HEADER ${PROJECT_ROOT}/UnboundedInteger/UnboundedInteger.h)

add_executable(tests ${PROJECT_ROOT}/tests/tests.cpp ${UNBOUNDED_INTEGER_HEADER})
