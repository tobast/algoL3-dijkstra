
/******************************************************************************
 * Algorithmic project (l3) - Dijkstra algorithm using Fibonacci heap
 ******************************************************************************
 * Théophile Bastian <contact@tobast.fr>, Noémie Cartier
 ******************************************************************************
 * File: tree.c
 * Implements a tree of TreeNodes
 *****************************************************************************/

#include "tree.h"

Tree* tr_create(TreeNode val) {
	Tree* tr = malloc(sizeof(Tree));
	tr->child = NULL;
	tr->sibling = NULL;
	tr->subtreeSize = 0;
	tr->val = val;
	return tr;
}

void tr_clean(Tree* node) {
	if(node == NULL)
		return;
	tr_clean(node->sibling);
	tr_clean(node->child);
	tr_cleanSingle(node);
}

void tr_cleanSingle(Tree* node) {
	if(node == NULL)
		return;
	free(node);
}

void tr_addChild(Tree* node, Tree* subNode) {
	subNode->sibling = node->child;
	node->child = subNode;
	node->subtreeSize += subNode->subtreeSize;
}

Tree* tr_merge(Tree* tr1, Tree* tr2) {
	if(tr1->val.weight < tr2->val.weight) {
		tr_addChild(tr1, tr2);
		return tr1;
	}
	tr_addChild(tr2, tr1);
	return tr2;
}

