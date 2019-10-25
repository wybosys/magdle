cmake_minimum_required(VERSION 3.10)
project(cxx)

set(CMAKE_CXX_STANDARD 17)

add_library(magdle
        SHARED
        magdle.cpp magdle.h
        storage.cpp
        similar.h similar.cpp
        similar_ocv.cpp
        )

include_directories(./)
link_directories(./cmake-build-debug)

add_executable(rmdup rmdup/rmdup.cpp)
target_link_libraries(rmdup magdle)
