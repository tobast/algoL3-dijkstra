
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
#include "genericStruct.h"

typedef struct ExtendList {
	int availLength;
	int curLength;
	int* list;
} ExtendList;

ExtendList el_create(int len);
int el_create_bound(int len);

void el_clean(ExtendList* lst);
int el_clean_bound(ExtendList* lst);

void el_push_back(ExtendList* lst, int val);
int el_push_back_bound(ExtendList* lst, int val);
int el_push_back_bound_amz(ExtendList* lst, int val);

void el_pop_back(ExtendList* lst);
int el_pop_back_bound(ExtendList* lst);

int el_get(ExtendList* lst, int rank);
int el_get_bound(ExtendList* lst, int rank);

int el_size(ExtendList* lst);
int el_size_bound(ExtendList* lst);

#endif//DEF_EXTENDLIST
