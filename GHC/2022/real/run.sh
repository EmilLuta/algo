#!/bin/zsh
c go.cpp
for x in a b c d e f; do
    ./go.bin $x.txt
done
