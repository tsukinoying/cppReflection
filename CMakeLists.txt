cmake_minimum_required(VERSION 3.6)
project(fun)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Reflex.h Reflex.cpp)
add_executable(fun ${SOURCE_FILES})