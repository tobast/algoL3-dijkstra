
/******************************************************************************
 * Algorithmic project (l3) - Dijkstra algorithm using Fibonacci heap
 ******************************************************************************
 * Théophile Bastian <contact@tobast.fr>, Noémie Cartier
 ******************************************************************************
 * File: naiveDijkstra.h
 * Implement naive Dijkstra
 *****************************************************************************/

#include "graph.h"


typedef struct Triple {
	int a;
	int b;
	int w;
} Triple;

void naiveDijkstra(Graph* g, int s, int* res);
