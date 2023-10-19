cmake_minimum_required(VERSION 3.10)

project(UnboundedInteger)

set(CMAKE_CXX_STANDARD 11)

# Додаємо ваші файли джерел та тести
add_executable(Tests/tests Tests/tests.cpp)
add_library(UnboundedInteger UnboundedInteger/UnboundedInteger.h)

# Лінкуємо ваші тести з бібліотекою
target_link_libraries(Tests/tests UnboundedInteger)
