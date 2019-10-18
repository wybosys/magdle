cmake_minimum_required(VERSION 3.10)
project(cxx)

set(CMAKE_CXX_STANDARD 17)

add_library(cxx SHARED magdle.cpp magdle.h)