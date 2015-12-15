
/******************************************************************************
 * Algorithmic project (l3) - Dijkstra algorithm using Fibonacci heap
 ******************************************************************************
 * Théophile Bastian <contact@tobast.fr>, Noémie Cartier
 ******************************************************************************
 * File: main.c
 * Main file.
 *****************************************************************************/

#include <stdio.h>
#include <string.h>

#include "extendLists.h"
#include "graph.h"
#include "genericStruct.h"
#include "naiveDijkstra.h"
//#include "dijkstra.h" //TODO

Arguments args(int argc, char** argv) {
	Arguments out;
	out.useNaiveDijkstra = false;

	for(int par=1; par < argc; par++) {
		if(strcmp(argv[par], "--naive"))
			out.useNaiveDijkstra = true;
	}
	return out;
}

void findPath(int pos, int* ancestors, ExtendList* outList) {
	el_push_back(outList, pos);
	if(pos != ancestors[pos])
		findPath(ancestors[pos], ancestors, outList);
}

int main(int argc, char** argv) {
	Arguments prgmArgs = args(argc, argv);

	// Input graph
	int nbVert, nbEdges;
	scanf("%d %d", &nbVert, &nbEdges);
	Graph graph = g_create(nbVert);
	graph.nbEdges = nbEdges;
	for(int edge=0; edge < graph.nbEdges; edge++) {
		int from,to,weight;
		scanf("%d %d %d", &from, &to, &weight);
		g_addEdge(&graph, from, to, weight);
	}


	int nbSources;
	scanf("%d", &nbSources);

	int* distances = (int*) malloc(sizeof(int)*nbVert);
	int* ancestors = (int*) malloc(sizeof(int)*nbVert);
	for(int sourceId=0; sourceId < nbSources; sourceId++) {
		int sourceVert;
		scanf("%d", &sourceVert);

		// BEHOLD, as Dijkstra itself is executed.
		if(prgmArgs.useNaiveDijkstra) { // Use the naive array-based version
			naiveDijkstra(&graph, sourceVert, distances, ancestors);
		}
		else { // Here comes the real stuff.
			//TODO
			assert(false);
		}

		// Output path
		for(int vert=0; vert < nbVert; vert++) {
			if(distances[vert] < 0)
				printf("%d: +∞\n", vert);
			else {
				printf("%d: %d, ", vert, distances[vert]);
				ExtendList path = el_create(1);
				findPath(vert, ancestors, &path);
				for(int pathPos=path.curLength-1; pathPos > 0; pathPos--)
					printf("%d -> ", path.list[pathPos]);
				printf("%d\n", vert);
			}
		}
	}

	free(ancestors);
	free(distances);

	return 0;
}

