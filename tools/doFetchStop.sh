for file in lineEdges/* ; do
	endNode=`tail -n 1 "$file" | sed 's/^.* \(.*\) .*$/\1/g'`
	res=`bash ./doMerge.sh $file idf.graph | ./dijkstra --undirected --path-to $endNode`
	dist=`echo $res | sed 's/^.*: \(.*\),.*$/\1/g'`
	stopid=`echo $res | sed 's/^.*-> \(.*\) -> [^>]*$/\1/g'`

	bn=`basename $file`
	stopname=`grep "$stopid" "corres/$bn" | sed 's/^[0-9]* //g'`
	echo `basename $bn .txt` $dist $stopname
#done
