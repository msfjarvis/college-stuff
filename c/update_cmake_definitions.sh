#!/usr/bin/env bash

echo 'cmake_minimum_required(VERSION 3.4.1)' > CMakeLists.txt
for f in $(find . -maxdepth 1 -type f -name '*.c'); do
    printf 'add_executable(%s %s)\n' "$(basename $f | sed 's/\.c//g')" "$(basename $f)" >> CMakeLists.txt
done
