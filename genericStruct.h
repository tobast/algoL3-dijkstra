
/******************************************************************************
 * Algorithmic project (l3) - Dijkstra algorithm using Fibonacci heap
 ******************************************************************************
 * Théophile Bastian <contact@tobast.fr>, Noémie Cartier
 ******************************************************************************
 * File: genericStruct.h
 * Defines some data structures without functions working on it.
 *****************************************************************************/

#ifndef DEF_GENERICSTRUCT
#define DEF_GENERICSTRUCT

#define false	0 // Yes, I like C++.
#define true	1

typedef struct TreeNode {
	int weight;
	int graphNode;
} TreeNode; 

#endif//DEF_GENERICSTRUCT
