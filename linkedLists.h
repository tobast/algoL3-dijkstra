
/******************************************************************************
 * Algorithmic project (l3) - Dijkstra algorithm using Fibonacci heap
 ******************************************************************************
 * Théophile Bastian <contact@tobast.fr>, Noémie Cartier
 ******************************************************************************
 * File: linkedLists.h
 * implement linked lists
 *****************************************************************************/

#include <stdlib.h>

typedef struct LinkedList{
	int val;
	LinkedList* next;
	LinkedList* prev;
} LinkedList;

LinkedList* ll_create(int val);

void ll_clean(LinkedList* lst);

void ll_insert_next(LinkedList* lst, int val);

void ll_delete_next(LinkedList* lst);
