cmake_minimum_required(VERSION 3.10)
project(AplikacjaCPP)

set(CMAKE_CXX_STANDARD 11)

# Dodaj katalogi src i lib/googletest do ścieżek przeszukiwania kompilatora
include_directories(src lib/googletest/googletest/include)

# Zdefiniuj źródła
set(SOURCE_FILES src/math_operations.cpp)

# Utwórz bibliotekę statyczną
add_library(math_operations ${SOURCE_FILES})

# Dodaj GoogleTest do projektu
add_subdirectory(lib/googletest)

# Zdefiniuj plik wykonywalny testów
add_executable(runTests test/test_math_operations.cpp)

# Linkowanie bibliotek GoogleTest i math_operations
target_link_libraries(runTests gtest gtest_main pthread math_operations)
