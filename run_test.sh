#!/usr/bin/env bash


cd build_macOS_x86/macOS-release/test_demo

./reverse_w


echo "CNN Inference"

./conv

echo "Done!"
