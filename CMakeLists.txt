cmake_minimum_required(VERSION 3.12)

project(UnboundedInteger)

# Встановлюємо стандарт C++
set(CMAKE_CXX_STANDARD 11)

# Додаємо виконавчий файл для тестів
add_executable(tests tests.cpp)

# Додаткові налаштування, якщо вони потрібні для вашого проекту

# Команда для компіляції тестів
enable_testing()
add_test(NAME tests COMMAND tests)
