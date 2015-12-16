#!/bin/bash
# Does random checks.

failcount=0

mkdir -p tests
for i in `seq 1 $1`; do
	echo "$i..."
	./genRandGraph.sh tests/cur
	./dijkstra --dists-only --naive < tests/cur.in > tests/curNaive.out
	./dijkstra --dists-only < tests/cur.in > tests/cur.out
	checker/checker < tests/cur.in > tests/curCheck.out

	fail=0
	diff tests/curNaive.out tests/cur.out > /dev/null
	if (( $? != 0 )); then
		>&2 echo "ERROR: mismatching naive/opti"
		fail=1
	fi
	diff tests/curNaive.out tests/curCheck.out > /dev/null
	if (( $? != 0 )); then
		>&2 echo "ERROR: mismatching naive/check"
		fail=1
	fi
	diff tests/cur.out tests/curCheck.out > /dev/null
	if (( $? != 0 )); then
		>&2 echo "ERROR: mismatching opti/check"
		fail=1
	fi

	if (( $fail != 0)) ; then
		>&2 echo "FAILED TEST saved as tests/${failcount}.in,png"
		cp tests/cur.in tests/${failcount}.in
#		cp tests/cur.png tests/${failcount}.png
		let "failcount = failcount + 1"
	fi
	rm tests/cur*
done
