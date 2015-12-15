
/******************************************************************************
 * Algorithmic project (l3) - Dijkstra algorithm using Fibonacci heap
 ******************************************************************************
 * Théophile Bastian <contact@tobast.fr>, Noémie Cartier
 ******************************************************************************
 * File: genericStruct.c
 * Defines constructors for the defined data structures.
 *****************************************************************************/

#include "genericStruct.h"

TreeNode makeTreeNode(int weight, int graphNode, int ancestor) {
	TreeNode t;
	t.weight = weight;
	t.graphNode = graphNode;
	t.ancestor = ancestor;
	return t;
}
int makeTreeNode_bound(int UNUSED(a),int UNUSED(b),int UNUSED(c)) {
	return 4;
}

