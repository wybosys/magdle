cmake_minimum_required(VERSION 3.10)
project(cxx)

set(CMAKE_CXX_STANDARD 17)

add_library(magdle
        SHARED
        magdle.cpp magdle.h
        storage.cpp
        similar.h similar.cpp
        similar_ocv.cpp
        kernel.h kernel.cpp
        config.cpp config.h
        logger.cpp logger.h
        dataset.cpp dataset.h
        dataset_images.cpp dataset_images.h
        stringt.h stringt.cpp
        json.cpp json.h
        )

include_directories(./)
link_directories(./cmake-build-debug)

add_executable(rmdup rmdup/rmdup.cpp)
target_link_libraries(rmdup magdle sqlite3 jsoncpp)
