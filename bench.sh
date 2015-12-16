#!/bin/bash
# Generates naive, opti time curves for growing |V| values

echo -e "nbVert\tnaive\topti"

for nbVert in `seq 10000 1000 100000`; do
	python3 ./genRandGraph.py "$nbVert" 2>/dev/null > tests/cur.in
	/usr/bin/time -f "%e" ./dijkstra < tests/cur.in > /dev/null 2>tests/cur.time
	tOpt=`cat tests/cur.time`
	/usr/bin/time -f "%e" ./dijkstra --naive < tests/cur.in > /dev/null \
		2>tests/cur.time
	tNaive=`cat tests/cur.time`
	rm tests/cur*

	echo -e "$nbVert\t$tNaive\t$tOpt"
done


