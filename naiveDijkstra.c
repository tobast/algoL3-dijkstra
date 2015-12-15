
/******************************************************************************
 * Algorithmic project (l3) - Dijkstra algorithm using Fibonacci heap
 ******************************************************************************
 * Théophile Bastian <contact@tobast.fr>, Noémie Cartier
 ******************************************************************************
 * File: naiveDijkstra.c
 * Implement naive Dijkstra
 *****************************************************************************/

#include "naiveDijkstra.h"

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

void naiveDijkstra(Graph* g, int s, int* res){
	if(s >= g->nbVertices)
		assert("The source isn't in the graph." == 0);
	int nbSeen;
	nbSeen = 1;
	ExtendList origin = el_create(0);
	ExtendList end = el_create(0);
	ExtendList weights = el_create(0);
	int* seen = (int*)malloc((g->nbVertices)*sizeof(int));
	for(int i = 0 ; i < g->nbVertices ; i++)
		res[i] = (-1);
	seen[s] = 1;
	for(int i = 0 ; i < (g->adj[s]).curLength ; i++){
		el_push_back(&origin,s);
		el_push_back(&end, (g->adj[s]).list[i]);
		el_push_back(&weights, (g->weights[s]).list[i]);
	}
	while(nbSeen < g->nbVertices){
		Triple t = naiveMin(&origin, &end, &weights);
		if(seen[t.b] == 0){
			res[t.b] = t.w;
			seen[t.b] = 1;
			nbSeen++;
			for(int i = 0 ; i < (g->adj[t.b]).curLength ; i++) {
				int dist = t.w + (g->weights[t.b]).list[i];
				el_push_back(&origin, t.b);
				el_push_back(&end, (g->adj[t.b].list[i]));
				el_push_back(&weights, dist);
			}
		}
	}
	free(seen);
}
	
