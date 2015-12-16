#!/usr/bin/python

############################# CONSTANTS #######################################
NB_VERT = 5 
DEGREE_RANGE = (1,3)
WEIGHT_RANGE = (0,5)
###############################################################################

from random import randint
import sys

def randInRange(x):
	return randint(x[0],x[1])

edges = []
for vert in range(NB_VERT):
	for edge in range(randInRange(DEGREE_RANGE)):
		oth = vert
		while(oth == vert):
			oth = randint(0, NB_VERT-1)
		edges.append( (vert, oth, randInRange(WEIGHT_RANGE)) )

print("digraph blah {", file=sys.stderr)
print(NB_VERT, end=" ")
print(len(edges))
for edge in edges:
	fr,to,weight = edge
	print("{} {} {}".format(fr,to,weight))
	print("\t{} -> {} [label={}]".format(fr,to,weight), file=sys.stderr)

print("}", file=sys.stderr)

print("1 0")

