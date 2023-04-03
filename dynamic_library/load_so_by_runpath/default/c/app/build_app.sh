#!/usr/bin/env bash

set -x
gcc -Wall -I ../lib -c main.c
#gcc main.o -Wl,-R../lib -Wl,--enable-new-dtags -L../lib -lmydynamiclib -o app
gcc main.o -Wl,-rpath,../lib -Wl,--enable-new-dtags -L../lib -lmydynamiclib -o app
