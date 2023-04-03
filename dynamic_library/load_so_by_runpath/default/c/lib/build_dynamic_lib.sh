#!/usr/bin/env bash

set -x
gcc -fPIC -c first.c fourth.c second.c third.c
gcc -shared first.o fourth.o second.o third.o -o libmydynamiclib.so

