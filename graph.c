
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
int g_create_bound(int size) {
	return size * sizeof(ExtendList);
}

void g_addEdge(Graph* g, int a, int b, int w){
	(g->nbVertices)++;
	el_push_back(&(g->adj[a]), b);
	el_push_back(&(g->weights[a]), w);
	el_push_back(&(g->indAdj[a]),b);
	el_push_back(&(g->indAdj[b]),a);
}
int g_addEdge_bound(Graph* UNUSED(g), int UNUSED(a), int UNUSED(b),
	int UNUSED(w))
{
	return 4*el_push_back_bound_amz(NULL,0);
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
int g_clean_bound(Graph* g) {
	int out=0;
	for(int vert=0; vert < g->nbVertices; vert++) {
		out += el_clean_bound(&(g->adj[vert]));
		out += el_clean_bound(&(g->weights[vert]));
		out += el_clean_bound(&(g->indAdj[vert]));
	}
	return 3+out;
}

int g_size(Graph* g){
	return g->nbVertices;
}
int g_size_bound(Graph* UNUSED(g)) {
	return 1;
}

void dfs(Graph* g, int s, int* test, int* seen){
	seen[s] = 1;
	for(int i = 0 ; i < g->indAdj[s].curLength ; i++)
		if(seen[(g->indAdj[s]).list[i]] == 0)
			dfs(g, (g->indAdj[s]).list[i], test, seen);
	(*test)++;
}
int dfs_bound(Graph* g, int UNUSED(s), int* UNUSED(test), int* UNUSED(seen)) {
	return g->nbEdges + g->nbVertices;
}

int g_testConnexity(Graph* g){
	int* test = NULL;
	int* seen = (int*)calloc(g->nbVertices, sizeof(int));
	dfs(g, 0, test, seen);
	return (*test == g->nbVertices);
}
int g_testConnexity_bound(Graph* g) {
	return (sizeof(int)*(g->nbVertices)) + dfs_bound(g, 0, NULL, NULL) + 1;
}

Triple tripleCreate(int a, int b, int w){
	Triple t;
	t.a = a;
	t.b = b;
	t.w = w;
	return t;
}

Triple naiveMin(ExtendList* origin, ExtendList* end, ExtendList* dist){
	int indMin = 0;
	for(int i = 1 ; i < end->curLength ; i++)
		if((0 < (dist->list)[i]) && (dist->list)[i] < (dist->list)[indMin])
			indMin = i;
	Triple t = tripleCreate((origin->list)[indMin],(end->list)[indMin],
		(dist->list)[indMin]);
	for(int i = indMin + 1 ; i < end->curLength ; i++){
		(dist->list)[i-1] = (dist->list)[i];
		(origin->list)[i-1] = (origin->list)[i];
		(end->list)[i-1] = (end->list)[i];
	}
	return t ;
}

int* naiveDijkstra(Graph* g, int s){
	if(s >= g->nbVertices)
		assert("The source isn't in the graph." == 0);
	int* nbSeen = (int*)malloc(g->nbVertices*sizeof(int));;
	nbSeen[0] = 1;
	ExtendList origin = el_create(0);
	ExtendList end = el_create(0);
	ExtendList weights = el_create(0);
	int* res = (int*)malloc((g->nbVertices)*sizeof(int));
	int* seen = (int*)malloc((g->nbVertices)*sizeof(int));
	for(int i = 0 ; i < g->nbVertices ; i++)
		res[i] = (-1);
	seen[s] = 1;
	for(int i = 0 ; i < (g->adj[s]).curLength ; i++){
		el_push_back(&origin,s);
		el_push_back(&end, (g->adj[s]).list[i]);
		el_push_back(&weights, (g->weights[s]).list[i]);
	}
	while(*nbSeen < g->nbVertices){
		Triple t = naiveMin(&origin, &end, &weights);
		if(seen[t.b] == 0){
			res[t.b] = t.w;
			seen[t.b] = 1;
			for(int i = 0 ; i < (g->adj[t.b]).curLength ; i++) {
				int dist = t.w + (g->weights[t.b]).list[i];
				el_push_back(&origin, t.b);
				el_push_back(&end, (g->adj[t.b].list[i]));
				el_push_back(&weights, dist);
			}
		}
	}
	return res;
}
	
