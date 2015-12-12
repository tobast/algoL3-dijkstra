
/******************************************************************************
 * Algorithmic project (l3) - Dijkstra algorithm using Fibonacci heap
 ******************************************************************************
 * Théophile Bastian <contact@tobast.fr>, Noémie Cartier
 ******************************************************************************
 * File: genericStruct.c
 * Defines constructors for the defined data structures.
 *****************************************************************************/

TreeNode makeTreeNode(int weight, int graphNode) {
	TreeNode t;
	t.weight = weight;
	t.graphNode = graphNode;
	return t;
}

