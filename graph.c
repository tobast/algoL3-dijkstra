
/******************************************************************************
 * Algorithmic project (l3) - Dijkstra algorithm using Fibonacci heap
 ******************************************************************************
 * Théophile Bastian <contact@tobast.fr>, Noémie Cartier
 ******************************************************************************
 * File: graph.c
 * Implement graph structure
 *****************************************************************************/

#include "graph.h"

Graph g_create(int size){
	Graph g;
	g.nbEdges = 0;
	g.nbVertices = size;
	g.adj = (ExtendList*)malloc(size*(sizeof(ExtendList)));
	g.weights = (ExtendList*)malloc(size*(sizeof(ExtendList)));
	for(int i = 0 ; i < size ; i++){
		g.adj[i] = el_create(0);
		g.weights[i] = el_create(0);
	}
	return g;
}

void g_addEdge(Graph* g, int a, int b, int w){
	(g->nbVertices)++;
	el_push_back(&(g->adj[a]), b);
	el_push_back(&(g->weights[a]), w);
	el_push_back(&(g->indAdj[a]),b);
	el_push_back(&(g->indAdj[b]),a);
}

void g_clean(Graph* g){
	for(int i = 0 ; i < g->nbVertices ; i++){
		el_clean(&(g->adj[i]));
		el_clean(&(g->weights[i]));
		el_clean(&(g->indAdj[i]));
	}
	free(g->adj);
	free(g->weights);
	free(g->indAdj);
}

int g_size(Graph* g){
	return g->nbVertices;
}

void dfs(Graph* g, int s, int* test, int* seen){
	seen[s] = 1;
	for(int i = 0 ; i < g->indAdj[s].curLength ; i++)
		if(seen[(g->indAdj[s]).list[i]] == 0)
			dfs(g, (g->indAdj[s]).list[i], test, seen);
	(*test)++;
}

int g_testConnexity(Graph* g){
	int* test = NULL;
	int* seen = (int*)calloc(g->nbVertices, sizeof(int));
	dfs(g, 0, test, seen);
	return (*test == g->nbVertices);
}

int naiveMin(int* tab, int len){
	int min = *tab;
	for(int i = 1 ; i < len ; i++)
		if(tab[i] < min)
			min = tab[i];
	return min;

int* naiveDijkstra(Graph* g, int s){
	if(s >= g->nbVertices)
		assert("The source isn't in the graph." == 0);
	if(g_testConnexity(g) == 0)
		assert("The graph isn't connex.");
	
	
