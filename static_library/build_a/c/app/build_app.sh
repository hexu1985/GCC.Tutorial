#!/usr/bin/env bash

set -x
gcc -Wall -I ../lib -c main.c
gcc main.o -L../lib -lmystaticlib -o app
