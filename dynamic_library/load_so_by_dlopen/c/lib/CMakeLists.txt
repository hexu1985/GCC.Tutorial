# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(mydynamiclib LANGUAGES C)

# generate a library from sources
add_library(mydynamiclib SHARED
    mydynamiclibexports.h
    first.c
    second.c
    third.c
    fourth.c
    )

# set library output path
set_target_properties(mydynamiclib
    PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/app"
    )
