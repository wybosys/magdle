cmake_minimum_required(VERSION 3.10)
project(cxx)

set(CMAKE_CXX_STANDARD 17)

set(COMMON_IMPL magdle.cpp magdle.h
        storage.cpp
        similar.h similar.cpp
        kernel.h kernel.cpp
        config.cpp config.h
        logger.cpp logger.h
        dataset.cpp dataset.h
        dataset_images.cpp dataset_images.h
        stringt.h stringt.cpp
        json.cpp json.h)

set(OPENCV_IMPL ${COMMON_IMPL}
        similar_ocv.cpp similar_ocv.h)

add_library(magdle SHARED ${OPENCV_IMPL})

include_directories(./)
link_directories(./cmake-build-debug)

set(DEPENDS magdle sqlite3 jsoncpp opencv_core opencv_imgcodecs)

add_executable(rmdup rmdup/rmdup.cpp)
target_link_libraries(rmdup ${DEPENDS})
