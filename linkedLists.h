
/******************************************************************************
 * Algorithmic project (l3) - Dijkstra algorithm using Fibonacci heap
 ******************************************************************************
 * Théophile Bastian <contact@tobast.fr>, Noémie Cartier
 ******************************************************************************
 * File: linkedLists.h
 * implement linked lists
 *****************************************************************************/

#ifndef DEF_LINKEDLISTS
#define DEF_LINKEDLISTS

#include <stdlib.h>
#include <assert.h>
#include "genericStruct.h"
#include "tree.h"

typedef Tree* LinkedListVal; // Alias to allow easy modification

typedef struct LinkedList {
	LinkedListVal val;
	struct LinkedList* next;
	struct LinkedList* prev;
} LinkedList;

LinkedList* ll_create(LinkedListVal val);
int ll_create_bound(LinkedListVal val);

void ll_clean(LinkedList* lst);
int ll_clean_bound(LinkedList* lst);

LinkedList* ll_insert_next(LinkedList* lst, LinkedListVal val);
int ll_insert_next_bound(LinkedList* lst, LinkedListVal val);

LinkedList* ll_delete_next(LinkedList* lst);
int ll_delete_next_bound(LinkedList* lst);

#endif//DEF_LINKEDLISTS
