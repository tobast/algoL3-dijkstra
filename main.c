
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
#include "dijkstra.h"

Arguments args(int argc, char** argv) {
	Arguments out;
	out.useNaiveDijkstra = false;
	out.printDistsOnly = false;
	out.printTheoreticalBound = false;
	out.pathTo = -1;
	out.undirected = false;

	for(int par=1; par < argc; par++) {
		if(strcmp(argv[par], "--naive") == 0)
			out.useNaiveDijkstra = true;
		else if(strcmp(argv[par], "--dists-only") == 0)
			out.printDistsOnly = true;
		else if(strcmp(argv[par], "--path-to") == 0) {
			if(par == argc-1)
				continue;
			out.pathTo = atoi(argv[par+1]);
			par++;
		}
		else if(strcmp(argv[par], "--undirected") == 0)
			out.undirected = true;
		else if(strcmp(argv[par], "--print-bound") == 0)
			out.printTheoreticalBound = true;
	}
	return out;
}

void findPath(int pos, int* ancestors, ExtendList* outList) {
	el_push_back(outList, pos);
	if(pos != ancestors[pos])
		findPath(ancestors[pos], ancestors, outList);
}

void dispResult(int vert, int* distances, Arguments prgmArgs, int* ancestors)
{
	if(distances[vert] < 0)
		printf("%d: +∞\n", vert);
	else {
		if(prgmArgs.printDistsOnly)
			printf("%d: %d\n", vert, distances[vert]);
		else {
			printf("%d: %d, ", vert, distances[vert]);
			ExtendList path = el_create(1);
			findPath(vert, ancestors, &path);
			for(int pathPos=path.curLength-1; pathPos > 0; pathPos--)
				printf("%d -> ", path.list[pathPos]);
			printf("%d\n", vert);
			el_clean(&path);
		}
	}
}

int main(int argc, char** argv) {
	Arguments prgmArgs = args(argc, argv);

	// Input graph
	int nbVert, nbEdges;
	scanf("%d %d", &nbVert, &nbEdges);
	Graph graph = g_create(nbVert);
	for(int edge=0; edge < nbEdges; edge++) {
		int from,to,weight;
		scanf("%d %d %d", &from, &to, &weight);
		g_addEdge(&graph, from, to, weight);
		if(prgmArgs.undirected)
			g_addEdge(&graph, to, from, weight);
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
			if(prgmArgs.printTheoreticalBound) {
				printf("BOUND: %d\n", naiveDijkstra_bound(
					&graph, sourceVert, distances, ancestors));
			}
		}
		else { // Here comes the real stuff.
			dijkstra(&graph, sourceVert, distances, ancestors);
			if(prgmArgs.printTheoreticalBound) {
				printf("BOUND: %d\n",
					dijkstra_bound(&graph, sourceVert, distances, ancestors));
			}
		}

		// Output path
		if(prgmArgs.pathTo < 0) {
			for(int vert=0; vert < nbVert; vert++)
				dispResult(vert, distances, prgmArgs, ancestors);
		}
		else
			dispResult(prgmArgs.pathTo, distances, prgmArgs, ancestors);
	}

	g_clean(&graph);

	free(ancestors);
	free(distances);

	return 0;
}

