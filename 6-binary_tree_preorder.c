#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_preorder - A function to goes throug a binary tree using
 *							pre-order traversal
 *
 * @tree: A pointer to the root of the tree
 * @func: A poiter to a function call for each node
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	printf("%d\n", tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
