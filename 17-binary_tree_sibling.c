#include "binary_trees.h"

/**
 * binary_tree_sibling - A function that finds the sibling of a node
 *
 * @node: A pointer to the node to find the sibling
 *
 * Return: NULL if no sibling, otherwise, the sibling
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node == node->parent->left && node->parent->right)
		return (node->parent->right);

	if (node == node->parent->right && node->parent->left)
		return (node->parent->left);

	return (NULL);
}
