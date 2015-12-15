#!/bin/bash

python ./genRandGraph.py > "$1.in" 2> "$1.dot"
dot -Tpng "$1.dot" > "$1.png"
rm "$1.dot"
