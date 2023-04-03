# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(topproj LANGUAGES C)

add_subdirectory(lib)
add_subdirectory(app)

