#!/usr/bin/env bash

set -x
gcc -Wall -I ../lib -c main.c
#gcc main.o -Wl,-R../lib -L../lib -lmydynamiclib -o app
gcc main.o -Wl,-rpath,../lib -L../lib -lmydynamiclib -o app
