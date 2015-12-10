
/******************************************************************************
 * Algorithmic project (l3) - Dijkstra algorithm using Fibonacci heap
 ******************************************************************************
 * Théophile Bastian <contact@tobast.fr>, Noémie Cartier
 ******************************************************************************
 * File: extendList.c
 * implement extendable lists
 *****************************************************************************/

#include "extendLists.h"

//FIXME don't force the user to add the first elem
//FIXME instead, why not let him select the initial size?
ExtendList* el_create(int val){
	ExtendList* lst = (ExtendList*)malloc(sizeof(ExtendList)); //FIXME malloc
	// We don't have to malloc() the structure itself here
	lst->dispLength = 1;
	lst->curLength = 1;
	lst->list = (int*)malloc(sizeof(int));
	*(lst->list) = val;
	return lst;
}

void el_clean(ExtendList* lst){
	free(lst->list);
	free(lst); //FIXME according to el_create() modifications
}

void el_push_back(ExtendList* lst, int val){
	if (lst->curLength = lst->dispLength){ // FIXME = -> ==
		int* lstAux = lst->list;
		lst->list = (int*)malloc(sizeof(int)*(lst->curLength)*2);
		int i; // FIXME (nearly) style only, but prefer for(int i=0; ... ; ...)
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
		int i; //FIXME idem push_back
		for(i = 0 ; i < (lst->curLength) - 1 ; i++)
			(lst->list)[i] = (lstAux)[i];
		free(lstAux);
		lst->dispLength /= 2;
	}
	lst->curLength--;
}

int el_get(ExtendList* lst, int rank){
	int res = (lst->list)[rank]; //FIXME allocating memory costs time :)
	// Return it directly (eg. return (a+b))
	return res;
}

int el_size(ExtendList* lst){
	int res = lst->curLength; //FIXME
	return res;
}


