
/******************************************************************************
 * Algorithmic project (l3) - Dijkstra algorithm using Fibonacci heap
 ******************************************************************************
 * Théophile Bastian <contact@tobast.fr>, Noémie Cartier
 ******************************************************************************
 * File: tree.c
 * Implements a tree of TreeNodes
 *****************************************************************************/

#include "tree.h"

void tr_addChild(Tree* node, Tree* subNode) {
	subNode->sibling = node->child;
	node->child = subNode;
}

Tree* tr_merge(Tree* tr1, Tree* tr2) {
	if(tr1->val.weight < tr2->val.weight) {
		tr_addChild(tr1, tr2);
		return tr1;
	}
	tr_addChild(tr2, tr1);
	return tr2;
}

