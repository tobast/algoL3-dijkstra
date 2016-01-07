endNode=`tail -n 1 "$1" | sed 's/^.* \(.*\) .*$/\1/g'`
bash doMerge.sh $1 | ../dijkstra --undirected --path-to $endNode
