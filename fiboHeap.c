
/******************************************************************************
 * Algorithmic project (l3) - Dijkstra algorithm using Fibonacci heap
 ******************************************************************************
 * Théophile Bastian <contact@tobast.fr>, Noémie Cartier
 ******************************************************************************
 * File: fiboHeap.c
 * Implements a fibonaccci heap
 *****************************************************************************/

#include "fiboHeap.h"

/// Useful to fh_extractMin. I don't want to link against math.
int intlog2(int x) {
	int out=1;
	while(x > 0) {
		out++;
		x>>=1;
	}
	return out;
}

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
	LinkedList** elemOfDegree =
		(LinkedList**) calloc(2 * intlog2(fh->totElem) + 1,
			sizeof(LinkedList*));

	// Iterates from fh->trees->next to fh->trees INCLUSIVE
	// Keeps a valid fh->trees pointer
	elemOfDegree[fh->trees->val->subtreeSize] = fh->trees;
	for(LinkedList* it=fh->trees->next; it != fh->trees; it = it->next) {
		int degr = it->val->subtreeSize;
		short moveHead = false;
		if(elemOfDegree[degr] != NULL) {
			if(elemOfDegree[degr] == fh->trees) {
				// If we're gonna delete fh->trees->next in this operation
				if(it == fh->trees->next)
					moveHead = true;
				else
					fh->trees = fh->trees->next;
			}
			Tree* nTree = tr_merge(elemOfDegree[degr]->val, it->val);
			ll_delete_next(elemOfDegree[degr]->prev);
			elemOfDegree[degr] = NULL;
			it = it->prev;
			it = ll_delete_next(it);
			it = ll_insert_next(it, nTree);
			// fh->trees->next was deleted, the rightful head is nTree
			if(moveHead)
				fh->trees = it->next;
		}
		else
			elemOfDegree[degr] = it;
	}

	free(elemOfDegree);

	(fh->totElem)--;

	// Now finds the minimum element
	LinkedList* curMin = fh->trees;
	for(LinkedList* it=fh->trees->next; it != fh->trees; it = it->next) {
		if(it->val->val.weight < curMin->val->val.weight)
			curMin = it;
	}
	fh->trees = curMin;

	return out;
}

void fh_insert(FiboHeap* fh, TreeNode nVal) {
	(fh->totElem)++;
	fh->trees = ll_insert_next(fh->trees, tr_create(nVal));
	if(nVal.weight < fh->trees->val->val.weight)
		fh->trees = fh->trees->next;
}

