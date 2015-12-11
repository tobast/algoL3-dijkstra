
/******************************************************************************
 * Algorithmic project (l3) - Dijkstra algorithm using Fibonacci heap
 ******************************************************************************
 * Théophile Bastian <contact@tobast.fr>, Noémie Cartier
 ******************************************************************************
 * File: extendList.c
 * implement extendable lists
 *****************************************************************************/

#include "extendLists.h"

ExtendList el_create(int len){
	ExtendList lst ;
	lst.availLength = (len > 1) ? len : 1;
	lst.curLength = 0 ; 
	lst.list = (int*)malloc(len*(sizeof(int)));
	return lst;
}

void el_clean(ExtendList* lst){
	free(lst->list);
}

void el_push_back(ExtendList* lst, int val){
	if (lst->curLength == lst->availLength){ 
		int* lstAux = lst->list;
		lst->list = (int*)malloc(sizeof(int)*(lst->curLength)*2);
		for(int i = 0 ; i < (lst->curLength) ; i++)
			(lst->list)[i] = (lstAux)[i];
		free(lstAux);
		lst->availLength *= 2;
	}
	(lst->list)[lst->curLength] = val;
	lst->curLength++;
}

void el_pop_back(ExtendList* lst){
	if(lst->curLength == 0) // trying to pop from an empty list
		assert(0);
	if ((lst->curLength) < (lst->availLength)/4){
		int* lstAux = lst->list;
		lst->list = (int*)malloc(sizeof(int)*((lst->availLength)/2));
		for(int i = 0 ; i < (lst->curLength) - 1 ; i++)
			(lst->list)[i] = (lstAux)[i];
		free(lstAux);
		lst->availLength /= 2;
	}
	lst->curLength--;
}

int el_get(ExtendList* lst, int rank){
	return (lst->list)[rank];
}

int el_size(ExtendList* lst){
	return lst->curLength;
}


