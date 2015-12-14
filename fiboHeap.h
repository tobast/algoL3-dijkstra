
/******************************************************************************
 * Algorithmic project (l3) - Dijkstra algorithm using Fibonacci heap
 ******************************************************************************
 * Théophile Bastian <contact@tobast.fr>, Noémie Cartier
 ******************************************************************************
 * File: fiboHeap.h
 * Implements a fibonaccci heap
 *****************************************************************************/

#ifndef DEF_FIBOHEAP
#define DEF_FIBOHEAP

#include "linkedLists.h"
#include "genericStruct.h"

typedef struct FiboHeap {
	LinkedList* trees; // Pointing to the minimal element.
	int totElem;
} FiboHeap;

/**
 * Creates a new empty fibonacci heap.
 **/
FiboHeap fh_create();

/**
 * Deallocates all the allocated memory.
 **/
void fh_clean(FiboHeap* fh);

/**
 * Gets the minimal value from the given fibonacci heap. Read-only.
 **/
TreeNode fh_getMin(FiboHeap* fh);

/**
 * Deletes the minimal value from the given fibonacci heap and returns it.
 **/
TreeNode fh_extractMin(FiboHeap* fh);

/**
 * Adds a new value to the given fibonacci heap.
 **/
void fh_insert(FiboHeap* fh, TreeNode nVal);

#endif//DEF_FIBOHEAP
