
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
int tripleCreate_bound(int UNUSED(a), int UNUSED(b), int UNUSED(c)){
	return 3;
}

Triple naiveMin(ExtendList* origin, ExtendList* end, ExtendList* dist){
	int indMin = 0;
	for(int i = 1 ; i < end->curLength ; i++)
		if((0 <= (dist->list)[i]) && (dist->list)[i] < (dist->list)[indMin])
			indMin = i;
	Triple t = tripleCreate((origin->list)[indMin],(end->list)[indMin],
		(dist->list)[indMin]);
	for(int i = indMin + 1 ; i < end->curLength ; i++){
		(dist->list)[i-1] = (dist->list)[i];
		(origin->list)[i-1] = (origin->list)[i];
		(end->list)[i-1] = (end->list)[i];
	}
	el_pop_back(dist);
	el_pop_back(origin);
	el_pop_back(end);
	return t ;
}
int naiveMin_bound(ExtendList* UNUSED(o), ExtendList* e, ExtendList* UNUSED(d)){
	return 1 + (e->curLength)*10 + tripleCreate_bound(0, 0, 0);
}

void naiveDijkstra(Graph* g, int s, int* res, int* ancestors){
	if(s >= g->nbVertices)
		assert("The source isn't in the graph." == 0);
	ExtendList origin = el_create(0);
	ExtendList end = el_create(0);
	ExtendList weights = el_create(0);
	int* seen = (int*)calloc((g->nbVertices),sizeof(int));
	for(int i = 0 ; i < g->nbVertices ; i++){
		res[i] = (-1);
		ancestors[i] = (-1);
	}
	el_push_back(&origin,s);
	el_push_back(&end, s);
	el_push_back(&weights, 0);
	while(end.curLength != 0){
		Triple t = naiveMin(&origin, &end, &weights);
		if(seen[t.b] == 0){
			res[t.b] = t.w;
			ancestors[t.b] = t.a;
			seen[t.b] = 1;
			for(int i = 0 ; i < (g->adj[t.b]).curLength ; i++) {
				int dist = t.w + (g->weights[t.b]).list[i];
				el_push_back(&origin, t.b);
				el_push_back(&end, (g->adj[t.b].list[i]));
				el_push_back(&weights, dist);
			}
		}
	}

	el_clean(&origin);
	el_clean(&end);
	el_clean(&weights);

	free(seen);
}
int naiveDijkstra_bound(Graph* g, int s, int* UNUSED(res), int* UNUSED(a)){
	return 5 + 3*el_create_bound(0) + (g->nbVertices)*4 
		+ ((g->adj[s]).curLength)*(2+3*el_push_back_bound_amz(NULL, 0))
		+ (g->nbEdges)*(1 + (g->nbEdges)*10 + tripleCreate_bound(0,0,0))
		+ (g->nbEdges)*(2 + 3*el_push_back_bound_amz(NULL,0));
}

