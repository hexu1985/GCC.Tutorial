#!/usr/bin/env bash

set -x
ar -x libmystaticlib.a
gcc -shared first.o fourth.o second.o third.o -o libmydynamiclib.so
rm *.o
