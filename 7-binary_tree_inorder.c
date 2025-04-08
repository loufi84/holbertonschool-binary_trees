#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_inorder - A function that goes through a binary tree
 *							in-order traversal
 *
 * @tree: A pointer to the root of the tree
 * @func: A pointer to the function to call for each node
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
