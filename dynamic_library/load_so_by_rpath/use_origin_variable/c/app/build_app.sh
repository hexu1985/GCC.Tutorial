#!/usr/bin/env bash

set -x
gcc -Wall -I ../lib -c main.c
gcc main.o -Wl,-rpath,'$ORIGIN/../lib' -L../lib -lmydynamiclib -o app
