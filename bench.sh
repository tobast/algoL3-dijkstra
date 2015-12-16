#!/bin/bash
# Generates naive, opti time curves for growing |V| values

mkdir -p "benchFiles/"
echo -e "nbVert\tnaive\topti"

for nbVert in `seq 10000 1000 100000`; do
	if [ ! -f "benchFiles/${nbVert}.in" ]; then
		python3 ./genRandGraph.py "$nbVert" 2>/dev/null > benchFiles/$nbVert.in
	fi
	/usr/bin/time -f "%e" ./dijkstra < benchs/$nbVert.in \
		> /dev/null 2>tests/cur.time
	tOpt=`cat tests/cur.time`
	/usr/bin/time -f "%e" ./dijkstra --naive < benchs/$nbVert.in \
		> /dev/null 2>tests/cur.time
	tNaive=`cat tests/cur.time`
	rm tests/cur*

	echo -e "$nbVert\t$tNaive\t$tOpt"
done


