
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

#ifdef __GNUC__
#  define UNUSED(x) UNUSED_ ## x __attribute__((__unused__))
#else
#  define UNUSED(x) UNUSED_ ## x
#endif

#define false	0 // Yes, I like C++.
#define true	1

typedef struct TreeNode {
	int weight;
	int graphNode;
	int ancestor;
} TreeNode; 

typedef struct Arguments {
	short useNaiveDijkstra;
} Arguments;

TreeNode makeTreeNode(int weight, int graphNode, int ancestor);
int makeTreeNode_bound(int, int, int);

#endif//DEF_GENERICSTRUCT
