#!/usr/bin/env bash

set -x
cmake -H. -Bbuild
cmake --build build -- VERBOSE=1

