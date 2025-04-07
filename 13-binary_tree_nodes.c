#include "binary_trees.h"

/**
 * binary_tree_nodes - A function that count the nodes with at least 1 child
 *
 * @tree: A pointer to the root node
 *
 * Return: The number of nodes or 0 if tree is NULL
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL || tree->right != NULL)
	{
		left = binary_tree_nodes(tree->left);
		right = binary_tree_nodes(tree->right);
		return (1 + left + right);
	}

	return (0);
}
