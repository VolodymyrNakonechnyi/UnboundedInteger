cmake_minimum_required(VERSION 3.10)

project(UnboundedIntegerTests)

set(CMAKE_CXX_STANDARD 11)

# Додаємо ваш тестовий файл
add_executable(tests ./Desktop/C++/Tests/tests.cpp)

# Додаємо ваш заголовний файл UnboundedInteger.h
include_directories(./Desktop/C++/UnboundedInteger)

# Лінкуємо ваш тестовий виконавчий файл з бібліотекою UnboundedInteger
target_link_libraries(tests UnboundedInteger)
