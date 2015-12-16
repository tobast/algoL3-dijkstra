
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
int intlog2_bound(int x) {
	return intlog2(x);
}
int intlog2_bound_bound(int x) {
	return intlog2_bound(x);
}
int intlog2_bound_bound_bound(int x) {
	return intlog2_bound_bound(x);
}
/*
And by induction, for all n in N, intlog2_bound_..._bound (n times) =
	intlog2_bound_..._bound (n-1 times)
*/

int fh_create_bound() {
	return 1;
}

FiboHeap fh_create() {
	FiboHeap fh;
	fh.trees = NULL;
	fh.totElem = 0;
	return fh;
}

int fh_clean_bound(FiboHeap* fh) {
	return ll_clean_bound(fh->trees);
}
void fh_clean(FiboHeap* fh) {
	ll_clean(fh->trees);
}

int fh_getMin_bound(FiboHeap* UNUSED(fh)) {
	return 1;
}
TreeNode fh_getMin(FiboHeap* fh) {
	assert(fh->trees != NULL);
	return fh->trees->val->val;
}

int fh_extractMin_bound(FiboHeap* fh) {
	if(fh->trees == NULL)
		return 1;
	
	int nbChildren=0;
	Tree* child=fh->trees->val->child;
	while(child != NULL) {
		nbChildren++;
		child = child->sibling;
	}

	int nbRoots = 0;
	LinkedList* elem = fh->trees;
	do {
		nbRoots++;
		elem = elem->next;
	} while(elem != fh->trees);
	nbRoots += nbChildren - 1; // The min is deleted, its childs are rooted

	return nbChildren * ll_insert_next_bound(NULL, NULL) +
		tr_cleanSingle_bound(NULL) +
		ll_delete_next_bound(NULL) +
		(2*intlog2(fh->totElem)+1)*sizeof(LinkedList*) +
		nbRoots * (ll_delete_next_bound(NULL)*2 +
			ll_insert_next_bound(NULL,NULL) +
			tr_merge_bound(NULL,NULL)
			) +
		intlog2(fh->totElem - 1);
}
TreeNode fh_extractMin(FiboHeap* fh) {
	assert(fh->trees != NULL);
	
	LinkedList* prevMin = fh->trees;
	TreeNode out = prevMin->val->val;
	Tree* child = prevMin->val->child;
	while(child != NULL) {
		Tree* next = child->sibling;
		child->sibling = NULL; // child is now a root
		prevMin = ll_insert_next(prevMin, child);
		child = next;
	}

	tr_cleanSingle(prevMin->val);
	fh->trees = prevMin->prev;
	fh->trees = ll_delete_next(fh->trees);

	if(fh->trees == NULL) // The list is now empty
		return out;

	// Now the list does not contain the minimum anymore, but contains all its
	// children as new roots.

	// According to Introduction to algorithms, D(n) <= ln(n). Let's take a
	// bit more.
	LinkedList** elemOfDegree =
		(LinkedList**) calloc(2 * intlog2(fh->totElem) + 1,
			sizeof(LinkedList*));

	/* To ensure that the iteration goes all around the circular linked list,
	 even when we mess a bit around with its contents while iterating,
	 we add a dummy element which will be a "beginning of list marker",
	 and we delete it after.
	*/
	ll_insert_next(fh->trees, tr_create(makeTreeNode(-1,-1,-1))); // DUMMY
	fh->trees = fh->trees->next; // Now points to the dummy elem.
	for(LinkedList* it=fh->trees->next; it != fh->trees; it = it->next) {
		int degr = it->val->subtreeSize;
		int ldegr = intlog2(degr); // The elemOfDegree list is of log size,
			// thus we need to take the logarithm of the degree.
		if(elemOfDegree[ldegr] != NULL) {
			Tree* nTree = tr_merge(elemOfDegree[ldegr]->val, it->val);
			// CORRECT because we have at least 2 elements.
			ll_delete_next(elemOfDegree[ldegr]->prev);
			elemOfDegree[ldegr] = NULL;
			it = it->prev;
			it = ll_delete_next(it);
			it = ll_insert_next(it, nTree);
		}
		else
			elemOfDegree[ldegr] = it;
	}
	fh->trees = fh->trees->prev;
	fh->trees = ll_delete_next(fh->trees); // Delete dummy

	free(elemOfDegree);

	(fh->totElem)--;

	// Now finds the minimum element
	LinkedList* curMin = fh->trees;
	for(LinkedList* it=fh->trees->next; it != fh->trees; it = it->next)
		if(it->val->val.weight < curMin->val->val.weight)
			curMin = it;
	fh->trees = curMin;

	return out;
}

int fh_insert_bound(FiboHeap* UNUSED(fh), TreeNode UNUSED(nVal)) {
	return (1 + ll_insert_next_bound(NULL, NULL));
}
void fh_insert(FiboHeap* fh, TreeNode nVal) {
	(fh->totElem)++;
	fh->trees = ll_insert_next(fh->trees, tr_create(nVal));
	if(nVal.weight < fh->trees->val->val.weight)
		fh->trees = fh->trees->next;
}

