#!/usr/bin/env bash

echo "start complie project"

./bash/build_macOS_x86.sh*

echo "end complie"

echo "start excute examples"

cd build_macOS_x86/macOS-release/test_demo

./reverse_w

echo "CNN Inference"

./conv

echo "Done!"
