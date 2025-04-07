#include "binary_trees.h"

/**
 * binary_tree_depth - A function that measures the depth of a node in a b tree
 *
 * @tree: A pointer tothe node to measure the depth
 *
 * Return: The depth or 0 if NULL
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL || tree->parent == NULL)
		return (0);
	else
		return (1 + binary_tree_depth(tree->parent));
}
