# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(mydynamiclib LANGUAGES CXX)

# generate a library from sources
add_library(mydynamiclib SHARED
    mydynamiclibexports.h
    first.cpp
    second.cpp
    third.cpp
    fourth.cpp
    )

