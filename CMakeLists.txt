cmake_minimum_required(VERSION 3.5)
project(UsedToo)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE_FILES

        main.cpp)

add_executable(UsedToo ${SOURCE_FILES})
