
/******************************************************************************
 * Algorithmic project (l3) - Dijkstra algorithm using Fibonacci heap
 ******************************************************************************
 * Théophile Bastian <contact@tobast.fr>, Noémie Cartier
 ******************************************************************************
 * File: tree.h
 * Implements a tree of TreeNodes
 *****************************************************************************/

#include "genericStruct.h"

typedef struct Tree {
	struct Tree* child;
	struct Tree* sibling;
	int subtreeSize;
	TreeNode val;
} Tree;

/**
 * Adds subNode as the first child of node, and its previous child as the
 * sibling of subNode.
 * WARNING! The siblings of subNode are lost in the process!
 **/
void tr_addChild(Tree* node, Tree* subNode);

/**
 * Adds tr1 as a child of tr2, or the other way, so that the output tree is
 * still a minimum priority queue.
 * @return the new root.
 **/
Tree* tr_merge(Tree* tr1, Tree* tr2);