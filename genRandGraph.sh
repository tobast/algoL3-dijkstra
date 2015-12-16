#!/bin/bash

noDot=0
if [ "$1" = "--no-dot" ] ; then
	noDot=1
	shift
fi

python3 ./genRandGraph.py > "$1.in" 2> "$1.dot"
if (($noDot == 0)); then
	dot -Tpng "$1.dot" > "$1.png"
fi
rm "$1.dot"
