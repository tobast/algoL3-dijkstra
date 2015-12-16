
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
	tr->subtreeSize = 1;
	tr->val = val;
	return tr;
}
int tr_create_bound(TreeNode UNUSED(val)) {
	return 6;
}

void tr_clean(Tree* node) {
	if(node == NULL)
		return;
	tr_clean(node->sibling);
	tr_clean(node->child);
	tr_cleanSingle(node);
}
int tr_clean_bound(Tree* node) {
	return tr_clean_bound(node->sibling) +
		tr_clean_bound(node->child) +
		tr_cleanSingle_bound(node);
}

void tr_cleanSingle(Tree* node) {
	if(node == NULL)
		return;
	free(node);
}
int tr_cleanSingle_bound(Tree* UNUSED(node)) {
	return 1;
}

void tr_addChild(Tree* node, Tree* subNode) {
	subNode->sibling = node->child;
	node->child = subNode;
	node->subtreeSize += subNode->subtreeSize;
}
int tr_addChild_bound(Tree* UNUSED(node), Tree* UNUSED(subNode)) {
	return 3;
}

Tree* tr_merge(Tree* tr1, Tree* tr2) {
	assert(tr1->subtreeSize == tr2->subtreeSize);
	if(tr1->val.weight < tr2->val.weight) {
		tr_addChild(tr1, tr2);
		return tr1;
	}
	tr_addChild(tr2, tr1);
	return tr2;
}
int tr_merge_bound(Tree* UNUSED(tr1), Tree* UNUSED(tr2)) {
	return tr_addChild_bound(NULL, NULL) + 1;
}

