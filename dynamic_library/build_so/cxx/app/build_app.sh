#!/usr/bin/env bash

set -x
g++ -Wall -I ../lib -c main.cpp
g++ main.o -L../lib -lmydynamiclib -o app
