
/******************************************************************************
 * Algorithmic project (l3) - Dijkstra algorithm using Fibonacci heap
 ******************************************************************************
 * Théophile Bastian <contact@tobast.fr>, Noémie Cartier
 ******************************************************************************
 * File: dijkstra.h
 * Implement Dijkstra algorithm with Fibonacci heaps
 *****************************************************************************/

#include "graph.h"
#include "fiboHeap.h"

void dijkstra(Graph* g, int s, int* res, int* ancestors);
int dijkstra_bound(Graph* g, int s, int* res, int* ancestors);
