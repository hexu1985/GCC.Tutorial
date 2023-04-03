# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(mystaticlib LANGUAGES C)

# generate a library from sources
add_library(mystaticlib STATIC
    mystaticlibexports.h
    first.c
    second.c
    third.c
    fourth.c
    )

