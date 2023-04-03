# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(mydynamiclib LANGUAGES C)

set(CMAKE_SHARED_LINKER_FLAGS "-Wl,--no-undefined")
#string(APPEND CMAKE_SHARED_LINKER_FLAGS " -Wl,--no-undefined")

# generate a library from sources
add_library(mydynamiclib SHARED
    mydynamiclibexports.h
    first.c
    second.c
    third.c
    fourth.c
    )

