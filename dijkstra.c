
/******************************************************************************
 * Algorithmic project (l3) - Dijkstra algorithm using Fibonacci heap
 ******************************************************************************
 * Théophile Bastian <contact@tobast.fr>, Noémie Cartier
 ******************************************************************************
 * File: dijkstra.c
 * Implement Dijkstra algorithm with Fibonacci heaps
 *****************************************************************************/

#include "dijkstra.h"

void dijkstra(Graph* g, int s, int* res, int* ancestors){
	if (s >= g->nbVertices)
		assert("The source isn't in the graph." == 0);
	FiboHeap queue = fh_create();
	int* seen = (int*)malloc((g->nbVertices)*sizeof(int));
	for(int i = 0 ; i < g->nbVertices ; i++){
		res[i] = -1;
		ancestors[i] = -1;
	}
	res[s] = 0;
	ancestors [s] = 0;
	for(int i = 0 ; i < (g->adj[s]).curLength ; i++)
		fh_insert(&queue,
			makeTreeNode((g->weights[s]).list[i],(g->adj[s]).list[i],s));
	while(queue.trees != NULL){
		TreeNode n = fh_extractMin(&queue);
		if(seen[n.graphNode] == 0){
			res[n.graphNode] = n.weight;
			ancestors[n.graphNode] = n.ancestor;
			seen[n.graphNode] = 1;
			for(int i = 0 ; i < (g->adj[n.graphNode]).curLength ; i++){
				int dist = n.weight + (g->weights[n.graphNode]).list[i];
				fh_insert(&queue, makeTreeNode(dist, n.graphNode, n.ancestor));
			}
		}
	}
	free(seen);
}
