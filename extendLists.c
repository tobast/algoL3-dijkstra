
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
int el_create_bound(int UNUSED(len)) {
	return 1;
}

void el_clean(ExtendList* lst){
	free(lst->list);
}
int el_clean_bound(ExtendList* UNUSED(lst)) {
	return 1;
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
int el_push_back_bound(ExtendList* lst, int UNUSED(val)) {
	if(lst->curLength == lst->availLength)
		return lst->curLength;
	return 1;
}
int el_push_back_bound_amz(ExtendList* UNUSED(lst), int UNUSED(val)) {
	return 2; //amortized
}

void el_pop_back(ExtendList* lst){
	if(lst->curLength == 0) // trying to pop from an empty list
		assert("Empty list: can't pop" == 0);
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
int el_pop_back_bound(ExtendList* lst) {
	if(lst->curLength < lst->availLength / 4)
		return lst->curLength;
	return 1;
}

int el_get(ExtendList* lst, int rank){
	return (lst->list)[rank];
}
int el_get_bound(ExtendList* UNUSED(lst), int UNUSED(rank)) {
	return 1;
}

int el_size(ExtendList* lst){
	return lst->curLength;
}
int el_size_bound(ExtendList* UNUSED(lst)) {
	return 1;
}


