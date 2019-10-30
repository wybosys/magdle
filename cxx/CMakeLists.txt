cmake_minimum_required(VERSION 3.10)
project(cxx)

set(CMAKE_CXX_STANDARD 17)

set(COMMON_IMPL
        magdle.cpp magdle.h
        storage.cpp
        similar.h similar.cpp
        kernel.h kernel.cpp
        config.cpp config.h
        logger.cpp logger.h
        dataset.cpp dataset.h
        dataset_images.cpp dataset_images.h
        stringt.h stringt.cpp
        json.cpp json.h
        variant.cpp variant.h
        timet.cpp timet.h
        sqlite.cpp
        )

set(OPENCV_IMPL ${COMMON_IMPL}
        similar_ocv.cpp similar_ocv.h)

add_library(magdle STATIC ${OPENCV_IMPL})
add_library(sqlite_ext STATIC sqlite_json1.c)

include_directories(./)
link_directories(./cmake-build-debug)

set(DEPENDS_OPENCV opencv_core opencv_imgcodecs opencv_imgproc)
set(DEPENDS magdle sqlite_ext sqlite3 jsoncpp ${DEPENDS_OPENCV})

add_executable(rmdup rmdup/rmdup.cpp)
target_link_libraries(rmdup ${DEPENDS})

add_executable(storage storage/storage.cpp)
target_link_libraries(storage ${DEPENDS})