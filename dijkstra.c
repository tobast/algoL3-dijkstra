
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
	int* seen = (int*)calloc((g->nbVertices),sizeof(int));
	int* minWeight = (int*)malloc((g->nbVertices)*sizeof(int));
	for(int i = 0 ; i < g->nbVertices ; i++){
		res[i] = -1;
		ancestors[i] = -1;
		minWeight[i] = -1;
	}
	fh_insert(&queue, makeTreeNode(0, s, s));
	while(queue.trees != NULL){
		TreeNode n = fh_extractMin(&queue);
		if(seen[n.graphNode] == 0){
			res[n.graphNode] = n.weight;
			ancestors[n.graphNode] = n.ancestor;
			seen[n.graphNode] = 1;
			for(int i = 0 ; i < (g->adj[n.graphNode]).curLength ; i++){
				if(seen[g->adj[n.graphNode].list[i]] > 0)
					continue;
				int dist = n.weight + (g->weights[n.graphNode]).list[i];
				if (dist < minWeight[(g->adj[n.graphNode]).list[i]] 
						|| minWeight[(g->weights[n.graphNode]).list[i]] < 0)
					fh_insert(&queue, makeTreeNode(dist, 
						(g->adj[n.graphNode]).list[i], n.graphNode));
			}
		}
	}
	fh_clean(&queue);
	free(seen);
	free(minWeight);
}

int dijkstra_bound(Graph* g, int s, int* UNUSED(res), int* UNUSED(ancestors)){
	return 1 + fh_create_bound() + (g->nbVertices)*5 
		+ fh_insert_bound(NULL, makeTreeNode(0,s,s)) 
		+ makeTreeNode_bound(0,s,s)
		+ (g->nbVertices)*(6 + fh_insert_bound(NULL, makeTreeNode(0, 0, 0)));
}
