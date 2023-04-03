#!/usr/bin/env bash

set -x
gcc -fPIC -c first.c fourth.c second.c third.c
ar rcs libmystaticlib.a first.o fourth.o second.o third.o 

gcc -fPIC -c mydynamiclibshell.c
gcc -shared mydynamiclibshell.o -o libmydynamiclib.so -Wl,--whole-archive libmystaticlib.a -Wl,-no-whole-archive

