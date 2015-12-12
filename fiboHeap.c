
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

}

TreeNode fh_extractMin(FiboHeap* fh) {

}

void fh_insert(FiboHeap* fh, TreeNode nVal) {

}

