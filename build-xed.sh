#!/bin/bash

set -e

mkdir xed-build && cd xed-build

git clone https://github.com/intelxed/xed.git xed
git clone https://github.com/intelxed/mbuild.git mbuild

mkdir build && cd build

../xed/mfile.py --no-encoder --no-werror --cc=$(which emcc) --jobs=$(nproc) --extra-flags="-sEXPORT_ALL=1" --static install

cd kits && mv */ xed && cp -r * ../../../

cd ../../../

rm -rf xed-build
