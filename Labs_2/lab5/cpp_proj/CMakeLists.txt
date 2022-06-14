cmake_minimum_required(VERSION 3.22)
project(archive)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(archive
        FloatMatrix.h
        IntMatrix.h
        main.cpp
        TMatrix.h)
