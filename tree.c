
/******************************************************************************
 * Algorithmic project (l3) - Dijkstra algorithm using Fibonacci heap
 ******************************************************************************
 * Théophile Bastian <contact@tobast.fr>, Noémie Cartier
 ******************************************************************************
 * File: tree.c
 * Implements a tree of TreeNodes
 *****************************************************************************/

#include "tree.c"

void tr_addChild(Tree* node, Tree* subNode) {
	subNode->sibling = node->child;
	node->child = subNode;
}

Tree* tr_merge(Tree* tr1, Tree* tr2) {
	//TODO implement
}
