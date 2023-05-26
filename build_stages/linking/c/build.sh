#!/bin/bash

gcc -c function.c main.c
gcc function.o main.o -o demoApp
