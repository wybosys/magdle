#!/usr/bin/env bash

PREFIX=`realpath .`

cd sqlite
make clean
./configure --prefix=$PREFIX --disable-shared --disable-static-shell --disable-dependency-tracking --enable-json1 --enable-fts5 --disable-fts4 --disable-fts3
make install
make clean
cd -

