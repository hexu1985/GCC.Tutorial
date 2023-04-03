#!/usr/bin/env bash

set -x
g++ -fPIC -c first.cpp fourth.cpp second.cpp third.cpp
g++ -shared first.o fourth.o second.o third.o -o libmydynamiclib.so

