
/******************************************************************************
 * Algorithmic project (l3) - Dijkstra algorithm using Fibonacci heap
 ******************************************************************************
 * Théophile Bastian <contact@tobast.fr>, Noémie Cartier
 ******************************************************************************
 * File: extendList.h
 * implement extendable lists
 *****************************************************************************/

#ifndef DEF_EXTENDLIST
#define DEF_EXTENDLIST

#include <stdlib.h>
#include <assert.h>

typedef struct ExtendList {
	int availLength;
	int curLength;
	int* list;
} ExtendList;

ExtendList el_create(int len);

void el_clean(ExtendList* lst);

void el_push_back(ExtendList* lst, int val);

void el_pop_back(ExtendList* lst);

int el_get(ExtendList* lst, int rank);

int el_size(ExtendList* lst);

#endif//DEF_EXTENDLIST
