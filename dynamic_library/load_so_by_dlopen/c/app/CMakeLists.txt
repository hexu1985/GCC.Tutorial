# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(app LANGUAGES C)

add_executable(app main.c)

target_link_libraries(app dl)

