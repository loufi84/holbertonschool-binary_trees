#include "binary_trees.h"

/**
 * binary_tree_leaves - A function that counts the number of leaves in a b tree
 *
 * @tree: A pointer to the node of the tree to count from
 *
 * Return: The number of leaves or 0 if tree is NULL
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	return (binary_tree_leaves(tree->left) + (binary_tree_leaves(tree->right)));
}
