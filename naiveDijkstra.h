
/******************************************************************************
 * Algorithmic project (l3) - Dijkstra algorithm using Fibonacci heap
 ******************************************************************************
 * Théophile Bastian <contact@tobast.fr>, Noémie Cartier
 ******************************************************************************
 * File: naiveDijkstra.h
 * Implement naive Dijkstra
 *****************************************************************************/

#include "graph.h"
#include <stdio.h>

typedef struct Triple {
	int a;
	int b;
	int w;
} Triple;

/**
 * Computes naively the distances from s to every vertice in g, and stores
 * it in res, while storing each node's ancestor in the path in ancestors.
 * @param res: array of size at least g->nbVertices. Needn't be initialized.
 * @param ancestors: same.
 **/
void naiveDijkstra(Graph* g, int s, int* res, int* ancestors);
