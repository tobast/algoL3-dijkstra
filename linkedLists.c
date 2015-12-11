
/******************************************************************************
 * Algorithmic project (l3) - Dijkstra algorithm using Fibonacci heap
 ******************************************************************************
 * Théophile Bastian <contact@tobast.fr>, Noémie Cartier
 ******************************************************************************
 * File: linkedLists.c
 * implement linked lists
 *****************************************************************************/

#include "linkedLists.h"


LinkedList* ll_create(int val){
	LinkedList* lst = (LinkedList*)malloc(sizeof(LinkedList));
	lst->next = lst;
	lst->prev = lst;
	lst->val = val;
	return lst;
}

void ll_clean(LinkedList* lst){
	while (lst->next != lst)
		ll_delete_next(lst);
	free(lst);
}

void ll_insert_next(LinkedList* lst, int val){
	LinkedList* newlst = (LinkedList*)malloc(sizeof(LinkedList));
	newlst->next = lst->next;
	newlst->prev = lst;
	lst->next->prev = newlst;
	lst->next = newlst;
}

void ll_delete_next(LinkedList* lst){
	if(lst->next == lst) // The list contains a single element
		assert(0);
	LinkedList* delLst = lst->next;
	lst->next = delLst->next;
	delLst->next->prev = lst;
	free(delLst);
}

