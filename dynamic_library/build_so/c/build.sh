#!/usr/bin/env bash

set -x
$(cd lib && ./build_dynamic_lib.sh)
$(cd app && ./build_app.sh)
