#!/usr/bin/env bash

set -x
$(cd lib && ./build_static_lib.sh)
$(cd app && ./build_app.sh)
