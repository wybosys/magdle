cmake_minimum_required(VERSION 3.10)
project(cxx)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(IMPLS
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
        threadt.h threadt.cpp
        object.h object.cpp
        )

set(IMPLS_OPENCV
        ocv.h ocv.cpp
        similar_ocv.cpp similar_ocv.h)

set(IMPLS_IOS
        similar_ios.h similar_ios.mm)

set(IMPLS_MACOS
        similar_macos.h similar_macos.mm)

set(DEPENDS magdle sqlite_ext sqlite3 jsoncpp)
set(DEPENDS_OPENCV opencv_core opencv_imgcodecs opencv_imgproc)

if (UNIX)
    list(APPEND IMPLS ${IMPLS_OPENCV})
    list(APPEND DEPENDS ${DEPENDS_OPENCV})
endif ()

add_library(magdle STATIC ${IMPLS})
add_library(sqlite_ext STATIC sqlite_json1.c)

include_directories(./)
link_directories(./cmake-build-debug)

add_executable(rmdup rmdup/rmdup.cpp)
target_link_libraries(rmdup ${DEPENDS})

add_executable(storage storage/storage.cpp)
target_link_libraries(storage ${DEPENDS})