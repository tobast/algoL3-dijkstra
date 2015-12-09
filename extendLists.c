
/******************************************************************************
 * Algorithmic project (l3) - Dijkstra algorithm using Fibonacci heap
 ******************************************************************************
 * Théophile Bastian <contact@tobast.fr>, Noémie Cartier
 ******************************************************************************
 * File: extendList.c
 * implement extendable lists
 *****************************************************************************/

#include "extendLists.h"

ExtendList* el_create(int val){
	ExtendList* lst = (ExtendList*)malloc(sizeof(ExtendList));
	lst->dispLength = 1;
	lst->curLength = 1;
	lst->list = (int*)malloc(sizeof(int));
	*(lst->list) = val;
	return lst;
}

void el_clean(ExtendList* lst){
	free(lst->list);
	free(lst);
}

void el_push_back(ExtendList* lst, int val){
	if (lst->curLength = lst->dispLength){
		int* lstAux = lst->list;
		lst->list = (int*)malloc(sizeof(int)*(lst->curLength)*2);
		int i;
		for(i = 0 ; i < (lst->curLength) ; i++)
			(lst->list)[i] = (lstAux)[i];
		free(lstAux);
		lst->dispLength *= 2;
	}
	(lst->list)[lst->curLength] = val;
	lst->curLength++;
}

void el_pop_back(ExtendList* lst){
	if ((lst->curLength) - 1 < (lst->dispLength)/4){
		int* lstAux = lst->list;
		lst->list = (int*)malloc(sizeof(int)*(lst->dispLength)/2);
		int i;
		for(i = 0 ; i < (lst->curLength) - 1 ; i++)
			(lst->list)[i] = (lstAux)[i];
		free(lstAux);
		lst->dispLength /= 2;
	}
	lst->curLength--;
}

int el_get(ExtendList* lst, int rank){
	int res = (lst->list)[rank];
	return res;
}

int el_size(ExtendList* lst){
	int res = lst->curLength;
	return res;
}


