#!/bin/bash

set -e

mkdir xed-build && cd xed-build

git clone https://github.com/intelxed/xed.git xed
git clone https://github.com/intelxed/mbuild.git mbuild

mkdir build && cd build

../xed/mfile.py --no-encoder --cc=$(which emcc) install
