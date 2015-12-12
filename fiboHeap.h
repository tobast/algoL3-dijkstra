
/******************************************************************************
 * Algorithmic project (l3) - Dijkstra algorithm using Fibonacci heap
 ******************************************************************************
 * Théophile Bastian <contact@tobast.fr>, Noémie Cartier
 ******************************************************************************
 * File: fiboHeap.h
 * Implements a fibonaccci heap
 *****************************************************************************/

#include "linkedLists.h"
#include "genericStruct.h"

typedef struct FiboHeap {
	LinkedList* trees; // Pointing to the minimal element.
	// We'll maybe want to store a few more things later, so keep a structure.
} FiboHeap;

/**
 * Creates a fibonacci heap (allocates memory, ...) with the given initial
 * element. (The way the structure is made doesn't allow empty fibonacci heaps)
 **/
FiboHeap fh_create(TreeNode initialVal);

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

