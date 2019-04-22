cmake_minimum_required(VERSION 3.12)
project(ed1_lista C)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES src/lista.c test/lista_test.c)

add_executable(ed1_lista ${SOURCE_FILES})
