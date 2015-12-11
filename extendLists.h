
/******************************************************************************
 * Algorithmic project (l3) - Dijkstra algorithm using Fibonacci heap
 ******************************************************************************
 * Théophile Bastian <contact@tobast.fr>, Noémie Cartier
 ******************************************************************************
 * File: extendList.h
 * implement extendable lists
 *****************************************************************************/

#include <stdlib.h>

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


