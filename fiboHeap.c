
/******************************************************************************
 * Algorithmic project (l3) - Dijkstra algorithm using Fibonacci heap
 ******************************************************************************
 * Théophile Bastian <contact@tobast.fr>, Noémie Cartier
 ******************************************************************************
 * File: fiboHeap.c
 * Implements a fibonaccci heap
 *****************************************************************************/

#include "fiboHeap.h"

FiboHeap fh_create(TreeNode initialVal) {
	FiboHeap fh;
	fh.trees = ll_create(tr_create(initialVal));
}

void fh_clean(FiboHeap* fh) {
	ll_clean(fh->trees);
}

TreeNode fh_getMin(FiboHeap* fh) {
	return fh->trees->val->val;
}

TreeNode fh_extractMin(FiboHeap* fh) {
	Tree* prevMin = fh->trees;
	TreeNode out = prevMin->val->val;
	Tree* child = prevMin->val->child;
	while(child != NULL) {
		Tree* next = child->sibling;
		child->sibling = NULL; // child is now a root
		ll_insert_next(prevMin, child);
		child = next;
	}

	fh->trees = prevMin->prev;
	ll_delete_next(fh->trees);

	// Now the list does not contain the minimum anymore, but contains all its
	// children as new roots.

	// TODO rearrange tree

	return out;
}

void fh_insert(FiboHeap* fh, TreeNode nVal) {
	ll_insert_next(fh->trees, tr_create(nVal));
	if(nVal.weight < fh->trees->val->val->weight)
		fh->trees = fh->trees->next;
}

