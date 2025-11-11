cmake_minimum_required(VERSION 4.1.2)
project(apm)
set(CMAKE_C_STANDARD 17)

set(SOURCE_FILES src/main.c src/utils.c)

add_executable(apm ${SOURCE_FILES})
