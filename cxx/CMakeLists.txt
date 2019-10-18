cmake_minimum_required(VERSION 3.10)
project(magdle)

set(CMAKE_CXX_STANDARD 17)

add_library(cxx SHARED magdle.cpp magdle.h storage.cpp similar.h similar.cpp similar_ocv.cpp)