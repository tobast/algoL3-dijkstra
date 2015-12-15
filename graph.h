
/******************************************************************************
 * Algorithmic project (l3) - Dijkstra algorithm using Fibonacci heap
 ******************************************************************************
 * Théophile Bastian <contact@tobast.fr>, Noémie Cartier
 ******************************************************************************
 * File: graph.h
 * Implement graph structure.
 *****************************************************************************/

#ifndef DEF_GRAPH
#define DEF_GRAPH

#include <stdlib.h>
#include "extendLists.h"
#include "genericStruct.h"

typedef struct Graph {
	int nbEdges;
	int nbVertices;
	ExtendList* adj; //array of size nbVertices
	ExtendList* weights;
	ExtendList* indAdj;
} Graph;

Graph g_create(int size);
int g_create_bound(int size);

void g_addEdge(Graph* g, int a, int b, int w);
int g_addEdge_bound(Graph* g, int a, int b, int w);

void g_clean(Graph* g);
int g_clean_bound(Graph* g);

int g_size(Graph* g);
int g_size_bound(Graph* g);

int g_testConnexity(Graph* g);
int g_testConnexity_bound(Graph* g);



#endif//DEF_GRAPH

