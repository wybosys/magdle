#!/usr/bin/env bash

export PREFIX=`realpath .`

./build-sqlite
./build-jsoncpp
./build-opencv