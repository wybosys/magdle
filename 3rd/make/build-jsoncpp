#!/usr/bin/env bash

PREFIX=`realpath .`

cd jsoncpp
if [ ! -e build ]; then
    mkdir build
fi
cd build
cmake . .. -DCMAKE_INSTALL_PREFIX=$PREFIX -DJSONCPP_WITH_TESTS=no
make
make install

