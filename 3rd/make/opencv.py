#!/usr/bin/env bash
PREFIX=`realpath .`

cd opencv

if [ ! -e build ]; then
    mkdir build
fi
cd build
cmake . .. -DCMAKE_INSTALL_PREFIX=$PREFIX -DBUILD_JAVA=NO -DBUILD_SHARED_LIBS=NO -DBUILD_TESTS=NO -DBUILD_PERF_TESTS=NO -DBUILD_opencv_python2=NO -DBUILD_opencv_python3=NO -DBUILD_opencv_apps=NO -DBUILD_DOCS=NO -DBUILD_opencv_data=NO -DBUILD_opencv_doc=NO
make
make install