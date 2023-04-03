# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(app LANGUAGES CXX)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../lib)

add_executable(app main.cpp)

target_link_libraries(app mydynamiclib)
