
/******************************************************************************
 * Algorithmic project (l3) - Dijkstra algorithm using Fibonacci heap
 ******************************************************************************
 * Théophile Bastian <contact@tobast.fr>, Noémie Cartier
 ******************************************************************************
 * File: fiboHeap.c
 * Implements a fibonaccci heap
 *****************************************************************************/

#include "fiboHeap.h"

FiboHeap fh_create() {
	FiboHeap fh;
	fh.trees = NULL;
	fh.totElem = 0;
	return fh;
}

void fh_clean(FiboHeap* fh) {
	ll_clean(fh->trees);
}

TreeNode fh_getMin(FiboHeap* fh) {
	return fh->trees->val->val;
}

TreeNode fh_extractMin(FiboHeap* fh) {
	if(fh->trees == NULL) // empty heap
		assert(0);
	
	LinkedList* prevMin = fh->trees;
	TreeNode out = prevMin->val->val;
	Tree* child = prevMin->val->child;
	while(child != NULL) {
		Tree* next = child->sibling;
		child->sibling = NULL; // child is now a root
		prevMin = ll_insert_next(prevMin, child);
		child = next;
	}

	fh->trees = prevMin->prev;
	fh->trees = ll_delete_next(fh->trees);

	// Now the list does not contain the minimum anymore, but contains all its
	// children as new roots.

	// According to Introduction to algorithms, D(n) <= ln(n)
	LinkedList* elemOfDegree =
		(LinkedList*) calloc((int)log(fh->totElem)+1, sizeof(LinkedList*));

	elemOfDegree[fh->trees->val.subtreeSize] = fh->trees;
	for(LinkedList* it=fh->trees->next; it != fh->trees; it = it->next) {
		int degr = it->val.subtreeSize;
		if(elemOfDegree[degr] != NULL) {
			Tree* nTree = tr_merge(elemOfDegree[degr]->val, it->val);
			//TODO
		}
		else
			elemOfDegree[degr] = it;
	}

	(fh->totElem)--;

	return out;
}

void fh_insert(FiboHeap* fh, TreeNode nVal) {
	(fh->totElem)++;
	fh->trees = ll_insert_next(fh->trees, tr_create(nVal));
	if(nVal.weight < fh->trees->val->val.weight)
		fh->trees = fh->trees->next;
}

