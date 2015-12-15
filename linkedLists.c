
/******************************************************************************
 * Algorithmic project (l3) - Dijkstra algorithm using Fibonacci heap
 ******************************************************************************
 * Théophile Bastian <contact@tobast.fr>, Noémie Cartier
 ******************************************************************************
 * File: linkedLists.c
 * implement linked lists
 *****************************************************************************/

#include "linkedLists.h"


LinkedList* ll_create(LinkedListVal val){
	LinkedList* lst = (LinkedList*)malloc(sizeof(LinkedList));
	lst->next = lst;
	lst->prev = lst;
	lst->val = val;
	return lst;
}

void ll_clean(LinkedList* lst){
	if(lst == NULL)
		return;
	while (lst->next != lst) {
		tr_clean(lst->next->val->child);
		tr_clean(lst->next->val->sibling); // supposed to be NULL
		ll_delete_next(lst);
	}
	free(lst);
}

LinkedList* ll_insert_next(LinkedList* lst, LinkedListVal val){
	if(lst == NULL)
		return ll_create(val);

	LinkedList* newlst = (LinkedList*)malloc(sizeof(LinkedList));

	newlst->next = lst->next;
	newlst->prev = lst;
	newlst->val = val;
	lst->next->prev = newlst;
	lst->next = newlst;
	return lst;
}

//WARNING! Doesn't free() the tree anymore
LinkedList* ll_delete_next(LinkedList* lst){
	if(lst == NULL)
		assert(0); // The user deleted a non-existing element.
	else if(lst->next == lst) { // The list contains a single element
		free(lst);
		return NULL;
	}

	LinkedList* delLst = lst->next;
	lst->next = delLst->next;
	delLst->next->prev = lst;
	
//	tr_cleanSingle(delLst->val); // Necessary for fiboHeap to work
	free(delLst);
	return lst;
}

