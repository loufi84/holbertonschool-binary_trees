#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_postorder - A function that goes thtough a binary tree
 *							using post-order traversal
 *
 * @tree: A pointer to the root of the tree
 * @func: A pointer to a function to call for each node
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
