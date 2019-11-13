cmake_minimum_required(VERSION 3.10)
project(cxx)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(IMPLS
        magdle.cpp magdle.h
        storage.cpp
        kernel.h kernel.cpp
        config.cpp config.h
        logger.cpp logger.h
        dataset.cpp dataset.h
        dataset_images.cpp dataset_images.h
        stringt.h stringt.cpp
        json.cpp json.h
        variant.cpp variant.h
        timet.cpp timet.h
        threadt.h threadt.cpp
        object.h object.cpp
        linear.h linear.cpp
        imageinfo.h imageinfo.cpp
        similar.h similar.cpp
        faces.h faces.cpp
        worker.h worker.cpp
        sqlite.cpp
        )

# OPENCV实现
set(IMPLS_OPENCV
        ocv.h ocv.cpp
        similar_ocv.h similar_ocv.cpp
        faces_ocv.h faces_ocv.cpp)

# IOS实现
set(IMPLS_IOS
        similar_ios.h similar_ios.mm
        faces_ios.h faces_ios.mm)

# MACOS实现
set(IMPLS_MACOS
        similar_macos.h similar_macos.mm
        faces_macos.h faces_macos.mm)

# 链接库
set(DEPENDS_SYS dl pthread)
set(DEPENDS magdle sqlite3 jsoncpp ${DEPENDS_SYS})
set(DEPENDS_OPENCV opencv_core opencv_imgcodecs opencv_imgproc jpeg tiff z)

# 根据系统筛选编译文件
list(APPEND IMPLS ${IMPLS_3RD})
if (UNIX)
    list(APPEND IMPLS ${IMPLS_OPENCV})
    list(APPEND DEPENDS ${DEPENDS_OPENCV})
endif ()

# 基础类库
add_library(magdle STATIC ${IMPLS})

# 编译引入目录
include_directories(./)
include_directories(../3rd/include)
link_directories(../3rd/lib)
link_directories(./cmake-build-debug)

# 相似图片过滤
add_executable(rmdup rmdup/rmdup.cpp)
target_link_libraries(rmdup ${DEPENDS})

# 保留卡片
add_executable(cards cards/cards.cpp)
target_link_libraries(cards ${DEPENDS})

# 人脸检测
add_executable(faces faces/faces.cpp)
target_link_libraries(faces ${DEPENDS})

# 数据库存储测试
add_executable(storage storage/storage.cpp)
target_link_libraries(storage ${DEPENDS})