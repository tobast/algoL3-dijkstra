
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
#include "tree.h"

typedef Tree LinkedListVal; // Alias to allow easy modification

typedef struct LinkedList {
	LinkedListVal val;
	struct LinkedList* next;
	struct LinkedList* prev;
} LinkedList;

LinkedList* ll_create(LinkedListVal val);

void ll_clean(LinkedList* lst);

void ll_insert_next(LinkedList* lst, LinkedListVal val);

void ll_delete_next(LinkedList* lst);

#endif//DEF_LINKEDLISTS
